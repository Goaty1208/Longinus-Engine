/*******************************************************************************************
*
*   Longinus Engine
*   3D Quake-like engine
*
*   This engine has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*   
*   Example application of this weird and shit engine.
*
********************************************************************************************/

#include "assets.hpp"
#include <iostream>

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main() {

    LonginusWindow::Init(500, 500, "test");

    LonginusSprites::CreateSprite(0 , {250, 250});

    while (!WindowShouldClose()) {
        LonginusWindow::ProcessFrame();
    }

    LonginusWindow::Close();
        
    return 0;
}