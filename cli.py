# Интерфейс CLI для работы с терминалом

import os, sys
import subprocess

TOOL_DIR = "toolkit"

# Поиск файлов для работы CLI через парсирование
def RunCommand(cmd):
    subprocess.call(["python3", "{}/{}/{}.py".format(os.getcwd(), TOOL_DIR, cmd)])

print("\n--------------------------------------------------------")

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]

    RunCommand(cmd)
