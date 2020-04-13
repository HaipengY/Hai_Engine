#pragma once
#include "Core.h"

namespace Hai {
	class HAI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* CreateApplication();

}