#include "base/app.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstdio>

int main(int argc, char *argv[])
{
    // Setup SDL
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return -1;
    }

    constexpr Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    SDL_Window *window = SDL_CreateWindow("SDL3", 1280, 720, window_flags);
    if (window == nullptr)
    {
        SDL_Log("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return -1;
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(window);


    // Main loop
    bool done = false;

    while (!done)
    {
         SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                done = true;
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
            SDL_Delay(10);
            continue;
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
