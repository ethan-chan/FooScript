///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   char_set.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.01.10
//  Comment     :   ×Ö·û¼¯Ïà¹Ø
//
///////////////////////////////////////////////////////////////////////////////
#include "char_set.h"
#include <codecvt>
#include <windows.h>
#include <vector>

std::wstring FooBase::CharSet::s2ws(const std::string& str)
{
    typedef std::codecvt_utf8<wchar_t> convert_typeX;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.from_bytes(str);
}

std::string FooBase::CharSet::ws2s(const std::wstring& wstr)
{
    typedef std::codecvt_utf8<wchar_t> convert_typeX;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

std::string FooBase::CharSet::utf82string(const std::string& utf8) {
    // UTF-8 to wstring
    int                requiredSize = 0;
    std::wstring    wstr         = s2ws(utf8);
    
    // = MultiByteToWideChar(CP_ACP,0,utf8.c_str(), utf8.length(), 0, 0);
    //if (!requiredSize) {
    //    return "";
    //}
    //std::vector<wchar_t> wbuf(requiredSize);
    //if (!MultiByteToWideChar(CP_ACP, 0, utf8.c_str(), utf8.length(), wbuf.data(), requiredSize))
    //    return "";

    // wstring to string
    requiredSize = WideCharToMultiByte(CP_ACP,0,wstr.data(), wstr.size(), 0, 0, 0, 0);
    if (!requiredSize) {
        return "";
    }
    std::vector<char> buf(requiredSize);
    requiredSize = WideCharToMultiByte(CP_ACP, 0, wstr.data(), wstr.size(), buf.data(), buf.size(), 0, 0);
    if (!requiredSize) {
        return "";
    }

    return std::string(buf.data(), buf.size());
}

std::string FooBase::CharSet::string2utf8(const std::string& str) {
    int                requiredSize = 0;
    requiredSize = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), 0, 0);
    if (!requiredSize) {
        return "";
    }
    std::vector<wchar_t> wstr(requiredSize);
    if (!MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), wstr.data(), requiredSize))
        return "";

    requiredSize = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), wstr.size(), 0, 0, 0, 0);
    if (!requiredSize) {
        return "";
    }
    std::vector<char> buf(requiredSize);
    requiredSize = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), wstr.size(), buf.data(), buf.size(), 0, 0);
    if (!requiredSize) {
        return "";
    }

    return std::string(buf.data(), buf.size());
}

bool FooBase::CharSet::s2ws(wchar_t * wstr, char * str, unsigned int length)
{
    bool bResult = false;
    do 
    {
        if (wstr == NULL || str == NULL || length == 0)
        {
            break;
        }
        if (!WideCharToMultiByte(CP_ACP, 0, wstr, length, str , length, NULL, NULL))
        {
            break;
        }
        bResult = true;
    } while (false);
    return bResult;
}

bool FooBase::CharSet::ws2s(char * str, wchar_t * wstr, unsigned int length)
{
    bool bResult = false;
    do
    {
        if (wstr == NULL || str == NULL || length == 0)
        {
            break;
        }
        if (!MultiByteToWideChar(CP_ACP, 0, str, length , wstr, length))
        {
            break;
        }
        bResult = true;
    } while (false);
    return bResult;
}