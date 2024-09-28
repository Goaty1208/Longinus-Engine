/*******************************************************************************************
*
*   window.hpp
*   Not entirely sure what this will do, but as of now it manages windows. Hopefully.
*   
*   Ok, it also starts audio, but that will likely be someone else's responsibility eventually.
*
*******************************************************************************************/

#pragma once

#include "raylib.h"
#include "render.hpp"

#include <string>

/*namespace LonginusWindow*/ 
namespace LonginusWindow {

    /*Is only one camera a limitation? Yes. Will it change? Who the fuck knows.*/
    extern Camera3D Viewport;

    /*Spelling is in British English. */
    extern Color VoidColour;

    /*Current working directory. Fundamental.*/
    extern std::string CurrentDir;

    /*Opens a Raylib window, inits sound, gets current directory.*/
    bool Init(int width, int height, const char* title);
    bool ProcessFrame();
    void Close();
}