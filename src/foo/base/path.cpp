///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   path.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   操作文件路径
//
///////////////////////////////////////////////////////////////////////////////
#include "path.h"
#include <Shlwapi.h>
#include <algorithm>
#include <vector>


void FooBase::Path::CleanQuotation(std::wstring& Path) {
    Path.erase(std::remove(Path.begin(), Path.end(), L'\"'),Path.end());
}

void FooBase::Path::ExpandToUnicode(std::wstring& Path) {
    if (0 != Path.compare(0, (sizeof(L"\\\\?\\") - 1) / sizeof(wchar_t), L"\\\\?\\"))
        Path = L"\\\\?\\" + Path;
}

std::wstring FooBase::Path::FindExtension(const std::wstring& Path) {
    return ::PathFindExtensionW(Path.c_str());
}

bool FooBase::Path::RemoveFileSpec(std::wstring& Path) {
    bool bRet                  = false;
    wchar_t TempPath[MAX_PATH] = { 0 };
    wcscpy_s(TempPath, Path.c_str());   
    bRet = ::PathRemoveFileSpecW(TempPath) ? true : false;
    Path = TempPath;
    return bRet;
}

bool FooBase::Path::RemoveFileSpec(std::string& Path) {
    bool bRet               = false;
    char TempPath[MAX_PATH] = { 0 };
    strcpy_s(TempPath, Path.c_str());
    bRet = ::PathRemoveFileSpecA(TempPath) ? true : false;
    Path = TempPath;
    return bRet;
}

std::string FooBase::Path::GetFileName(const std::string& Path) {
    std::vector<char> Temp(Path.begin(), Path.end());
    return std::string(::PathFindFileNameA(Temp.data()));
}

std::string FooBase::Path::RemoveExtension(const std::string& Path) {
    char TempPath[MAX_PATH] = { 0 };
    strcpy_s(TempPath, Path.c_str());
    PathRemoveExtensionA(TempPath);
    return std::string(TempPath);
}

bool FooBase::Path::Append(std::wstring& Path, const std::wstring& More) {
    bool bRet                  = false;
    wchar_t TempPath[MAX_PATH] = { 0 };
    wcscpy_s(TempPath, Path.c_str());
    bRet = ::PathAppendW(TempPath, More.c_str()) ? true : false;
    Path = TempPath;
    return bRet;
}

bool FooBase::Path::Append(std::string& Path, const std::string& More) {
    bool bRet               = false;
    char TempPath[MAX_PATH] = { 0 };
    strcpy_s(TempPath, Path.c_str());
    bRet = ::PathAppendA(TempPath, More.c_str()) ? true : false;
    Path = TempPath;
    return bRet;
}

bool FooBase::Path::GetModulePath(std::wstring& Path) {
    wchar_t TempPath[MAX_PATH] = { 0 };
    if (::GetModuleFileName(NULL, TempPath, MAX_PATH) != 0) {
        Path = TempPath;
        return true;
    }
    else {
        return false;
    }
}

bool FooBase::Path::GetWindowsPath(std::wstring& Path) {
    wchar_t TempPath[MAX_PATH] = { 0 };
    if (::GetWindowsDirectoryW(TempPath, MAX_PATH) != 0) {
        Path = TempPath;
        return true;
    }
    else {
        return false;
    }
}

bool FooBase::Path::GetSystemPath(std::wstring& Path) {
    wchar_t TempPath[MAX_PATH] = { 0 };
    if (::GetSystemDirectoryW(TempPath, MAX_PATH) != 0) {
        Path = TempPath;
        return true;
    }
    else {
        return false;
    }
}

bool FooBase::Path::IsPathExists(const std::wstring& Path) {
    return ::PathFileExistsW(Path.c_str()) ? true : false;
}

bool FooBase::Path::IsPathExists(const std::string& Path) {
    return ::PathFileExistsA(Path.c_str()) ? true : false;
}

bool FooBase::Path::IsPathDirectory(const std::wstring& Path) {
    return ::PathIsDirectoryW(Path.c_str()) ? true : false;
}

bool FooBase::Path::IsPathDirectory(const std::string& Path) {
    return ::PathIsDirectoryA(Path.c_str()) ? true : false;
}

bool FooBase::Path::GetCurDirectory(std::string& Path) {
    char TempPath[MAX_PATH] = { 0 };
    ::GetCurrentDirectoryA(MAX_PATH, TempPath);
    Path = TempPath;
    return true;
}

bool FooBase::Path::GetCurDirectory(std::wstring& Path) {
    wchar_t TempPath[MAX_PATH] = { 0 };
    ::GetCurrentDirectoryW(MAX_PATH, TempPath);
    Path = TempPath;
    return true;
}

bool FooBase::Path::SetCurDirectory(const std::string& Path) {
    ::SetCurrentDirectoryA(Path.c_str());
    return true;
}

bool FooBase::Path::SetCurDirectory(const std::wstring& Path) {
    ::SetCurrentDirectoryW(Path.c_str());
    return true;
}