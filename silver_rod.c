//
// Created by smeek on 14/03/2021.
//

#include "include/raylib.h"
#include "screens/screens.h"
#include <stdlib.h>

GameScreen currentScreen = 0;
//global
const int screenWidth = 1920;
const int screenHeight = 1080;

//local
static void ChangeScreen(int screen);
static void UpdateFrame(void); //updates frame on screen
static bool onTransition = false;


//game loop
int main(void) {
    InitWindow(screenWidth, screenHeight, "silver rod 21.1");

    currentScreen = RL_LOGO;
    rlInitLogoScreen();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateFrame();
    }
}

static void ChangeScreen (int screen){
    switch (currentScreen) {
        case RL_LOGO: rlUnloadLogoScreen(); break;
        case DEV_WARNING: UnloadDevScreen(); break;
        default: break;
    }
    switch (screen) {
        case RL_LOGO: rlInitLogoScreen(); break;
        case DEV_WARNING: InitDevScreen(); break;
        default: break;
    }
    currentScreen = screen;
}

static void UpdateFrame(void) {
    if (!onTransition) {
        switch (currentScreen) {
            case RL_LOGO: {
                rlUpdateLogoScreen();
                if (rlFinishLogoScreen()) ChangeScreen(DEV_WARNING);
                default: break;
            }
            case DEV_WARNING: {
                UpdateDevScreen();
            } break;
        }
    }
}

