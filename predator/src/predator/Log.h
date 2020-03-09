#pragma once

#include"Core.h"
#include<memory>
#include"spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace predator {
	class PD_API Log {
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger>s_CoreLogger;
		static std::shared_ptr<spdlog::logger>s_ClientLogger;
	};
}

#define PD_CORE_TRACE(...) ::predator::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PD_CORE_INFO(...) ::predator::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PD_CORE_WARN(...) ::predator::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PD_CORE_ERROR(...) ::predator::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PD_CORE_FATAL(...) ::predator::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define PD_CLIENT_TRACE(...)  ::predator::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PD_CLIENT_INFO(...)   ::predator::Log::GetClientLogger()->info(__VA_ARGS__)
#define PD_CLIENT_WARN(...)   ::predator::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PD_CLIENT_ERROR(...)  ::predator::Log::GetClientLogger()->error(__VA_ARGS__)
#define PD_CLIENT_FATAL(...)  ::predator::Log::GetClientLogger()->fatal(__VA_ARGS__)




