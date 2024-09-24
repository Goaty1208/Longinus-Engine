/*******************************************************************************************
*
*   sprites.hpp   
*   Texture references (Evangelion reference?!) with position information associated with it.
*
*******************************************************************************************/

#pragma once

#include "raylib.h"
#include "assets.hpp"
#include "render.hpp"

#include <vector>
#include <functional>

namespace LonginusSprites {
    
    struct Sprite2D {
        u_int8_t ID;
        LonginusAssets::TextureAsset& Texture;
        /*Since 2D textures are, well, 2D it's not stupid to assume that
          their position on screen will ALSO be 2D.*/
        Vector2 Position;

        /*Not that the program would run with zero assets anyways*/
        Sprite2D(int ID, int TextureID, Vector2 position) :Texture(LonginusAssets::CurrentGameTextures[0]), Position({.0f,.0f}), ID(Texture.InternalID){
            this->Texture = LonginusAssets::CurrentGameTextures[TextureID];
            this->Position = position;
            this->ID = ID;
        };
    };

    extern uint SpriteCounter;
    extern Sprite2D* Sprites;
    extern std::vector<Sprite2D> SpriteQueue;

    void CreateSprite(Sprite2D Sprite);

} // namespace LonginusSprites
