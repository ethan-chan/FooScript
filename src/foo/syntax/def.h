#pragma once

#include <string>

#include "syntax\value.h"
namespace FooScript {
    typedef std::string tToken;
    typedef std::string tCmdString;
    namespace Type {
        typedef std::shared_ptr<ValueObject>    tValueSPtr;
        typedef std::map<tToken, ValueObject>    tVariables;
        typedef std::unique_ptr<tVariables>        tVariablesUPtr;


        typedef long tInt32;
        typedef long long tInt64;
        typedef tInt64 tInt;
        typedef double tFloat;
    }
    static const Type::ValueObject null_value = Type::ValueObject();
}