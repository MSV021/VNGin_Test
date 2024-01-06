#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Bullet.hpp"

#include <VNGin/VNGin.h> 

using namespace VNGin;

class PlayerController : public Module {
public: 
    PlayerController(Entity* owner, float speed) : Module(owner), speed{speed}, shotEffect("media/shot.wav") {}
    
    void Update() {
        // MOVEMENT
        if(InputSystem::GetKey(SDL_SCANCODE_DOWN)) 
            owner->transform->Move(Vector::down * speed);
        if(InputSystem::GetKey(SDL_SCANCODE_UP)) 
            owner->transform->Move(Vector::up * speed); 
        if(InputSystem::GetKey(SDL_SCANCODE_RIGHT)) 
            owner->transform->Move(Vector::right * speed); 
        if(InputSystem::GetKey(SDL_SCANCODE_LEFT)) 
            owner->transform->Move(Vector::left * speed);

        // SHOOTING
        if(InputSystem::GetKeyDown(SDL_SCANCODE_SPACE)) {
            Entity* bullet = new Entity(Game::GetActiveScene(), "Bullet", owner->transform->GetPosition(), 0, Vector::one * 0.1f);
            bullet->AddModule<TextureRenderer>("media/bullet.png");
            bullet->AddModule<Bullet>(10);

            shotEffect.Play();
        }
    }

    const char* GetType() { return "PlayerController"; }
private: 
    float speed;
    AudioClip shotEffect;
}; 

#endif