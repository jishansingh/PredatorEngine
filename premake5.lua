workspace "Solution"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "predator"
	location "predator"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"predator/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"PD_PLATFORM_WINDOWS",
			"PD_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/sandbox")
		}

	filter "configurations:Debug"
		defines "PD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PD_DIST"
		optimize "On"



project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/"..outputdir.."/%{prj.name}")
	objdir("bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"predator/vendor/spdlog/include",
		"predator/src"
	}
	links
	{
		"predator"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"PD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PD_DIST"
		optimize "On"




