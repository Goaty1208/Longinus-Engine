/*******************************************************************************************
*
*   assets.cpp   
*
*******************************************************************************************/

#include "assets.hpp"

int LonginusAssets::TextureAssetCounter = 0;

void LonginusAssets::ParseAssetFiles() {

    const std::string AssetFileLocation = LonginusWindow::CurrentDir + "/resources/";

    std::string CurrentFile;

    std::fstream CurrentAssetFile;
    
    /*Due to reasons that I honestly do not want to explain we have to use an if statement for each filetype
      instead of using a switch. Does it suck? Yeah. Does it work? I mean, I guess?
      Will fix later.*/
    
    /*Textures*/
    CurrentFile = AssetFileLocation + "textures/textures.a";
    if(FileExists(CurrentFile.c_str())) {
        CurrentAssetFile.open(CurrentFile);

        for(std::string CurrentToken; std::getline(CurrentAssetFile, CurrentToken);) {
            LonginusAssets::AddAsset({AssetFileLocation + "textures/" + CurrentToken});
        }
    } else {
        std::cerr << "Couldn't load texture asset file!" << std::endl;
    }
}


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
void LonginusAssets::LoadAssets() {

    auto it = LonginusAssets::CurrentGameTextures.begin();

    while(it != LonginusAssets::CurrentGameTextures.end()){    

      if (it->first.Name.empty()) {
        std::cerr << "Error: TextureAsset" << it->first.InternalID << "Name is null!" << std::endl;
        it++;
        continue;  // Skip this entry if the name is null
      }

      if (LonginusWindow::CurrentDir.empty()) {
        std::cerr << "Error: LonginusWindow::CurrentDir is null!" << std::endl;
        return;  // Or handle the error appropriately
      }

      std::string fileLocationit(it->first.Name);
      fileLocationit.insert(0, "/textures/");
      fileLocationit.insert(0, LonginusWindow::CurrentDir);

      std::cout << fileLocationit << "\n";

      it++;
    }

} 