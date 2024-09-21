/*******************************************************************************************
*
*   sprites.hpp   
*   Texture references (Evangelion reference?!) with position information associated with it.
*
*******************************************************************************************/

#pragma once

#include "assets.hpp"
#include "raylib.h"

namespace LonginusSprites {
    
    struct Sprite2D {
        LonginusAssets::TextureAsset& Texture;
        /*Since 2D textures are, well, 2D it's not stupid to assume that
          their position on screen will ALSO be 2D.*/
        Vector2 Position;

        /*Not that the program would run with zero assets anyways*/
        Sprite2D() :Texture(LonginusAssets::CurrentGameTextures[0]), Position({.0f,.0f}){};
    };

} // namespace LonginusSprites
