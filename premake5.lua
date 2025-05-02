workspace "zorya"
    startproject "zoryagamekit"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

project "zoryagamekit"
    location "zoryagamekit"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    flags
    {
        "FatalWarnings"
    }
