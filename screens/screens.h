/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Screens Functions Declarations (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2021 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef SCREENS_H
#define SCREENS_H


typedef enum GameScreen { RL_LOGO = 0, DEV_WARNING, CHARACTER_SELECT, FEM_CONFIRM, MASC_CONFIRM} GameScreen;


extern GameScreen currentScreen;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//raylib logo screen declaration
void rlInitLogoScreen(void);
void rlUpdateLogoScreen(void);
void rlDrawLogoScreen(void);
void rlUnloadLogoScreen(void);
int rlFinishLogoScreen(void);

//development warning screen declaration
void InitDevScreen(void);
void UpdateDevScreen(void);
void DrawDevScreen(void);
void UnloadDevScreen(void);
int FinishDevScreen(void);

//character select screen declaration
void InitCharacterScreen(void);
void UpdateCharacterScreen(void);
void DrawCharacterScreen(void);
void UnloadCharacterScreen(void);
int FinishCharacterScreen(void);
bool SelectedPlayer();

//fem character confirmation screen declaration
void InitFemScreen(void);
void UpdateFemScreen(void);
void DrawFemScreen(void);
void UnloadFemScreen(void);
int FinishFemScreen(void);

//masc character confirmation screen declaration
void InitMascScreen(void);
void UpdateMascScreen(void);
void DrawMascScreen(void);
void UnloadMascScreen(void);
int FinishMascScreen(void);

#ifdef __cplusplus
}
#endif

#endif // SCREENS_H