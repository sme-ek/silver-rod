//
// Created by smeek on 18/03/2021.
//

#include "../include/raylib.h"

static int framesCounter;
static int finishScreen;
static float alpha = 1.0f;
bool selectedPlayer;

void InitFemScreen(void){
    framesCounter = 0;
    finishScreen = 0;
}

void UpdateFemScreen(void){

}

void DrawFemScreen(void) {
    DrawRectangle(0, 0, 1920, 1080, Fade(PINK, alpha));
    DrawText("You have selected [fem]. Is this correct?", GetScreenWidth()/8, GetScreenHeight()/2, 50, Fade(WHITE, alpha));
}

void UnloadFemScreen(void){

}

int FinishFemScreen(void){
    return finishScreen;
}