import os, subprocess, sys
import globals

CONFIGURATION = "Debug" # Потом переделать на что-то более адекватное!!!

error_return = 0

if globals.IsWindows():
    MS_BUILD_PATH = os.environ["MS_BUILD_PATH"][8:-1] # При взятии пути нужно убрать кавычки!
    MS_BUILD_PATH = "C:\\\\" + MS_BUILD_PATH

    error_return = subprocess.call(["cmd.exe", "/c", MS_BUILD_PATH, "{}.sln".format(globals.ENGINE_NAME), "/property:Configuration={}".format(CONFIGURATION)])

if globals.IsLinux():
    error_return = subprocess.call(["make", "config={}".format(CONFIGURATION)])

if globals.IsMac():
    error_return = subprocess.call(["make", "config={}".format(CONFIGURATION)])

sys.exit(error_return)