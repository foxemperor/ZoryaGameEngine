import subprocess, sys
import globals

error_return = 0

if globals.IsWindows():
    error_return = subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2022"])

if globals.IsLinux():
    error_return = subprocess.call({"premake/premake5.linux", "gmake2"})

if globals.IsMac():
    error_return = subprocess.call({"premake/premake5", "gmake2"})
    if error_return == 0:
        error_return = subprocess.call({"premake/premake5", "xcode4"})

sys.exit(error_return)