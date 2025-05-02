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

project "zoryagamekit"
    location "zoryagamekit"
    kind "ConsoleApp"
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

    flags
    {
        "FatalWarnings"
    }
