/*******************************************************************************************
*
*   sprites.cpp   
*   boring
*
*******************************************************************************************/
#include "sprites.hpp"

uint LonginusSprites::SpriteCounter = 0;

void LonginusSprites::CreateSprite(int ID, Vector2 position) {

    LonginusSprites::Sprites[LonginusSprites::SpriteCounter] = {LonginusSprites::SpriteCounter, ID, position};
    LonginusSprites::SpriteCounter++;
}