#include "Window.h"


Window::Window(const std::string& windowName, const int width, const int height)
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL Initialized\n";
    }

    m_Window = SDL_CreateWindow("CmakeGameDev", 1000, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY );

    m_Context = SDL_GL_CreateContext(m_Window);

    if (m_Context)
    {
        std::cout << "SDL successfully created an OpenGL Context.\n";
    }

    // Load OpenGL functions, gladLoadGL returns the loaded version, 0 on error.
    const auto version = gladLoadGL(SDL_GL_GetProcAddress);
    if (version == 0)
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;

    }

    // Successfully loaded OpenGL
    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;


    if (SDL_GL_SetSwapInterval(1) < 0)
    {
        std::cout << "Warning: Unable to set VSync! SDL Error: \n" << SDL_GetError() << std::endl;
    }
}

void Window::Events()
{
    
    while (SDL_PollEvent(&m_Event))
    {
        if (m_Event.type == SDL_EVENT_QUIT)
        {
            m_Run = false;
            break;
        }
        
    }


}

void Window::ReSize()
{
    int width, height;
    SDL_GetWindowSize(m_Window, &width, &height);
    glViewport(0, 0, width, height);
}

