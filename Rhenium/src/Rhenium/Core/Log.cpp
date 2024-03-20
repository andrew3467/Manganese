//
// Created by Andrew Graser on 3/20/2024.
//

#include "Log.h"

#include "spdlog/sinks/basic_file_sink.h"
#include <spdlog/sinks/stdout_color_sinks.h>


namespace Manganese {

    std::shared_ptr<spdlog::logger> Log::mCoreLogger;

    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        mCoreLogger = spdlog::stdout_color_mt("MANGANESE");
        mCoreLogger->set_level(spdlog::level::trace);
    }
}