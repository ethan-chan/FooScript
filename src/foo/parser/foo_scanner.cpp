#include "stdafx.h"
#include "foo_scanner.h"

using namespace FooScript;
using Parser::FooScanner;

void FooScanner::PushString(const std::string& CmdString) {
    // clear the eofbit
    if (!ss.good())
        ss.clear();
    ss << CmdString << std::endl;
}