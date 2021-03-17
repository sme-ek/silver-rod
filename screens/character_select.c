//
// Created by smeek on 17/03/2021.
//

#include "../include/raylib.h"

static int framesCounter;
static int finishScreen;
static float alpha = 1.0f;

//general variable for character select
static void fem_player;
static void masc_player;
static void selectedPlayer;

//the area that the player can click to select their character
static Rectangle selectFemArea;
static Rectangle selectMascArea;

int GetMouseX(void);
int GetMouseY(void);

void InitCharacterScreen(void){
    framesCounter = 0;
    finishScreen = 0;

    //stand in character select radius
    selectFemArea = (struct Rectangle){150, 200, 350, 950};
    selectMascArea = (struct Rectangle){1250, 200, 350, 900};
}

void SelectCharacter(void){
    if (GetMouseX() == 150 && GetMouseY() == 200){
        selectedPlayer == fem_player;
    }
    if (GetMouseX() == 1250 && GetMouseY() == 200){
        selectedPlayer == masc_player;
    }
}

void UpdateCharacterScreen(void){
    if (selectedPlayer == fem_player){
        finishScreen == 1;
    }
    if (selectedPlayer == masc_player){
        finishScreen == 2;
    }
}

void DrawCharacterScreen(void){
DrawRectangle(GetScreenWidth(), GetScreenHeight(), 1920, 1080, Fade(WHITE, alpha));
DrawCircle(960, 540, 300, Fade(PINK, alpha));
DrawRectangle (150, 200, 350, 900, PURPLE); //stand in female slot
DrawRectangle(1450, 200, 350, 900, BLUE); //stand in male slot
}

void UnloadCharacterScreen(void){

}
int FinishCharacterScreen(void){
    return finishScreen;
}