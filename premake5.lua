workspace "Zodiac"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zodiac"
	location "Zodiac"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZO_PLATFORM_WINDOWS",
			"ZO_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/ZodiacPlayground")
		}

	filter "configurations:Debug"
		defines "ZO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZO_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ZO_Dist"
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
			"ZO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "ZO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZO_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ZO_Dist"
		optimize "On"