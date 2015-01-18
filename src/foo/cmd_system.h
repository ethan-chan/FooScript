///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   cmd_system.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2013.12.19
//  Comment     :   命令行系统的定义，即整个模块的封装，保存并控制着各个子管理模块
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "parser\reg_parser.h"
#include "parser\foo_driver.h"

namespace FooScript{

    class FooCmdSystem final{
    public:
        FooCmdSystem(
            FooBase::Log::LogOStream& SysLogOStream,
            FooBase::Log::LogOStream& UserLogOStream);
        ~FooCmdSystem();
        // delete
        FooCmdSystem() = delete;
        FooCmdSystem(FooCmdSystem const&) = delete;
        FooCmdSystem& operator=(FooCmdSystem const&) = delete;

        void Start();
        void Start(int argc, _TCHAR* argv[]);
        void Start(const std::wstring& ModulePath);

        void Run(const tCmdString& CmdString);

        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& LOG_NONE();
        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& LOG_DEBUG();
        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& LOG_INFO();
        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& LOG_WARNING();
        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_HARD>& LOG_ERROR();
        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_SOFT>& LOG_HELP();
        FooBase::Log::Dispatcher<FooBase::Log::LOG_LEVEL_SOFT>& LOG_DATA();

        void RedirectUserLog(FooBase::Log::LogOStream& o);
        void RestoreUserLog();
        void ResetParser();

        void Stop() { is_stop = true; };

        const std::string& GetEngineRootDirectory() const { return engine_root_directory; }

        // get specified sub module path
        std::string GetEngineSubModulePath(const std::string& ModuleName) const;
        std::wstring GetEngineSubModulePath(const std::wstring& ModuleName) const;
        std::string GetEngineSubModulePath(
            const std::string& SubDirectory,
            const std::string& ModuleName) const;
        std::wstring GetEngineSubModulePath(
            const std::wstring& SubDirectory,
            const std::wstring& ModuleName) const;

        std::string GetModuleAbsPathFromRel(const tCmdString& RelativePath) const;
        std::string GetModuleRelPathFromModule(const tCmdString& ModulePath) const;

        void InitGlobalValues();

        void EnterFooMode() { is_in_foo = true; }
        void ExitFooMode() { is_in_foo = false; is_in_foo_block = false; }
        void EnterFooBlockMode() { is_in_foo = true; is_in_foo_block = true; }
        void ExitFooBlockMode() { is_in_foo = false; is_in_foo_block = false; }

    protected:
        void CommandLoop();
        bool IsRunInFooMode() const { return is_in_foo; }
    private:
        bool                            is_stop;
        bool                            is_in_foo;
        bool                            is_in_foo_block;
        std::string                        engine_root_directory;    // last character is not L'\\'
        std::vector<std::string>        module_root_directory_list;
        std::string                     work_root_directory;
        std::string                     start_module_path;
        //Module::Manager                mm;
        FooBase::Log::Manager            lm;

        //FooScript::Kernel::MainKernel    main_kernel;
        FooScript::Parser::FooDriver    foo_parser;
        FooScript::Parser::RegParser    debug_parser;
    };
}

#define FOO_MODULE_POSTFIX  ".foo"
#define FOO_MODULE_ROOT     "~" ## FOO_MODULE_POSTFIX