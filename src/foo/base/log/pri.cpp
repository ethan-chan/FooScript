///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   pri.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.04.10
//  Comment     :   可打印对象实现
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include "pri.h"

#include "base\char_set.h"

using FooBase::Log::Pri::GError;
using FooBase::Log::Pri::HexDump;

GError::GError() :error(::GetLastError()) {
}

GError::GError(unsigned int Error) : error(Error) {
}

const std::string GError::ToString() const {
    LPSTR errorText = NULL;
    std::stringstream ss;
    ::FormatMessageA(
        // use system message tables to retrieve error text
        FORMAT_MESSAGE_FROM_SYSTEM
        // allocate buffer on local heap for error text
        | FORMAT_MESSAGE_ALLOCATE_BUFFER
        // Important! will fail otherwise, since we're not 
        // (and CANNOT) pass insertion parameters
        | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,    // unused with FORMAT_MESSAGE_FROM_SYSTEM
        error,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)&errorText,  // output 
        0, // minimum size for output buffer
        NULL);   // arguments - see note 

    if (NULL != errorText)
    {
        ss << "Error code: " << std::hex << error << std::dec << ". Detail: " << errorText;
        ::LocalFree(errorText);
        errorText = NULL;
    }
    return FooBase::CharSet::string2utf8(ss.str());
}

HexDump::HexDump(char* Start, size_t Length) : start(Start), length(Length) {

}

static const unsigned int HEX_LENGTH = 16;
const std::string HexDump::ToString() const {
    std::stringstream ss;
    int Count = length / HEX_LENGTH;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i <= Count; ++i) {
        int Len = i != Count ? HEX_LENGTH : length % HEX_LENGTH;
        if (Len) {
            for (int j = 0; j < Len; ++j) {
                ss << std::setw(2) <<
                    static_cast<int>(
                    static_cast<unsigned char>(start[i * HEX_LENGTH + j])
                    ) << " ";
            }
            if (Len < HEX_LENGTH) {
                ss.width((HEX_LENGTH - Len) * 3 + 2);
                ss.fill(' ');
            }
            ss << "| ";
            std::copy(start + i * HEX_LENGTH, start + i * HEX_LENGTH + Len,
                std::ostream_iterator<char>(ss));
            ss << std::endl;
        }
    }
    return FooBase::CharSet::string2utf8(ss.str());
}