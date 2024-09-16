/*******************************************************************************************
*
*   assets.cpp   
*
*******************************************************************************************/

#include "assets.hpp"

LonginusAssets::TextureAsset test = {"resources/test.png"};

/*Adds Texture2D to texture list, increases texture counter.*/
bool LonginusAssets::AddAsset(LonginusAssets::TextureAsset asset) {

    LonginusAssets::CurrentGameTextures[asset] = LonginusAssets::TextureAssetCounter;
    LonginusAssets::TextureAssetCounter++;
    
    return true;
}

/*Loads all textures for assets found in CurrentGameTextures.*/
void LonginusAssets::LoadAssetTextures() {

    for(size_t i; i < LonginusAssets::TextureAssetCounter; i++){
        
    }

} 