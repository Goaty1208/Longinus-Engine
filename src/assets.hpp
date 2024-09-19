/*******************************************************************************************
*
*   assets.hpp   
*
*******************************************************************************************/

#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "raylib.h"
#include "window.hpp"

#include <map>
#include <iostream>
#include <fstream>
#include <string>

namespace LonginusAssets {
    
    /*Texture asset. InternalID is what determines the loading order.*/
    struct TextureAsset {
        std::string Name;
        int InternalID;
        Texture2D Texture;
        
        bool operator<(const LonginusAssets::TextureAsset& asset) const {
            return this->InternalID < asset.InternalID;
        }

        bool operator>(const LonginusAssets::TextureAsset& asset) {
            return this->InternalID > asset.InternalID;
        }

        TextureAsset(std::string name) : InternalID(0) {
            this->Name = name;
        }
    };
    
    /*TEXTURE ASSETS------------*/
    extern std::fstream TextureDotA;
    extern int TextureAssetCounter;
    static std::map<LonginusAssets::TextureAsset, int> CurrentGameTextures;
    bool AddAsset(LonginusAssets::TextureAsset asset);
    /*--------------------------*/

    void ParseAssetFiles();

    void LoadAssets();
} // namespace LonginusAssets


#endif