#include "Application.h"
#include"events/ApplicationEvent.h"
#include"Log.h"
predator::Application::Application()
{
}

predator::Application::~Application()
{
}

void predator::Application::Run()
{
	predator::WindowResizeEvent e(1200, 720);
	PD_CLIENT_TRACE(e);
	while (true);
	return;
}
