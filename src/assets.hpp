/*******************************************************************************************
*
*   assets.hpp   
*
*******************************************************************************************/

#ifndef ASSETS_HPP
#define ASSETS_HPP

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
    };
    
    extern int TextureAssetCounter;
    static std::map<LonginusAssets::TextureAsset, int> CurrentGameTextures;

    bool AddAsset(LonginusAssets::TextureAsset asset);
    void LoadAssetTextures();

} // namespace LonginusAssets


#endif