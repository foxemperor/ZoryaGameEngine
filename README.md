# ZoryaGameEngine

Видеоигровой движок Зоря (Zorya Game Engine) — движок на C++20 с использованием SDL3 и OpenGL, собираемый через Premake5.

## Зависимости

- [Premake5 beta8](https://premake.github.io/download/) — уже включён в `premake/`
- [SDL3](https://github.com/libsdl-org/SDL/releases) — уже включён в `vendor/SDL3/`

## Быстрый старт (Windows)

```bat
# Генерация .sln для Visual Studio 2022
python cli.py gensln
```

После этого открой `zorya.sln` в Visual Studio 2022 и нажми **F5**.

## Структура проекта

```
ZoryaGameEngine/
├── premake/          # Бинарники Premake5 (win/linux/mac)
├── toolkit/          # Python-скрипты CLI
├── vendor/
│   └── SDL3/         # SDL3 include + lib
├── zoryagamekit/
│   ├── include/      # Заголовочные файлы движка
│   └── src/
│       └── main.cpp  # Точка входа
├── cli.py            # CLI точка входа
├── cli.bat           # Запуск CLI на Windows
├── cli.sh            # Запуск CLI на Linux/macOS
└── premake5.lua      # Конфигурация сборки
```
