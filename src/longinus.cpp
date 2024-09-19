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

    LonginusAssets::ParseAssetFiles();
    LonginusAssets::LoadAssets();
    std::cout << "Textures loaded: " << LonginusAssets::CurrentGameTextures.size() << std::endl;

    while (!WindowShouldClose()) {
        LonginusWindow::ProcessFrame();
    }
    
    return 0;
}