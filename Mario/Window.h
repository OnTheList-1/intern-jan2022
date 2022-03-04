#pragma once

//Singleton implemnentation for the window ?

class Window
{
public:
    static Window* getInstance()
    {
        if (!instance)
            instance = new Window;

        return instance;
    }

    SDL_Window* getWindow();
    SDL_Surface* getSurface();
    void destroyWindow();
    void initializeWindow();
    void run();

private:
    static Window* instance;
    SDL_Window* window;
    SDL_Surface* background;
    Window()
    {
        window = nullptr;
        background = nullptr;
    }
};

Window* Window::instance = 0;

SDL_Window* Window::getWindow()
{
    return this->window;
}

SDL_Surface* Window::getSurface()
{
    return this->background;
}

void Window::destroyWindow()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Window::initializeWindow()
{
    SDL_Init(SDL_INIT_VIDEO);

    if (SDL_INIT_VIDEO == 0)
    {
        std::cout << "Failed to initialize window: " << SDL_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow("Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    this->run();
}

void Window::run()
{
    SDL_Event ev;
    bool isRunning = true;
    while (isRunning)
    {
        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
            {
                isRunning = false;
                SDL_Log("Requesting to quit.");
            }
        }
        SDL_UpdateWindowSurface(this->window);
    }
    SDL_Log("Request Granted.");
    SDL_DestroyWindow(this->window);
}