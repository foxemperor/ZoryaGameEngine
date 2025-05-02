import sys, platform

ENGINE_NAME = "zorya"
PROJECT_NAME = "zoryagamekit"
TOOL_DIR = "toolkit"

V_MAJOR = 1
V_MINOR = 0
PLATFORM = sys.platform
for x in platform.uname():
    if "microsoft" in x.lower():
        PLATFORM = "windows"
        break

def IsWindows():
    return PLATFORM == "windows"

def IsLinux():
    return PLATFORM == "linux"

def IsMac():
    return PLATFORM == "darwin"
