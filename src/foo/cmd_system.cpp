///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   func_system.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   命令行系统的实现，即整个模块的封装，保存并控制着各个子管理模块
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <vector>

#include <sstream>
#include <fstream>

#include "base\path.h"
#include "cmd_system.h"
#include "base\char_set.h"

using namespace FooScript;

FooCmdSystem::FooCmdSystem(
    FooBase::Log::LogOStream& SysLogOStream,
    FooBase::Log::LogOStream& UserLogOStream) :
    engine_root_directory([]()->std::string {
        std::wstring TempPath;
        FooBase::Path::GetModulePath(TempPath);
        FooBase::Path::RemoveFileSpec(TempPath);
        return FooBase::CharSet::ws2s(TempPath);
        }()),
    lm(SysLogOStream,UserLogOStream),
    foo_parser(*this),
    debug_parser(*this, foo_parser) {
    is_stop = false;
    is_in_foo = false;
    is_in_foo_block = false;
    InitGlobalValues();
}

FooCmdSystem::~FooCmdSystem() {
}

void FooCmdSystem::Start() {
    LOG_HELP() << "Enter h(Help) for help." << FooBase::Log::FooLogEnd;
    while (!is_stop) {
        CommandLoop();
    }
}

void FooCmdSystem::Start(int argc, _TCHAR* argv[]) {
    std::wstring TempPathW = argv[1];
    std::string TempPath = FooBase::CharSet::ws2s(TempPathW);
    start_module_path = TempPath;
    FooBase::Path::RemoveFileSpec(TempPath);
    work_root_directory = TempPath;
    // push the work_root_directory into module_root_directory_list as
    // the primary module search direcotry
    module_root_directory_list.push_back(work_root_directory);

    //foo_parser.Execute(start_module_path, argc - 1, &argv[1]);
}

void FooCmdSystem::Start(const std::wstring& ModulePath) {
    std::ifstream    ifs;
    ifs.open(ModulePath);
    if (!ifs.is_open()) {
        LOG_ERROR() << ModulePath << " open failed." << FooBase::Log::FooLogEnd;
        return;
    }
    std::string s((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    EnterFooMode();
    Run(s);
    ExitFooMode();
    ifs.close();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& FooCmdSystem::LOG_NONE() {
    return lm.LOG_NONE();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& FooCmdSystem::LOG_DEBUG() {
    return lm.LOG_DEBUG();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& FooCmdSystem::LOG_INFO() {
    return lm.LOG_INFO();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& FooCmdSystem::LOG_WARNING() {
    return lm.LOG_WARNING();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& FooCmdSystem::LOG_ERROR() {
    return lm.LOG_ERROR();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_SOFT>& FooCmdSystem::LOG_HELP() {
    return lm.LOG_HELP();
}

FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_SOFT>& FooCmdSystem::LOG_DATA() {
    return lm.LOG_DATA();
}

void FooCmdSystem::RedirectUserLog(FooBase::Log::LogOStream& o) {
    lm.RedirectUserLog(o);
}

void FooCmdSystem::RestoreUserLog() {
    lm.RestoreUserLog();
}

void FooCmdSystem::ResetParser() {
    foo_parser.Reset();
}

std::string FooCmdSystem::GetEngineSubModulePath(const std::string& ModuleName) const {
    return engine_root_directory + '\\' + ModuleName;
}

std::wstring FooCmdSystem::GetEngineSubModulePath(const std::wstring& ModuleName) const {
    return FooBase::CharSet::s2ws(
        GetEngineSubModulePath(FooBase::CharSet::ws2s(ModuleName)));
}

std::string FooCmdSystem::GetEngineSubModulePath(
    const std::string& SubDirectory,
    const std::string& ModuleName) const {
    return engine_root_directory + '\\' + SubDirectory + '\\' + ModuleName;
}

std::wstring FooCmdSystem::GetEngineSubModulePath(
    const std::wstring& SubDirectory,
    const std::wstring& ModuleName) const {
    return FooBase::CharSet::s2ws(
        GetEngineSubModulePath(
        FooBase::CharSet::ws2s(SubDirectory), 
        FooBase::CharSet::ws2s(ModuleName)));
}

std::string FooCmdSystem::GetModuleAbsPathFromRel(const tCmdString& RelativePath) const {
    std::string AbsolutePath;
    for (auto module_root : module_root_directory_list) {
        AbsolutePath = module_root;
        FooBase::Path::Append(AbsolutePath, RelativePath);
        // it's a directory
        if (FooBase::Path::IsPathDirectory(AbsolutePath) &&
            FooBase::Path::IsPathExists(AbsolutePath)) {
            return AbsolutePath + "\\" + FOO_MODULE_ROOT;
        }
        // it's a file
        AbsolutePath += FOO_MODULE_POSTFIX;
        if (!FooBase::Path::IsPathDirectory(AbsolutePath) &&
            FooBase::Path::IsPathExists(AbsolutePath)
            ) {
            return AbsolutePath;
        }
    }
    return std::string();
}

std::string FooCmdSystem::GetModuleRelPathFromModule(const tCmdString& ModulePath) const {
    tCmdString TempPath = ModulePath;
    std::replace_if(TempPath.begin(), TempPath.end(), [](char a){ return a == '.' ? true : false; }, '\\');
    return TempPath;
}

void FooCmdSystem::InitGlobalValues() {
}

// protected
void FooCmdSystem::CommandLoop() {
    tCmdString        CmdString;
    bool            IsExitFooBlock = false;

    if (is_in_foo_block) {
        LOG_HELP() << "Enter code block. Stop with \"!\"."
            << FooBase::Log::FooLogEnd;
        LOG_HELP() << FooBase::Log::blue;
        std::string Line;
        while (true) {
            std::getline(std::cin, Line);
            if (Line == "!")
                break;
            CmdString += Line;
        }
        IsExitFooBlock = true;
    }
    else {
        if (!IsRunInFooMode())
            LOG_HELP() << FooBase::Log::white << FooBase::Log::FooLogCmdPre;
        else
            LOG_HELP() << FooBase::Log::blue << FooBase::Log::FooLogCmdPre;
        std::getline(std::cin, CmdString);
    }
    try{
        Run(CmdString);
    }
    catch (std::runtime_error& e) {
        LOG_ERROR() << e.what() << FooBase::Log::FooLogEnd;
    }
    catch (std::bad_alloc&) {
        LOG_ERROR() << "内存不足" << FooBase::Log::FooLogEnd;
    }
    catch (std::exception& e) {
        LOG_ERROR() << "其化类型异常:" << e.what() << FooBase::Log::FooLogEnd;
    }
    if (IsExitFooBlock) {
        ExitFooBlockMode();
    }
}

void FooCmdSystem::Run(const tCmdString& CmdString) {
    if (!IsRunInFooMode())
        debug_parser.Execute(CmdString);
    else
        foo_parser.Execute(CmdString);
}