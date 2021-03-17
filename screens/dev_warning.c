//
// Created by smeek on 14/03/2021.
//

#include "../include/raylib.h"

static int framesCounter;
static int finishScreen;
static float alpha = 1.0f;

void InitDevScreen(void){
    framesCounter = 0;
    finishScreen = 0;
}

void UpdateDevScreen(void){
    if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        finishScreen = 1;
    }
}

void DrawDevScreen () {
    DrawRectangle(0, 0, 1920, 1080, Fade(PINK, alpha));
    DrawText("WARNING: this is a developmental build.",GetScreenWidth()/8, GetScreenHeight()/2, 70, Fade(WHITE, alpha));
}

void UnloadDevScreen(void){

}

int FinishDevScreen(void){
    return finishScreen;
}