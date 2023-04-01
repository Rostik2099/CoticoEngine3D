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
	}

	includedirs 
	{
		"ThirdParty/include",
		"Source",
	}

	libdirs
	{
	}

	defines
	{
	}

	links
	{
		"opengl32.lib",
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter { "system:windows"}
		buildoptions "/MD"