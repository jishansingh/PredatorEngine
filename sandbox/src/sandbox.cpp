#include<predator.h>
	
class Sandbox :public predator::Application {
public:
	Sandbox() {};
	~Sandbox() {}
};

predator::Application* predator::createApplication() {
	return new Sandbox();
}