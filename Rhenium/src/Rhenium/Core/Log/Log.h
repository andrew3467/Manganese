//
// Created by Andrew Graser on 3/20/2024.
//

#ifndef MANGANESE_LOG_H
#define MANGANESE_LOG_H

#include "spdlog/spdlog.h"



namespace Manganese {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return mCoreLogger; }

    private:
        static std::shared_ptr<spdlog::logger> mCoreLogger;
    };
}

#define MN_TRACE(...)    ::Manganese::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MN_INFO(...)     ::Manganese::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MN_WARN(...)     ::Manganese::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MN_ERROR(...)    ::Manganese::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MN_FATAL(...)    ::Manganese::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define MN_ASSERT(x, ...)    {if(!(x)) {MN_ERROR("Assertion failed: {0}", __VA_ARGS__);}}


#endif //MANGANESE_LOG_H
