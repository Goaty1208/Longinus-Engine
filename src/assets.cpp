/*******************************************************************************************
*
*   assets.cpp   
*
*******************************************************************************************/

#include "assets.hpp"

LonginusAssets::TextureAsset test = {"resources/test.png"};

/*Adds Texture2D to texture list, increases texture counter.*/
bool LonginusAssets::AddAsset(const char* fileName) {

    LonginusAssets::CurrentGameTextures.push_back({fileName, LonginusAssets::TextureAssetCounter, 0});
    LonginusAssets::TextureAssetCounter++;
    
    return true;
}