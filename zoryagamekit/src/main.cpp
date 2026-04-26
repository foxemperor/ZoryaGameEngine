#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }

    // Запрашиваем OpenGL 4.1 Core Profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_Window* window = SDL_CreateWindow(
        "Zorya Game Engine",
        800, 600,
        SDL_WINDOW_OPENGL
    );

    if (!window)
    {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext)
    {
        SDL_Log("SDL_GL_CreateContext failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Загружаем все OpenGL-функции через GLAD
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
    {
        SDL_Log("gladLoadGLLoader failed");
        SDL_GL_DestroyContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Log("OpenGL %s | %s",
        reinterpret_cast<const char*>(glGetString(GL_VERSION)),
        reinterpret_cast<const char*>(glGetString(GL_RENDERER)));

    // Устанавливаем viewport под размер окна
    glViewport(0, 0, 800, 600);

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        // Очищаем экран тёмно-синим
        glClearColor(0.08f, 0.10f, 0.18f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Показываем готовый кадр
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
