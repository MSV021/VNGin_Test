#ifndef BULLET_H
#define BULLET_H

#include <VNGin/VNGin.h> 

using namespace VNGin;

class Bullet : public Module {
public: 
    Bullet(Entity* owner, float speed) : Module(owner), speed{speed} {} 

    void Update() {
        owner->transform->Move(Vector::right * speed);
        if(owner->transform->GetPosition().x > static_cast<double>(Game::ScreenWidth())) 
            owner->Destroy();
    }

    void Destroy() {}

    const char* GetType() { return "Bullet"; }
private: 
    float speed; 
};

#endif 