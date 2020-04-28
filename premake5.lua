solution "Hai_Engine"
	architecture "x64"
	configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hai_Engine"
	location "Hai_Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/submodule/spdlog/include",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines{
		"HAI_PLATFORM_WINDOWS",
		"HAI_BUILD_DLL",
		"_WINDLL",
		"_SCL_SECURE_NO_WARNINGS"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "HAI_DEBUG"
		symbols "ON"

	filter "configurations:Release"
		defines "HAI_RELEASE"
		optimize "ON"

	filter "configurations:Dist"
		defines "HAI_DIST"
		optimize "ON"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	includedirs
	{
		"Hai_Engine/submodule/spdlog/include",
		"Hai_Engine/src"
	}
	links{
		"Hai_Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines{
		"HAI_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HAI_DEBUG"
		symbols "ON"

	filter "configurations:Release"
		defines "HAI_RELEASE"
		optimize "ON"

	filter "configurations:Dist"
		defines "HAI_DIST"
		optimize "ON"