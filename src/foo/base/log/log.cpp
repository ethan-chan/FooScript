///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   log.cpp
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   多模式分级日志的实现
//
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>

#include "log.h"
#include "base\char_set.h"

using FooBase::Log::FooLog;
using FooBase::Log::LOG_LEVEL_SOFT;
using FooBase::Log::LOG_LEVEL_HARD;
using FooBase::Log::LOG_FOR;
using FooBase::Log::FOO_LOG_FORMAT_CODE;
using FooBase::Log::Manager;
using FooBase::Log::Dispatcher;
using FooBase::Log::Pri::Printable;
using FooBase::Log::LogOStream;

FooLog::FooLog(
    LOG_LEVEL_SOFT LevelSoft,
    LOG_LEVEL_HARD LevelHard,
    LOG_FOR           For,
    LogOStream& o) :
    log_level_soft(LevelSoft),
    log_level_hard(LevelHard),
    log_for(For),
    target(o){
}

FooLog::~FooLog() {
}

FooLog& FooLog::operator<<(const FOO_LOG_FORMAT_CODE& FormatCode) {
    if (FormatCode == FooLogEnd)
        target << std::endl;
    if (FormatCode == FooLogFlush)
        target.flush();
    else if (FormatCode == FooLogCmdPre)
        target << '>';
    else if (FormatCode == FooLogCmdIndent)
        target << '    ';
    return *this;
}

FooLog& FooLog::operator<<(const unsigned long& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const unsigned int& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const int& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const long long& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const double& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const char& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const char* v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const wchar_t& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const wchar_t* v) {
    std::wstring ws(v);
    target << FooBase::CharSet::ws2s(ws);
    return *this;
}

FooLog& FooLog::operator<<(const std::wstring& v) {
    target << FooBase::CharSet::ws2s(v);
    return *this;
}

FooLog& FooLog::operator<<(const std::string& v) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const std::_Smanip<std::streamsize>& v) {
    target << v;
    return *this;
}

template<class _Elem>
FooLog& FooLog::operator<<(const std::_Fillobj<_Elem>& v) {
    target << v;
    return *this;
}

template FooLog& FooLog::operator<<(const std::_Fillobj<char>& v);

FooLog& FooLog::operator<<(std::ostream& (*v)(std::ostream&)) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(std::ios_base& (__cdecl *v)(std::ios_base&)) {
    target << v;
    return *this;
}

FooLog& FooLog::operator<<(const Printable& v) {
    const std::string& s = v.ToString();
    std::string::size_type pos = std::string::npos;
    std::string::size_type start = 0;
    while ((pos = s.find('\n', start)) != std::string::npos) {
        target << " " << s.substr(start, pos + 1 - start);
        start = pos + 1;
    }
    if (start < s.length())
        target << " " << s.substr(start);
    return *this;
}

LOG_LEVEL_SOFT FooLog::LogLevelSoft() const {
    return log_level_soft;
}

LOG_LEVEL_HARD FooLog::LogLevelHard() const {
    return log_level_hard;
}

LOG_FOR FooLog::LogFor() const {
    return log_for;
}

Manager::Manager(
    LogOStream& SysLogOStream,
    LogOStream& UserLogOStream) :
    dispatcher_none(*this, LOG_LEVEL_HARD_NONE),
    dispatcher_error(*this, LOG_LEVEL_HARD_ERROR),
    dispatcher_warning(*this, LOG_LEVEL_HARD_WARNING),
    dispatcher_info(*this, LOG_LEVEL_HARD_INFO),
    dispatcher_debug(*this, LOG_LEVEL_HARD_DEBUG),
    dispatcher_help(*this, LOG_LEVEL_SOFT_HELP),
    dispatcher_data(*this, LOG_LEVEL_SOFT_DATA) {
    // logs that show to user
    CreateLog(Log::LOG_LEVEL_SOFT_HELP, Log::LOG_LEVEL_HARD_DEBUG, Log::LOG_FOR_USER, UserLogOStream);
    // log that used by develop(or manager)
    CreateLog(Log::LOG_LEVEL_SOFT_NONE, Log::LOG_LEVEL_HARD_DEBUG, Log::LOG_FOR_DEVELOPER, SysLogOStream);
}

Manager::~Manager() {
}

void Manager::CreateLog(
    LOG_LEVEL_SOFT    LevelSoft,
    LOG_LEVEL_HARD    LevelHard,
    LOG_FOR            For,
    LogOStream&    o) {
    log_list.push_back(std::shared_ptr<FooLog>(new FooLog(LevelSoft, LevelHard, For, o)));
}

void Manager::RedirectUserLog(LogOStream& o) {
    user_log = log_list.front();
    log_list.front() = std::shared_ptr<FooLog>(new
            FooLog(
            user_log->LogLevelSoft(),
            user_log->LogLevelHard(),
            Log::LOG_FOR_USER, o)
        );
}

void Manager::RestoreUserLog() {
    log_list.front() = user_log;
}

void Manager::OutPutTimePre(FooLog& Log) {
    std::time_t T = std::time(NULL);
    std::tm        Tm;
    errno_t e = localtime_s(&Tm, &T);
    if (e)
        return;

    Log << L"[" <<
        (int)(1900 + Tm.tm_year) << L"-" << std::setw(2) <<
        Tm.tm_mon + 1 << L"-" <<
        Tm.tm_mday << L" " <<
        Tm.tm_hour << L":" <<
        Tm.tm_min << L":" <<
        Tm.tm_sec << L"]" << L"\t";
}

void Manager::OutPutTimePreHard(LOG_LEVEL_HARD LevelHard) {
    for (auto log : log_list) {
        if (log->LogFor() == LOG_FOR_DEVELOPER && log->LogLevelHard() >= LevelHard) {
            OutPutTimePre(*log);
        }
    }
}

void Manager::OutPutTimePreSoft(LOG_LEVEL_SOFT LevelSoft) {
    for (auto log : log_list) {
        if (log->LogFor() == LOG_FOR_DEVELOPER && log->LogLevelSoft() >= LevelSoft) {
            OutPutTimePre(*log);
        }
    }
}


Dispatcher<LOG_LEVEL_HARD>& Manager::LOG_NONE() {
    OutPutTimePreHard(LOG_LEVEL_HARD_NONE);
    dispatcher_none << " ";
    return dispatcher_none;
}

Dispatcher<LOG_LEVEL_HARD>& Manager::LOG_DEBUG() {
    dispatcher_warning << green;
    OutPutTimePreHard(LOG_LEVEL_HARD_DEBUG);
    dispatcher_debug << " ";
    return dispatcher_debug;
}

Dispatcher<LOG_LEVEL_HARD>& Manager::LOG_INFO() {
    dispatcher_warning << green;
    OutPutTimePreHard(LOG_LEVEL_HARD_INFO);
    dispatcher_info << " ";
    return dispatcher_info;
}

Dispatcher<LOG_LEVEL_HARD>& Manager::LOG_WARNING() {
    dispatcher_warning << red;
    OutPutTimePreHard(LOG_LEVEL_HARD_WARNING);
    dispatcher_warning << " ";
    return dispatcher_warning;
}

Dispatcher<LOG_LEVEL_HARD>& Manager::LOG_ERROR() {
    dispatcher_error << red;
    OutPutTimePreHard(LOG_LEVEL_HARD_ERROR);
    dispatcher_error << " ";
    return dispatcher_error;
}

Dispatcher<LOG_LEVEL_SOFT>& Manager::LOG_HELP() {
    dispatcher_help << yellow;
    OutPutTimePreSoft(LOG_LEVEL_SOFT_HELP);
    return dispatcher_help;
}

Dispatcher<LOG_LEVEL_SOFT>& Manager::LOG_DATA() {
    dispatcher_data << blue;
    OutPutTimePreSoft(LOG_LEVEL_SOFT_DATA);
    return dispatcher_data;
}

std::ostream& FooBase::Log::blue(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& FooBase::Log::red(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& FooBase::Log::green(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN);
    return s;
}

std::ostream& FooBase::Log::yellow(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

std::ostream& FooBase::Log::white(std::ostream& s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return s;
}