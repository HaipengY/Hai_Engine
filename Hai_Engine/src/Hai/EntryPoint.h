#pragma once

#ifdef HAI_PLATFORM_WINDOWS

extern	 Hai::Application* Hai::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hai::CreateApplication();
	app->run();
	delete app;
}

#endif