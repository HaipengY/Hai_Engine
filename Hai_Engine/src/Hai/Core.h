#pragma once

#ifdef HAI_PLATFORM_WINDOWS
	#ifdef HAI_BUILD_DLL
		#define HAI_API __declspec(dllexport)
	#else
		#define HAI_API __declspec(dllimport)
	#endif
#else
	#error Only Windows!!
#endif