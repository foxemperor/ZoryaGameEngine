workspace "zorya"
    startproject "zoryagamekit"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

-- Пути к vendor-зависимостям
VENDOR_SDL3_INCLUDE = "vendor/SDL3/include"
VENDOR_SDL3_LIB     = "vendor/SDL3/lib/x64"

project "zoryagamekit"
    location "zoryagamekit"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir    ("bin-int/%{cfg.buildcfg}")

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/include",
        VENDOR_SDL3_INCLUDE
    }

    libdirs
    {
        VENDOR_SDL3_LIB
    }

    links
    {
        "SDL3",
        "opengl32"
    }

    flags { "FatalWarnings" }

    filter "configurations:Debug"
        defines { "DEBUG", "ZGE_DEBUG" }
        symbols "on"
        optimize "off"

    filter "configurations:Release"
        defines { "NDEBUG", "ZGE_RELEASE" }
        optimize "on"
        symbols "off"
