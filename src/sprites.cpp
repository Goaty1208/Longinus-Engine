/*******************************************************************************************
*
*   sprites.cpp   
*   boring
*
*******************************************************************************************/
#include "sprites.hpp"

int LonginusSprites::SpriteCounter = 0;

void LonginusSprites::CreateSprite(int ID, Vector2 position) {

    LonginusSprites::Sprites[LonginusSprites::SpriteCounter] = LonginusSprites::Sprite2D(LonginusSprites::SpriteCounter, ID, position);
    LonginusSprites::SpriteCounter++;
}