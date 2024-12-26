#pragma once 
#include <GLAD/gl.h>
#include <SDL3/SDL.h>

#include <iostream>
#include <string>

class Window
{
public:
    Window() = default;

    Window(const std::string& windowName,const int width,const int height );

    void Events();
    void ReSize();

    inline SDL_Window* GetWindow() { return m_Window; }
    inline bool GetRun() { return m_Run; }

private:
    SDL_Event m_Event;

    SDL_Window* m_Window;

    SDL_GLContext m_Context;

    bool m_Run = true;


};