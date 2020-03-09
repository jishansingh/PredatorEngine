#include<predator.h>
	
class Sandbox :public predator::Application {
public:
	Sandbox() {};
	~Sandbox() {}

};


int main() {
	predator::Log::init();
	PD_CORE_WARN("warn core logger");
	PD_CLIENT_INFO("info client logger");
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}