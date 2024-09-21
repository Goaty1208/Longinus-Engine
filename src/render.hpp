/*******************************************************************************************
*
*   render.hpp   
*   Stuff related to rendering (ex.: rendering queue)
*
*******************************************************************************************/
#pragma once

#include "raylib.h"
#include "sprites.hpp"

namespace LonginusRender {

    extern std::vector<Mesh> TextureQueue;

    extern Color CurrentTint;

    void RenderSpriteQueue();

} // namespace LonginusRender
