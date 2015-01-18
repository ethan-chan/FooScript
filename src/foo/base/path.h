///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   path.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   操作文件路径
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

namespace FooBase{
    namespace Path{
        void CleanQuotation(std::wstring& Path);
        void ExpandToUnicode(std::wstring& Path);
        std::wstring FindExtension(const std::wstring& Path);
        bool RemoveFileSpec(std::wstring& Path);
        bool RemoveFileSpec(std::string& Path);
        std::string GetFileName(const std::string& Path);
        std::string RemoveExtension(const std::string& Path);
        bool Append(std::wstring& Path, const std::wstring& More);
        bool Append(std::string& Path, const std::string& More);
        bool GetModulePath(std::wstring& Path);
        bool GetWindowsPath(std::wstring& Path);
        bool GetSystemPath(std::wstring& Path);
        bool IsPathExists(const std::wstring& Path);
        bool IsPathExists(const std::string& Path);
        bool IsPathDirectory(const std::wstring& Path);
        bool IsPathDirectory(const std::string& Path);
        bool GetCurDirectory(std::string& Path);
        bool GetCurDirectory(std::wstring& Path);
        bool SetCurDirectory(const std::string& Path);
        bool SetCurDirectory(const std::wstring& Path);
    }
}