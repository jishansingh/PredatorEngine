#pragma once
#include"Application.h"
#include"Log.h"
#ifdef PD_PLATFORM_WINDOWS

extern predator::Application* predator::createApplication();
int main(int argc, char* argv[]) {
	predator::Log::init();
	PD_CORE_WARN("warn core logger");
	PD_CLIENT_INFO("info client logger");
	auto sand = predator::createApplication();
	sand->Run();
	delete sand;
}

#endif

