import os, subprocess, sys
import globals

config = "Debug"
exepath = "{}/bin/{}/{}/".format(os.getcwd(), config, globals.PROJECT_NAME)
error_return = 0

if globals.IsWindows():
    print("Executing...\n")
    error_return = subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(globals.TOOL_DIR), config, globals.PROJECT_NAME], cwd=os.getcwd())
else:
    error_return = subprocess.call(["{}{}".format(exepath, globals.PROJECT_NAME)], cwd=exepath)

sys.exit(error_return)