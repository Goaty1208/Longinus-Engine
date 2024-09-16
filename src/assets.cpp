/*******************************************************************************************
*
*   assets.cpp   
*
*******************************************************************************************/

#include "assets.hpp"

LonginusAssets::TextureAsset test = {"resources/test.png"};

/*Adds Texture2D to texture map, increases texture counter.
  Unlike a shitty ol' vector, the amazing map allows us to use a cool ass ID which I'd guess is better as assets load in a better way.
  I'd assume, at least.
  
  But hey, it is quite efficient
*/

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