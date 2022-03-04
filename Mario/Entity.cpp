#include "Entity.h"

Entity::Entity(SDL_Renderer* renderTarget, std::string filePath, int x, int y, int frameX, int frameY)
{
    SDL_Surface* surface = IMG_Load(filePath.c_str());
}

Entity::~Entity()
{

}

void Entity::Update(float delta, const Uint8* keyState)
{

}
void Entity::Draw(SDL_Renderer* renderTarget)
{

}