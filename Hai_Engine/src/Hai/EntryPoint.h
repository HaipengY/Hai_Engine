#pragma once

#ifdef HAI_PLATFORM_WINDOWS

extern Hai::Application* Hai::CreateApplication();

int main(int argc, char** argv)
{
	Hai::Log::Init();
	HAI_CORE_WARN("INITIALIZED LOG");
	HAI_CLIENT_INFO("HALLO HAI!");

	auto app = Hai::CreateApplication();
	app->run();
	delete app;
}

#endif