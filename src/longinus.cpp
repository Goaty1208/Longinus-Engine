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

    LonginusWindow::Init(0, 0, "test");

    LonginusAssets::AddAsset({"jim0.png"});
    LonginusAssets::AddAsset({"jim1.png"});
    LonginusAssets::AddAsset({"jim2.png"});
    LonginusAssets::AddAsset({"jim3.png"});
    LonginusAssets::AddAsset({"jim4.png"});
    LonginusAssets::AddAsset({"jim5.png"});

    LonginusAssets::LoadAssetTextures();

    return 0;
}