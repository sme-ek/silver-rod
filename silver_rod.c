//
// Created by smeek on 14/03/2021.
//

#include "include/raylib.h"
#include "screens/screens.h"
#include <stdlib.h>

GameScreen currentScreen = 0;

const int screenWidth = 1920;
const int screenHeight = 1080;
bool PlayerCharacter;
//screen transitions!
static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static int transToScreen = -1;
static Music music;
static void UpdateScreen();

static void DrawTransition();

int main(void)
{
//game params & global data loading
    InitWindow(screenWidth, screenHeight, "silver rod 21.1");
    SetTargetFPS(60);
    InitAudioDevice();
    music = LoadMusicStream("resources/audio/time machine.wav"); //TODO figure out why this isn't loading in lol
    SetMusicVolume(music, 1.0f);
    PlayMusicStream(music);

//initiate all screens
    rlInitLogoScreen();
    InitDevScreen();
    InitCharacterScreen();

    while (!WindowShouldClose()){

        UpdateScreen();
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
        case CHARACTER_SELECT: UnloadCharacterScreen(); break;
        case FEM_CONFIRM: UnloadFemScreen(); break;
        case MASC_CONFIRM: UnloadMascScreen(); break;
        default: break;
    }
//switch to next screen
    switch (screen) {
        case RL_LOGO: rlInitLogoScreen(); break;
        case DEV_WARNING: DrawDevScreen(); break;
        case CHARACTER_SELECT: DrawCharacterScreen(); break;
        case FEM_CONFIRM: DrawFemScreen(); break;
        case MASC_CONFIRM: DrawMascScreen(); break;
        default: break;
    }
    currentScreen = screen;
}

void upTransition(void){
    if (!transFadeOut){
        transAlpha  += 0.05f;
        if (transAlpha >= 1.0){
            transAlpha = 1.0;
            switch (transFromScreen){
                case RL_LOGO: rlUnloadLogoScreen(); break;
                case DEV_WARNING: UnloadDevScreen(); break;
                case CHARACTER_SELECT: UnloadCharacterScreen(); break;
                case FEM_CONFIRM: UnloadFemScreen(); break;
                case MASC_CONFIRM: UnloadMascScreen(); break;
                default: break;
            }
            switch (transToScreen){
                case RL_LOGO:{
                    rlInitLogoScreen();
                    currentScreen = RL_LOGO;
                } break;
                case DEV_WARNING:{
                    InitDevScreen();
                    currentScreen = DEV_WARNING;
                } break;
                case CHARACTER_SELECT:{
                    InitCharacterScreen();
                    currentScreen = CHARACTER_SELECT;
                }
                case FEM_CONFIRM:{
                    InitFemScreen();
                    currentScreen = FEM_CONFIRM;
                } break;
                case MASC_CONFIRM:{
                    InitMascScreen();
                    currentScreen = MASC_CONFIRM;
                } break;
                default: break;
            }
            transFadeOut = true;
        }
    }
    else {
        transAlpha  -= 0.05f;
        if (transAlpha <= 0){
            transAlpha = 0;
            transFadeOut = false;
            onTransition = false;
            transFromScreen = -1;
            transToScreen = -1;
        }
    }
}

static void UpdateScreen(void) {
    if (!onTransition) {
        switch (currentScreen) {
            case RL_LOGO: {
                rlUpdateLogoScreen();
                if (rlFinishLogoScreen()) TransitionScreen(DEV_WARNING);
            } break;
            case DEV_WARNING: {
                UpdateDevScreen();
                if (FinishDevScreen() == 1) TransitionScreen(CHARACTER_SELECT);
            } break;
            case CHARACTER_SELECT: {
                UpdateCharacterScreen();
                if (SelectedPlayer() == 1) TransitionScreen(FEM_CONFIRM);
                if (SelectedPlayer() != 1) TransitionScreen(MASC_CONFIRM);
            } break;
            case FEM_CONFIRM: {
                UpdateFemScreen();
                if (FinishFemScreen() == 1) TransitionScreen(RL_LOGO);
            } break;
            case MASC_CONFIRM: {
                UpdateMascScreen();
                if (FinishMascScreen() == 1) TransitionScreen(RL_LOGO);
            } break;
            default: break;
        }
    }
    else{
        upTransition();
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch(currentScreen){
        case RL_LOGO: rlDrawLogoScreen(); break;
        case DEV_WARNING: DrawDevScreen(); break;
        case CHARACTER_SELECT: DrawCharacterScreen(); break;
        case FEM_CONFIRM: DrawFemScreen(); break;
        case MASC_CONFIRM: DrawMascScreen(); break;
        default: break;
    }
    if (onTransition) DrawTransition();
    EndDrawing();
}

