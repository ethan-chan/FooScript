///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   parser.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.03.24
//  Comment     :   语法解析器
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <regex>
#include <sstream>
#include <cctype>
#include <fstream>

#include "cmd_system.h"
#include "reg_parser.h"

#include "base\path.h"
#include "foo_driver.h"

using namespace FooBase;
using namespace FooScript;
using Parser::RegParser;
using Parser::FooDriver;

#define P_OR            "|"
#define P_EXISTS        "+" // must exist.
#define P_ANY            "*" // any number
#define P_OPT            "?"    // optional 0 or 1
#define P_VALUE(s)        "(" s ")"
#define P_SPACE_A        "[ \\t]" P_ANY        
#define P_SPACE_E        "[ \\t]" P_EXISTS        
#define P_PRINT_E        "[[:print:]]" P_EXISTS    // Print char must exist.
#define P_TOKEN            "[\\w.!]" P_EXISTS
#define P_TOKEN_V        P_VALUE(P_TOKEN)
#define P_P_GROUP(s)    "(?:" s ")"    // Passive group

#define P_CALL_ARGS        "[\\w.=,]" P_ANY

#define P_MACRO_START       "#"

#define SYM_CLASS_END        '#'
#define SYM_CLASS_STATIC    '$'
#define SYM_CLASS_MEMBER    '.'
#define SYM_MACRO_START     '#'

RegParser::TestNode TestCases[] = {
    { L"expression", L"1.foo", L"" },
    { L"print", L"1.foo", L"" },
    { L"class", L"1.foo", L""},
    { L"closure", L"1.foo", L"" },
};

RegParser::RegParser(FooCmdSystem& Fcs, FooDriver& Fd) :
    fcs(Fcs),
    fd(Fd) {
    RegisterFunction(key_start_foo, std::bind(&RegParser::_foo, this, std::placeholders::_1));
    RegisterFunction(key_start_foo_block, std::bind(&RegParser::_foo_block, this, std::placeholders::_1));
    RegisterFunction(key_lv, std::bind(&RegParser::_list_value, this, std::placeholders::_1));
    RegisterFunction(key_ls, std::bind(&RegParser::_list_stream, this, std::placeholders::_1));
    RegisterFunction(key_lm, std::bind(&RegParser::_list_member, this, std::placeholders::_1));
    RegisterFunction(key_p, std::bind(&RegParser::_step_over, this, std::placeholders::_1));
    RegisterFunction(key_t, std::bind(&RegParser::_step_into, this, std::placeholders::_1));
    RegisterFunction(key_test, std::bind(&RegParser::_test, this, std::placeholders::_1));
}

RegParser::~RegParser() {

}

void RegParser::Execute(const tCmdString& CmdString) {
    const tCmdString* p = &CmdString;
    if (CmdString.length() == 0)
        return;

    auto it = p->begin();
    auto end = p->end();
    it = SkipSpace(it, end);

    ExecuteTokenString(it, end);
}

void RegParser::RegisterFunction(const tToken& Cmd, const HandlerType& KeyFunc) {
    khs.insert(tKeyHandler::value_type(Cmd, KeyFunc));
}

void RegParser::_foo(const tCmdString& CmdString) {
    fcs.EnterFooMode();
    std::istringstream is(CmdString);
    tToken SubToken;
    is >> SubToken;
    if ("m" == SubToken) {
        fd.EnterMutualMode();
    }
}

void RegParser::_foo_block(const tCmdString& CmdString) {
    fcs.EnterFooBlockMode();
    std::istringstream is(CmdString);
    tToken SubToken;
    is >> SubToken;
    if ("m" == SubToken) {
        fd.EnterMutualMode();
    }
}

void RegParser::_list_value(const tCmdString& CmdString) {

}

void RegParser::_list_stream(const tCmdString& CmdString) {
    fd.ListStream();
}

void RegParser::_list_member(const tCmdString& CmdString) {

}

void RegParser::_step_over(const tCmdString& CmdString) {
    fd.DebugExecuteByStepInto();
}

void RegParser::_step_into(const tCmdString& CmdString) {
    fd.DebugExecuteByStepInto();
}

void RegParser::_test(const tCmdString& CmdString) {
    std::wstring   _test_dir;
    FooBase::Path::GetModulePath(_test_dir);
    FooBase::Path::RemoveFileSpec(_test_dir);
    _test_dir = _test_dir.substr(0, _test_dir.rfind(L"bin"));
    FooBase::Path::Append(_test_dir, L"test");
    _test_input_dir = _test_dir;
    FooBase::Path::Append(_test_input_dir, L"input");
    _test_output_dir = _test_dir;
    FooBase::Path::Append(_test_output_dir, L"output");

    std::wstring    CaseFindDir;
    std::wstring    CaseDir;
    std::wstring    CaseFile;
    bool            IsPassed = true;
    for (auto Case : TestCases) {
        // 先清空输出目录
        auto TestOutputTypeDir = _test_output_dir;
        FooBase::Path::Append(TestOutputTypeDir, Case.type);
        CleanOutputDir(TestOutputTypeDir);

        CaseFindDir = _test_input_dir;
        FooBase::Path::Append(CaseFindDir, Case.type);
        CaseDir = CaseFindDir;
        FooBase::Path::Append(CaseFindDir, L"*.foo");
        WIN32_FIND_DATAW Data = {};
        HANDLE hFind = ::FindFirstFileW(CaseFindDir.c_str(),&Data);
        if (hFind == INVALID_HANDLE_VALUE) {
            continue;
        }
        do {
            CaseFile = CaseDir;
            FooBase::Path::Append(CaseFile, Data.cFileName);
            try {
                StartCase(CaseFile);
            }
            catch (std::exception& e) {
                fcs.RestoreUserLog();
                fcs.LOG_ERROR() << CaseFile << L": " << e.what() << FooBase::Log::FooLogEnd;
                IsPassed = false;
            }
            if (!IsPassed)
                break;
        } while (::FindNextFileW(hFind, &Data));
        if (hFind != INVALID_HANDLE_VALUE)
            ::FindClose(hFind);
        if (!IsPassed)
            break;
    }
}

void RegParser::CleanOutputDir(const std::wstring& Dir) {
    std::wstring    FindDir = Dir;
    std::wstring    FilePath;
    if (!FooBase::Path::IsPathExists(Dir.c_str())) {
        ::CreateDirectoryW(Dir.c_str(), NULL);
    }
    else {
        FooBase::Path::Append(FindDir, L"*.output");
        WIN32_FIND_DATAW Data = {};
        HANDLE hFind = ::FindFirstFileW(FindDir.c_str(), &Data);
        if (hFind == INVALID_HANDLE_VALUE) {
            return;
        }
        do {
            FilePath = Dir;
            FooBase::Path::Append(FilePath, Data.cFileName);
            ::DeleteFileW(FilePath.c_str());
        } while (::FindNextFileW(hFind, &Data));
        if (hFind != INVALID_HANDLE_VALUE)
            ::FindClose(hFind);
    }
}

void RegParser::StartCase(const std::wstring& CasePath) {
    auto CaseResultPath = _test_output_dir;
    FooBase::Path::Append(
        CaseResultPath, 
        CasePath.substr(
        _test_input_dir.length() + 1, 
        CasePath.length() - 1).c_str()
        );
    CaseResultPath  = CaseResultPath + L".output";
    auto CaseTargetPath = CasePath + L".target";

    // 打开输出文件，并接入日志引擎
    std::ofstream    ofs;
    ofs.open(CaseResultPath, std::wofstream::app);
    if (!ofs.is_open()) {
        fcs.LOG_ERROR() << CaseResultPath << " open failed." << FooBase::Log::FooLogEnd;
        return;
    }

    fcs.ResetParser();
    fcs.RedirectUserLog(FooBase::Log::LogOStream(ofs));
    fcs.Start(CasePath);
    fcs.RestoreUserLog();

    // 打开目标结果文件
    std::ifstream    ifs;
    ifs.open(CaseResultPath);
    if (!ifs.is_open()) {
        fcs.LOG_ERROR() << CaseResultPath << " open failed." << FooBase::Log::FooLogEnd;
        return;
    }
    std::string s1((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    // 打开输出文件
    ifs.open(CaseTargetPath);
    if (!ifs.is_open()) {
        fcs.LOG_ERROR() << CaseTargetPath << " open failed." << FooBase::Log::FooLogEnd;
        return;
    }
    std::string s2((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    if (s1 != s2) {
        throw std::runtime_error("Executed unsuccessfully");
    }
}

void RegParser::ExecuteTokenString(
    const tCmdString::const_iterator&    begin,
    const tCmdString::const_iterator&    end) {
    static const std::regex        Pattern(P_TOKEN_V); // Get the cmd token
    std::smatch                    Match;
    tKeyHandler::iterator        Khit;
    if (std::regex_search(begin, end, Match, Pattern, std::regex_constants::match_continuous)) {
        tToken& CmdToken = Match[1].str();
        tCmdString& Suf = Match.suffix().str();
        Khit = khs.find(CmdToken);
        if (khs.end() ==Khit) {
            fcs.LOG_ERROR() << "\"" << CmdToken << L"\" command does not exist." << Log::FooLogEnd;
            return;
        }
        // second 是一个函数指针
        Khit->second(Suf);

    }
    else {
        fcs.LOG_ERROR() << L"Failed to get the command." << Log::FooLogEnd;
    }
}

tCmdString::const_iterator RegParser::SkipSpace(
    const tCmdString::const_iterator& begin,
    const tCmdString::const_iterator& end
    ) const {
    tCmdString::const_iterator it = begin;
    while (true) {
        if (end == it) return end;
        if (std::isblank(*it)) {
            ++it;
        }
        else {
            break;
        }
    }
    return it;
}