#include<predator.h>
	
class Sandbox :public predator::Application {
public:
	Sandbox() {};
	~Sandbox() {}

};


int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}