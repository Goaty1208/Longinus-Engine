/*******************************************************************************************
*
*   render.hpp   
*   Stuff related to rendering (ex.: rendering queue)
*
*******************************************************************************************/
#pragma once

#include "raylib.h"

#include <vector>

namespace LonginusRender {

    std::vector<Texture2D> TextureQueue;
    std::vector<Mesh> TextureQueue;
    
} // namespace LonginusRender
