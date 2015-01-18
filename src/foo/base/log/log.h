///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   log.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   多模式分级日志的实现
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <list>
#include <ctime>
#include <iomanip>
#include <memory>

#include "pri.h"

namespace FooBase{
    namespace Log{
        enum LOG_LEVEL_SOFT
        {    // from least to most
            LOG_LEVEL_SOFT_NONE = 0,
            LOG_LEVEL_SOFT_DATA,
            LOG_LEVEL_SOFT_HELP
        };

        enum LOG_LEVEL_HARD
        {    // from least to most
            LOG_LEVEL_HARD_NONE = 0,
            LOG_LEVEL_HARD_ERROR,
            LOG_LEVEL_HARD_WARNING,
            LOG_LEVEL_HARD_INFO,
            LOG_LEVEL_HARD_DEBUG
        };

        enum LOG_FOR{
            LOG_TYPE_NONE = 0,
            LOG_FOR_USER,
            LOG_FOR_DEVELOPER
        };

        enum FOO_LOG_FORMAT_CODE {
            FooLogEnd,    // \n + flush
            FooLogFlush,// flush
            FooLogCmdPre,
            FooLogCmdIndent
        };

        class LogOStream {
        public:
            LogOStream(std::ostream& O) : o(O) { o.precision(std::numeric_limits<double>::digits10); }
            virtual LogOStream& operator<<(const unsigned long& v) { o << v; return *this; }
            virtual LogOStream& operator<<(const unsigned int& v) { o << v; return *this;}
            virtual LogOStream& operator<<(const int& v) { o << v; return *this; }
            virtual LogOStream& operator<<(const long long& v) { o << v; return *this; }
            virtual LogOStream& operator<<(const double& v) { o << v; return *this; }
            virtual LogOStream& operator<<(const char& v) { o << v; return *this; }
            virtual LogOStream& operator<<(const char* v) { o << v; return *this; }
            virtual LogOStream& operator<<(const std::string& v) { o << v; return *this; }
            virtual LogOStream& operator<<(const std::_Smanip<std::streamsize>& v) { o << v; return *this; }
            template<class _Elem>
            LogOStream& operator<<(const std::_Fillobj<_Elem>& v) { o << v; return *this; }
            virtual LogOStream& operator<<(std::ostream& (*v)(std::ostream&)) {o << v;return *this;}
            virtual LogOStream& operator<<(std::ios_base& (__cdecl *v)(std::ios_base&)) { o << v; return *this; }
            std::ostream& flush() { o.flush(); return o; }
        private:
                std::ostream&    o;
        };

        class Manager;

        class FooLog : public std::enable_shared_from_this<FooLog> {
        public:
            FooLog(
                LOG_LEVEL_SOFT LevelSoft,
                LOG_LEVEL_HARD LevelHard,
                LOG_FOR For, LogOStream& o);
            ~FooLog();
            // delete
            FooLog() = delete;
            FooLog& operator=(FooLog const&) = delete;
        public:
            FooLog& operator<<(const FOO_LOG_FORMAT_CODE& FormatCode);
            FooLog& operator<<(const unsigned long& v);
            FooLog& operator<<(const unsigned int& v);
            FooLog& operator<<(const int& v);
            FooLog& operator<<(const long long& v);
            FooLog& operator<<(const double& v);
            FooLog& operator<<(const char& v);
            FooLog& operator<<(const char* v);
            FooLog& operator<<(const wchar_t& v);
            FooLog& operator<<(const wchar_t* v);
            FooLog& operator<<(const std::wstring& v);
            FooLog& operator<<(const std::string& v);
            FooLog& operator<<(const std::_Smanip<std::streamsize>& v);
            template<class _Elem>
            FooLog& operator<<(const std::_Fillobj<_Elem>& v);
            FooLog& operator<<(std::ostream& (*v)(std::ostream&));
            FooLog& operator<<(std::ios_base& (__cdecl *v)(std::ios_base&));
            FooLog& operator<<(const Pri::Printable& v);
            LOG_LEVEL_SOFT LogLevelSoft() const;
            LOG_LEVEL_HARD LogLevelHard() const;
            LOG_FOR   LogFor() const;
        private:
            LOG_LEVEL_SOFT    log_level_soft;
            LOG_LEVEL_HARD    log_level_hard;
            LOG_FOR            log_for;
            LogOStream&        target;
        };

        template <typename TLevelType>
        class Dispatcher{
        public:
            Dispatcher(
                Manager& M, 
                TLevelType Level);
            ~Dispatcher();
            // delete
            Dispatcher() = delete;
            Dispatcher(Dispatcher const&) = delete;
            Dispatcher& operator=(Dispatcher const&) = delete;
        public:
            template <typename TValueType>
            Dispatcher<TLevelType>& operator<<(const TValueType& v) {
                m.OutPut(v, log_level);
                return *this;
            }
        private:
            Manager&    m;
            TLevelType    log_level;
        };

        template <typename TLevelType>
        Dispatcher<TLevelType>::Dispatcher(
            Manager&    M,
            TLevelType    Level) :
            m(M),
            log_level(Level) {

        }

        template <typename TLevelType>
        Dispatcher<TLevelType>::~Dispatcher() {

        }

        class Manager{
        public:
            Manager(
                LogOStream& SysLogOStream,
                LogOStream& UserLogOStream);
            ~Manager();
            // delete
            Manager() = delete;
            Manager(Manager const&) = delete;
            Manager& operator=(Manager const&) = delete;
        public:
            Dispatcher<LOG_LEVEL_HARD>& LOG_NONE();
            Dispatcher<LOG_LEVEL_HARD>& LOG_DEBUG();
            Dispatcher<LOG_LEVEL_HARD>& LOG_INFO();
            Dispatcher<LOG_LEVEL_HARD>& LOG_WARNING();
            Dispatcher<LOG_LEVEL_HARD>& LOG_ERROR();
            Dispatcher<LOG_LEVEL_SOFT>& LOG_HELP();
            Dispatcher<LOG_LEVEL_SOFT>& LOG_DATA();

            template <typename T, typename TLevelType>
            void OutPut(
                T v, TLevelType LogLevel);
        public:
            void CreateLog(
                LOG_LEVEL_SOFT LevelSoft,
                LOG_LEVEL_HARD LevelHard,
                LOG_FOR For,
                LogOStream& o);

            void RedirectUserLog(LogOStream& o);
            void RestoreUserLog();

            void OutPutTimePre(FooLog& Log);
            void OutPutTimePreHard(LOG_LEVEL_HARD LevelHard);
            void OutPutTimePreSoft(LOG_LEVEL_SOFT LevelSoft);
        private:
            std::list<std::shared_ptr<FooLog>> log_list;
            std::shared_ptr<FooLog>            user_log;

            Dispatcher<LOG_LEVEL_HARD>    dispatcher_none;
            Dispatcher<LOG_LEVEL_HARD>    dispatcher_debug;
            Dispatcher<LOG_LEVEL_HARD>    dispatcher_info;
            Dispatcher<LOG_LEVEL_HARD>    dispatcher_warning;
            Dispatcher<LOG_LEVEL_HARD>    dispatcher_error;
            Dispatcher<LOG_LEVEL_SOFT>    dispatcher_help;
            Dispatcher<LOG_LEVEL_SOFT>    dispatcher_data;
        };

        template <typename T, typename TLevelType>
        void Manager::OutPut(T v, TLevelType LogLevel) {
            for (auto log : log_list) {
                if (std::is_same<TLevelType, LOG_LEVEL_SOFT>::value) {
                    if (LogLevel <= log->LogLevelSoft()) {
                        *log << v;
                    }
                }
                else if (std::is_same<TLevelType, LOG_LEVEL_HARD>::value){
                    if (LogLevel <= log->LogLevelHard()) {
                        *log << v;
                    }
                }
                else {
                }
            }
        }

        std::ostream& blue(std::ostream& s);
        std::ostream& red(std::ostream& s);
        std::ostream& green(std::ostream& s);
        std::ostream& yellow(std::ostream& s);
        std::ostream& white(std::ostream& s);

        struct color {
            color(unsigned int attribute) :m_color(attribute){};
            unsigned int m_color;
        };

        template <class _Elem, class _Traits>
        std::basic_ostream<_Elem, _Traits>&
            operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c)
        {
                HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hStdout, c.m_color);
                return i;
        }
    }
}