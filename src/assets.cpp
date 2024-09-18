/*******************************************************************************************
*
*   assets.cpp   
*
*******************************************************************************************/

#include "assets.hpp"

#include "raylib.h"
#include "window.hpp"

#include <map>
#include <string>
#include <iostream>
#include <fstream>

int LonginusAssets::TextureAssetCounter = 0;

/*Adds Texture2D to texture map, increases texture counter.
  Unlike a shitty ol' vector, the amazing map allows us to use a cool ass ID which I'd guess is better as assets load in a better way.
  I'd assume, at least.
  
  But hey, it is quite efficient
*/
bool LonginusAssets::AddAsset(LonginusAssets::TextureAsset asset) {

  asset.InternalID = LonginusAssets::TextureAssetCounter;

  LonginusAssets::CurrentGameTextures[asset] = LonginusAssets::TextureAssetCounter;
  LonginusAssets::TextureAssetCounter++;

  return true;
}

/*Loads all textures for assets found in CurrentGameTextures.*/
void LonginusAssets::LoadAssetTextures() {

    std::string directory;

    auto it = LonginusAssets::CurrentGameTextures.begin();

    while(it != LonginusAssets::CurrentGameTextures.end()){    

      if (it->first.Name.empty()) {
        std::cerr << "Error: TextureAsset" << it->first.InternalID << "Name is null!" << std::endl;
        it++;
        continue;  // Skip this entry if the name is null
      }

      if (LonginusWindow::CurrentDir == nullptr) {
        std::cerr << "Error: LonginusWindow::CurrentDir is null!" << std::endl;
        return;  // Or handle the error appropriately
      }

      std::string fileLocationit(it->first.Name);
      fileLocationit.insert(0, "");
      fileLocationit.insert(0, LonginusWindow::CurrentDir);

      std::cout << fileLocationit << "\n";

      it++;
    }

} 