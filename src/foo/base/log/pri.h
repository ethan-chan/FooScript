///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   pri.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.04.10
//  Comment     :   可打印对象实现
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
namespace FooBase{
    namespace Log{
        namespace Pri{
            class Printable{
            public:
                Printable() {}
                virtual ~Printable() {}
            public:
                virtual const std::string ToString() const = 0;
            };

            class GError : public Printable{
            public:
                GError();
                explicit GError(unsigned int Error);
            public:
                const std::string ToString() const;
            private:
                unsigned int error;
            };

            class HexDump : public Printable{
            public:
                HexDump(char* Start, size_t Length);
            public:
                const std::string ToString() const;
            private:
                char * start;
                size_t length;
            };
        }
    }
}