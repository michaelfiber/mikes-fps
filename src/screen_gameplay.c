/**********************************************************************************************
 *
 *   raylib - Advance Game template
 *
 *   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
 *
 *   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
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

#include "raylib.h"
#include "screens.h"
#include "fontstyle.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
static Camera camera = {0};

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
	// TODO: Initialize GAMEPLAY screen variables here!
	framesCounter = 0;
	finishScreen = 0;

	camera.position = (Vector3){4.0f, 2.0f, 4.0f};
	camera.target = (Vector3){0.0f, 1.8f, 0.0f};
	camera.up = (Vector3){0.0f, 1.0f, 0.0f};
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	SetCameraMode(camera, CAMERA_FIRST_PERSON);
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
	UpdateCamera(&camera);

	// Press enter or tap to change to ENDING screen
	// if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	// {
	//     finishScreen = 1;
	//     PlaySound(fxCoin);
	// }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
	BeginMode3D(camera);
	{
		DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY); // Draw ground
		DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);			// Draw a blue wall
		DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);			// Draw a green wall
		DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);			// Draw a yellow wall
	}
	EndMode3D();
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
	return finishScreen;
}