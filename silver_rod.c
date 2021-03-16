//
// Created by smeek on 14/03/2021.
//

#include "include/raylib.h"
#include "screens/screens.h"
#include <stdlib.h>

GameScreen currentScreen = 0;

const int screenWidth = 1920;
const int screenHeight = 1080;

//screen transitions!
static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static int transToScreen = -1;

static void UpdateScreen();

static void DrawTransition();

int main(void)
{

//game params
    InitWindow(screenWidth, screenHeight, "silver rod 21.1");
    SetTargetFPS(60);

//run through opening sequence
    rlInitLogoScreen();
    InitDevScreen();

    while (!WindowShouldClose()){
        UpdateScreen(); //TODO update to a better command so work with more than just the opening sequence lolz
    }
}

//fade transition to next screen
static void TransitionScreen(int screen){
    onTransition = true;
    transFadeOut = false;
    transFromScreen = currentScreen;
    transToScreen = screen;
    transAlpha = 0.0f;
}
//rectangle transition effect
static void DrawTransition() {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
}

void ChangeScreen(int screen) {
    //unload screen first
    switch (currentScreen) {
        case RL_LOGO: rlUnloadLogoScreen(); break;
        case DEV_WARNING: UnloadDevScreen(); break;
        default: break;
    }
    //switch to next screen
    switch (screen) {
        case RL_LOGO: rlInitLogoScreen(); break;
        case DEV_WARNING: DrawDevScreen(); break;
        default: break;
    }
    currentScreen = screen;
}

static void UpdateScreen(void) {
    if (!onTransition) {
        switch (currentScreen) {
            case RL_LOGO: {
                rlUpdateLogoScreen();
                if (rlFinishLogoScreen()) TransitionScreen(DEV_WARNING);
            }
                break;
        }
    }

BeginDrawing();
    ClearBackground(RAYWHITE);

    switch(currentScreen){
        case RL_LOGO: rlDrawLogoScreen(); break;
        case DEV_WARNING: DrawDevScreen(); break;
        default: break;
    }
    if (onTransition) DrawTransition();
    EndDrawing();
}

