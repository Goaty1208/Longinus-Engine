/*******************************************************************************************
*
*   assets.hpp   
*
*******************************************************************************************/
#pragma once

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

        // Default constructor
        TextureAsset() : InternalID(0), Name("INVALID"), Texture() {}

        // Constructor with name argument
        TextureAsset(std::string name) : InternalID(0), Name(name), Texture() {}
    
    };
    
    /*TEXTURE ASSETS------------*/
    extern std::fstream TextureDotA;
    extern int TextureAssetCounter;
    extern std::map<int, LonginusAssets::TextureAsset> CurrentGameTextures;
    bool AddAsset(LonginusAssets::TextureAsset asset);
    /*--------------------------*/

    void ParseAssetFiles();

    void LoadAssets();
    void UnloadAssets();
} // namespace LonginusAssets