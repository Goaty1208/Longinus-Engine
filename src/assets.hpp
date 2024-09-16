/*******************************************************************************************
*
*   assets.hpp   
*
*******************************************************************************************/

#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "raylib.h"
#include <map>

namespace LonginusAssets {
    
    /*Texture asset. InternalID is what determines the loading order.*/
    struct TextureAsset {
        const char* Name;
        const int InternalID;
        Texture2D Texture;

        bool operator>(const LonginusAssets::TextureAsset& asset) {
            return this->InternalID > asset.InternalID;
        }
    };
    
    static int TextureAssetCounter = 0;
    static std::map<LonginusAssets::TextureAsset, int> CurrentGameTextures;

    bool AddAsset(const char* fileName);
    void LoadAssetTextures();

} // namespace LonginusAssets


#endif