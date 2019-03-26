#pragma once 


#include <SDL2/SDL.h>
#include<glad.h>


#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION


#include "nuclear/nuklear.h"
#include "nuclear/nuklear_sdl_gl3.h"
#include "nuclear/style.h"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 400

#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024


//#include "ctm/ctm_obj.h"
#include "ctm/ctm_data.h"
#include "ctm/ctm_topmenu.h"
#include "ctm/ctm_dialog.h"
#include "ctm/ctm_window.h"
#include "../overview.c"
#include "ctm/ctm_window.h"
