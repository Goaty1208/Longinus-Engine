/*******************************************************************************************
*
*   window.cpp
*   Not entirely sure what this will do, but as of now it manages windows. Hopefully.
*   Implements the header. Of course.
*
*******************************************************************************************/

#include "window.hpp"

Camera3D LonginusWindow::Viewport = {0};

Color LonginusWindow::VoidColour = BLACK;
Texture2D LonginusWindow::nano;
std::string LonginusWindow::CurrentDir;

bool LonginusWindow::Init(int width, int height, const char* title) {

    InitWindow(width, height, title);
    InitAudioDevice();

    std::string CurrentDir = GetWorkingDirectory();

    if(DirectoryExists(CurrentDir.c_str()))
        LonginusWindow::CurrentDir = CurrentDir; 

    return IsWindowReady();    

}

bool LonginusWindow::ProcessFrame() {

    /*Rendering starts here. Draw UI and other crap here. Or else shit will break unimmaginably.*/
    BeginDrawing();
    ClearBackground(LonginusWindow::VoidColour);
    
    DrawTexture(LonginusAssets::CurrentGameTextures[0].Texture, 0, 0, WHITE);

    /*Rendering of 3D objects starts here. Draw 3D stuff here. Or else, you can guess what will happen.*/
    BeginMode3D(LonginusWindow::Viewport);

    /*Rendering stops here. It draws over empty space with .*/
    EndMode3D();
    EndDrawing();

    return true;
}