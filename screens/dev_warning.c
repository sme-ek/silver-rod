//
// Created by smeek on 14/03/2021.
//

#include "C:\Users\18432\Desktop\medoing\silver-rod-git\include\raylib.h" //TODO figure out why this isn't working like normal with include/raylib.h :\

static int framesCounter;
static int finishScreen;

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
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
    DrawText("WARNING: this is a developmental build.", 1920/2, 1080/2, 20, PINK);
}

void UnloadDevScreen(void){

}

int FinishDevScreen(void){
    return finishScreen;
}
