#include<predator.h>
	
class Sandbox :public predator::Application {
public:
	Sandbox() {};
	~Sandbox() {}
};

predator::Application* predator::createApplication() {
	auto s = new Sandbox();
	return (s);
}
