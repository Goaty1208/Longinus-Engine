/*******************************************************************************************
*
*   render.cpp   
*   Stuff related to rendering (ex.: rendering queue)
*
*******************************************************************************************/
#include "render.hpp"

Color LonginusRender::CurrentTint = WHITE;

void LonginusRender::RenderSpriteQueue(){

    for (size_t i = 0; i < LonginusRender::TextureQueue.size() ; i++) {
        
        DrawTexture(LonginusSprites::SpriteQueue[i].Texture.Texture, LonginusSprites::SpriteQueue[i].Position.x, LonginusSprites::SpriteQueue[i].Position.y, LonginusRender::CurrentTint);
    }

}