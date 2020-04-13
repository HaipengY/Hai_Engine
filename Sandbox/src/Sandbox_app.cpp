#include <Hai.h>

class Sandbox :public Hai::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Hai::Application* Hai::CreateApplication()
{
	return new Sandbox();
}