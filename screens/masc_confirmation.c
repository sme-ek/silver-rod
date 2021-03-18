//
// Created by smeek on 18/03/2021.
//

#include "../include/raylib.h"

static int framesCounter;
static int finishScreen;
static float alpha = 1.0f;
bool selectedPlayer;

void InitMascScreen(void){
    framesCounter = 0;
    finishScreen = 0;
}

void UpdateMascScreen(void){

}

void DrawMascScreen(void) {
    DrawRectangle(0, 0, 1920, 1080, Fade(BLUE, alpha));
    DrawText ("You have selected [masc]. Is this correct?", GetScreenWidth()/8, GetScreenHeight()/2, 50, Fade(WHITE, alpha));
}


void UnloadMascScreen(void){

}

int FinishMascScreen(void){
    return finishScreen;
}