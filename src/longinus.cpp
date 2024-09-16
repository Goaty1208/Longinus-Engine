/*******************************************************************************************
*
*   raylib game template
*
*   Longinus Engine
*   3D Quake-like engine
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*   
*   Example application of this weird and shit engine.
*
********************************************************************************************/

#include "window.hpp"
#include <iostream>

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main() {

    LonginusWindow::Init(800, 800, "Hello!");

    while (!WindowShouldClose()) {
        LonginusWindow::ProcessFrame();
    }
    

    return 0;
}