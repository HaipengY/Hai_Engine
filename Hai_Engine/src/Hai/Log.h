#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hai {
	
	class HAI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}
#define HAI_CLIENT_TRACE(...)  ::Hai::Log::GetClientLogger() ->trace(__VA_ARGS__)
#define HAI_CLIENT_INFO(...)   ::Hai::Log::GetClientLogger() ->info(__VA_ARGS__)
#define HAI_CLIENT_WARN(...)   ::Hai::Log::GetClientLogger() ->warn(__VA_ARGS__)
#define HAI_CLIENT_ERROR(...)  ::Hai::Log::GetClientLogger() ->error(__VA_ARGS__)
#define HAI_CLIENT_FATAL(...)  ::Hai::Log::GetClientLogger() ->fatal(__VA_ARGS__)

#define HAI_CORE_TRACE(...)    ::Hai::Log::GetCoreLogger() ->trace(__VA_ARGS__)
#define HAI_CORE_INFO(...)     ::Hai::Log::GetCoreLogger() ->info(__VA_ARGS__)
#define HAI_CORE_WARN(...)     ::Hai::Log::GetCoreLogger() ->warn(__VA_ARGS__)
#define HAI_CORE_ERROR(...)    ::Hai::Log::GetCoreLogger() ->error(__VA_ARGS__)
#define HAI_CORE_FATAL(...)    ::Hai::Log::GetCoreLogger() ->fatal(__VA_ARGS__)

