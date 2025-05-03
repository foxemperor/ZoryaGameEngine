workspace "zorya"
    startproject "zoryagamekit"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

-- Чтобы директории были привязаны к конкретному проекту, а не создавались общие
tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin-obj/%{cfg.buildcfg}/%{prj.name}"

project "zorya"
    location "zorya"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs
    {
        "%{prj.name}/include/engine"
    }

    flags
    {
        "FatalWarnings"
    }

    filter {"system:macosx", "configurations:*"}
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }

        defines 
        {
            "ZORYAENGINE_PLATFORM_MAC"
        }

    filter {"system:linux", "configurations:*"}
        defines 
        {
            "ZORYAENGINE_PLATFORM_LINUX"
        }

    filter {"system:windows", "configurations:*"}
        systemversion "latest"

        defines 
        {
            "ZORYAENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines
        {
            "ZORYAENGINE_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"
        optimize "off"
        
    filter "configurations:Release"
        defines
        {
            "ZORYAENGINE_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"

project "zoryagamekit"
    location "zoryagamekit"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    links "zorya"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs
    {
        "zorya/include"
    }

    flags
    {
        "FatalWarnings"
    }

    filter {"system:macosx", "configurations:*"}
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }

        defines 
        {
            "ZORYAENGINE_PLATFORM_MAC"
        }

    filter {"system:linux", "configurations:*"}
        defines 
        {
            "ZORYAENGINE_PLATFORM_LINUX"
        }

    filter {"system:windows", "configurations:*"}
        systemversion "latest"

        defines 
        {
            "ZORYAENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines
        {
            "ZORYAENGINE_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"
        optimize "off"
        
    filter "configurations:Release"
        defines
        {
            "ZORYAENGINE_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"