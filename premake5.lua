workspace "Zodiac"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	IncludeDir = {}
	IncludeDir["GLFW"] = "Zodiac/vendor/GLFW/include"
	IncludeDir["Glad"] = "Zodiac/vendor/Glad/include"

	include "Zodiac/vendor/GLFW"
	include "Zodiac/vendor/Glad"
project "Zodiac"
	location "Zodiac"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "zopch.h"
	pchsource "Zodiac/src/zopch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZO_PLATFORM_WINDOWS",
			"ZO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/ZodiacPlayground")
		}

	filter "configurations:Debug"
		defines "ZO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ZO_Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ZO_Dist"
		buildoptions "/MD"
		optimize "On"

project "ZodiacPlayground"
	location "ZodiacPlayground"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Zodiac/src",
		"Zodiac/vendor/spdlog/include"
	}

	links
	{
		"Zodiac"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ZO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ZO_Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ZO_Dist"
		buildoptions "/MD"
		optimize "On"