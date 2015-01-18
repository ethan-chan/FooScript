///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   char_set.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.01.10
//  Comment     :   ×Ö·û¼¯Ïà¹Ø
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

namespace FooBase{
    namespace CharSet{
        std::wstring s2ws(const std::string& str);
        std::string ws2s(const std::wstring& wstr);
        std::string utf82string(const std::string& utf8);
        std::string string2utf8(const std::string& str);
        bool s2ws(wchar_t * wstr, char * str, unsigned int length);
        bool ws2s(char * str, wchar_t * wstr, unsigned int length);
    }
}