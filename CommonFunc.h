
#ifndef COMMOM_FUNCTION_H_
#define COMMOM_FUNCTION_H_


#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>



static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;



//screen
const int FRAME_PER_SECOND = 38; //fps
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 608;
const int SRCEEN_BPP = 32;
const int NUM_BARRIER = 4;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

const int RENDER_DRAW_COLOR = 0xff;

namespace SDLCommonFunc
{
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}

#endif