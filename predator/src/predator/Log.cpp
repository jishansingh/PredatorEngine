
#include"Log.h"
	
namespace predator {
	std::shared_ptr<spdlog::logger>Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger>Log::s_ClientLogger;
	
	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("PREDATOR");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("app");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}


