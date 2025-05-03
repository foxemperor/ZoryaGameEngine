# Интерфейс CLI для работы с терминалом

import os, sys
import subprocess

TOOL_DIR = "toolkit"

# Поиск файлов для работы CLI через парсирование
def RunCommand(cmd):
    error_return = 0
    script_path = "{}/{}/{}.py".format(os.getcwd(), TOOL_DIR, cmd)
    if os.path.exists(script_path):
        print("Executing command:", cmd)
        error_return = subprocess.call(["python3", script_path])
    else:
        print("Command not found", "(" + cmd + ")")
        error_return = -1
    
    return error_return

# Лейбл CLI игрового движка
print("----------------------------")
print("| Zorya Engine CLI ToolKit |")
print("----------------------------\n")

# Выполнение команды в CLI
for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]

    if RunCommand(cmd) != 0:
       break

print("\n")
