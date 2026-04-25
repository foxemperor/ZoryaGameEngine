import subprocess, sys, os

if sys.platform == "win32":
    premake = os.path.join("premake", "premake5.exe")
elif sys.platform == "darwin":
    premake = os.path.join("premake", "premake5")
else:
    premake = os.path.join("premake", "premake5.linux")

subprocess.call([premake, "vs2022"])
