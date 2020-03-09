#pragma once
#include "Core.h"
#include "events/Event.h"
namespace predator{

	class PD_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* createApplication();
}



