import os, subprocess
import globals

config = "Debug"
exepath = "{}/bin/{}/{}/".format(os.getcwd(), config, globals.PROJECT_NAME)

if globals.IsWindows():
    print("Executing...\n")
    subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(globals.TOOL_DIR), config, globals.PROJECT_NAME], cwd=os.getcwd())
else:
    subprocess.call(["{}{}".format(exepath, globals.PROJECT_NAME)], cwd=exepath)