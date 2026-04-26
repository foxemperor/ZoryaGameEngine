import subprocess, sys, os

if sys.platform == "win32":
    premake = os.path.join("premake", "premake5.exe")
elif sys.platform == "darwin":
    premake = os.path.join("premake", "premake5")
else:
    premake = os.path.join("premake", "premake5.linux")

# Определяем действие: можно передать аргумент, например cli.bat gensln vs2019
# По умолчанию — vs2022 (самое широкое покрытие, VS 2026 умеет обновить toolset)
vs_target = sys.argv[1] if len(sys.argv) > 1 else "vs2022"

print(f"[gensln] Generating project files for {vs_target}...")
subprocess.call([premake, vs_target])
