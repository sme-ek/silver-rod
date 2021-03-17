//
// Created by smeek on 17/03/2021.
//

#include "../include/raylib.h"

static int framesCounter;
static int finishScreen;
static float alpha = 1.0f;

//general variable for character select
struct Vector2;
struct Vector3;

static struct Vector2 fem_player; //fem player
static struct Vector3 masc_player; //masc player
static Rectangle selectArea; //the area that the player can click to select their character

void InitCharacterScreen(void){
    framesCounter = 0;
    finishScreen = 0;
    //stand in character select radius
    selectArea = (struct Rectangle){150, 150, 50, 450};
}

void UpdateCharacterScreen(void){

}

void DrawCharacterScreen(void){
DrawRectangle(GetScreenWidth(), GetScreenHeight(), 1920, 1080, Fade(WHITE, alpha));
DrawCircle(0, 0, 600, Fade(PINK, alpha));
DrawRectangle (150, 150, 50, 450, PURPLE); //stand in female slot
}
void UnloadCharacterScreen(void){

}
int FinishCharacterScreen(void){
    return finishScreen;
}