#include "PlayerController.hpp"
#include <VNGin/VNGin.h> 

using namespace VNGin;

Entity* player; 

int main(int argc, char** argv) {
    Game::New("Test", true, 1280, 720, ColorRGBA::black);
    player = new Entity(
        Game::GetActiveScene(), std::string("Player"), {200, 200}, 90, Vector::one * 0.5);

    player->AddModule<TextureRenderer>("media/player.png", 1);
    player->AddModule<PlayerController>(5.0f);

    Game::Run(60);
}