//
// Created by smeek on 14/03/2021.
//
#include "raylib.h"
#include "screens\screens.h"
#include <stdlib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif


const int screenWidth = 1920;
const int screenHeight = 1080;
void UpdateFrame(void); //updates frame on screen
static void currentScreen();
static void rlInitLogoScreen();
static void InitDevScreen ();
static void DrawDevScreen ();
static void UpdateFrame ();
static void rlUpdateLogoScreen ();
static void rlFinishLogoScreen ();

int main(void)
{
    InitWindow(screenWidth, screenHeight, "silver rod 21.1");

    currentScreen = RL_LOGO;
    rlInitLogoScreen();
    InitDevScreen();

    SetTargetFPS(60);

    while (!WindowShouldClose()){
        UpdateFrame();
    }
}

void ChangeScreen(int screen) {
    switch (currentScreen) {
        case RL_LOGO: rlUnloadLogoScreen();
        case DEV_WARNING: UnloadDevScreen();
    }
    switch (screen) {
        case RL_LOGO: rlInitLogoScreen();
        case DEV_WARNING: DrawDevScreen();
    }
    currentScreen = screen;
}

void UpdateFrame(void){
    switch(currentScreen) {
        case RL_LOGO: {
            rlUpdateLogoScreen();
            if (rlFinishLogoScreen()) ChangeScreen(DEV_WARNING);
        }
    }
}