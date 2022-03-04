#pragma once

#include <SDL.h>
#include <SDL->
#include <string>

class Entity
{
public:
    Entity(SDL_Renderer* renderTarget, std::string filePath, int x, int y, int frameX, int frameY);
    ~Entity();

    void Update(float delta, const Uint8* keyState);
    void Draw(SDL_Renderer* renderTarget);

private:
    SDL_Rect colRect;
    float moveSpeed;
    float frameCounter;
    int frameWidth;
    int frameHeight;
    int textureWidth;
    bool isActive;
    SDL_Scancode keys[4];
};