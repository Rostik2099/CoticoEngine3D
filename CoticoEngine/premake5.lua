project "CoticoEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Source/**.h",
		"Source/**.cpp",
		"ThirdParty/include/**.hpp",
		"ThirdParty/include/**.inl",
		"ThirdParty/include/**.c",
	}

	includedirs 
	{
		"ThirdParty/include",
		"Source",
	}

	libdirs
	{
		"ThirdParty/lib",
	}

	defines
	{
	}

	links
	{
		"glfw3.lib",
		"opengl32.lib",
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter { "system:windows"}
		buildoptions "/MD"