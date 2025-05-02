import os, subprocess
import globals

CONFIGURATION = "Debug" # Потом переделать на что-то более адекватное!!!

if globals.IsWindows():
    MS_BUILD_PATH = os.environ["MS_BUILD_PATH"][8:-1] # При взятии пути нужно убрать кавычки!
    MS_BUILD_PATH = "C:\\\\" + MS_BUILD_PATH

    subprocess.call(["cmd.exe", "/c", MS_BUILD_PATH, "{}.sln".format(globals.ENGINE_NAME), "/property:Configuration={}".format(CONFIGURATION)])

if globals.IsLinux():
    subprocess.call(["make", "config={}".format(CONFIGURATION)])

if globals.IsMac():
    subprocess.call(["make", "config={}".format(CONFIGURATION)])