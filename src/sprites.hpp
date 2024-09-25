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
#include <map>

namespace LonginusSprites {
    
    struct Sprite2D {
        int ID;
        LonginusAssets::TextureAsset Texture;
        /*Since 2D textures are, well, 2D it's not stupid to assume that
          their position on screen will ALSO be 2D.*/
        Vector2 Position;

        /*Not that the program would run with zero assets anyways*/
        Sprite2D(int ID, int TextureID, Vector2 position) : ID(ID), Texture(LonginusAssets::CurrentGameTextures[TextureID]), Position(position){};
        Sprite2D() : ID(0), Texture(LonginusAssets::CurrentGameTextures[0]), Position({0, 0}) {};
    };

    extern int SpriteCounter;
    extern std::map<int, Sprite2D> Sprites;
    extern std::vector<Sprite2D> SpriteQueue;

    void CreateSprite(int ID, Vector2 position);

} // namespace LonginusSprites
