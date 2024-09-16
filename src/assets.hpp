/*******************************************************************************************
*
*   assets.hpp   
*
*******************************************************************************************/

#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "raylib.h"
#include <vector>

namespace LonginusAssets {
    
    /*Texture asset. Will the InternalID actually have a purpose? I don't know, probably, I'd guess.*/
    typedef struct {
        const char* Name;
        const int InternalID;
        Texture2D Texture;
    } TextureAsset;
    
    int TextureAssetCounter = 0;
    std::vector<LonginusAssets::TextureAsset> CurrentGameTextures;

    bool AddAsset(const char* fileName);
    void LoadAllAssets();

} // namespace LonginusAssets


#endif