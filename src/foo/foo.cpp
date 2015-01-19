///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   foo.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   main start
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <thread>
#include <locale>
#include <string>

#include "base\path.h"
#include "base\char_set.h"
#include "cmd_system.h"

class no_comma_numpunct :public std::numpunct<wchar_t> {
    wchar_t do_thousands_sep() const { 
        return ' '; 
    }
    std::string do_grouping() const { 
        return ""; 
    }
};

class StdCoutLogStream : public FooBase::Log::LogOStream{
public:
    StdCoutLogStream(std::ostream& O) : FooBase::Log::LogOStream(O) {}
    virtual StdCoutLogStream& operator<<(const char* v) override { 
        FooBase::Log::LogOStream::operator<<(FooBase::CharSet::utf82string(v));
        return *this; 
    }
    virtual StdCoutLogStream& operator<<(const std::string& v) override { 
        FooBase::Log::LogOStream::operator<<(FooBase::CharSet::utf82string(v));
        return *this; 
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    std::wstring    TempFile;
    FooBase::Path::GetModulePath(TempFile);
    FooBase::Path::RemoveFileSpec(TempFile);
    FooBase::Path::SetCurDirectory(TempFile);
    std::locale        loc(std::cout.getloc(), new no_comma_numpunct);
    std::ofstream    ofs;
    ofs.open(L"./log.txt", std::wofstream::app);

    std::wstring    TargetPath;
    std::wstring    ServiceName;
    if (!ofs.is_open())
        return 0;
    std::cout.imbue(loc);
    ofs.imbue(loc);

    StdCoutLogStream& Cout = StdCoutLogStream(std::cout);
    {
        try {
            std::shared_ptr<FooScript::FooCmdSystem> cs = std::shared_ptr<FooScript::FooCmdSystem>(new FooScript::FooCmdSystem(
                FooBase::Log::LogOStream(ofs),
                Cout));
            if (argc <= 1) {
                cs->Start();
            }
            else {
                cs->Start(argc, argv);
            }
        }
        catch (std::exception& e) {
            Cout << " " << e.what();
            FooBase::Log::LogOStream(std::cout) << std::endl;
        }
        catch (...) {
        }
    }
    ofs.close();
    getchar();
    return 0;
}