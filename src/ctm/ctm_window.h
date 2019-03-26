#pragma once
#include "ctm_data.h"

static void ctm_window_delete(struct ctm_window * window)
{
    SDL_GL_DeleteContext(window->glContext);
    SDL_DestroyWindow(window->win);
}

static void ctm_exit(struct ctm_window *window,struct ctm_topmenu * topmenu,struct ctm_dialog* dialog)
{
    window->running=0;
    ctm_topmenu_delete(topmenu);
    ctm_dialog_delete(dialog);
    nk_sdl_shutdown();

    ctm_window_delete(window);

    SDL_Quit();
}

static void ctm_window_init(struct ctm_window *w)
{
    setlocale ( LC_ALL , " " ) ;
    /* SDL setup */
    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    w->win = SDL_CreateWindow("3dGraph",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_BORDERLESS|SDL_WINDOW_RESIZABLE);
    (w->glContext) = SDL_GL_CreateContext( w->win);
    SDL_GetWindowSize(w->win, &w->win_width, &w->win_height);


    // Check OpenGL properties
    printf("OpenGL loaded\n");
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    // Use v-sync
    SDL_GL_SetSwapInterval(1);
    /* OpenGL setup */
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    w->ctx = nk_sdl_init(w->win);
    /* Load Fonts: if none of these are loaded a default font will be used  */
    /* Load Cursor: if you uncomment cursor loading please hide the cursor */

    struct nk_font_config config = nk_font_config(16);
    config.oversample_h = 1;
    config.oversample_v = 1;
    config.range=nk_font_cyrillic_glyph_ranges();

    {struct nk_font_atlas *atlas;
        nk_sdl_font_stash_begin(&atlas);
        struct nk_font *roboto = nk_font_atlas_add_from_file(atlas, "resources/font/Roboto-Regular.ttf", 16, &config);
        nk_sdl_font_stash_end();
        /*nk_style_load_all_cursors(ctx, atlas->cursors);*/
        nk_style_set_font(w->ctx, &roboto->handle);}
    set_style(w->ctx, THEME_WHITE);
    w->bg.r = 0.99f, w->bg.g = 0.99f,w->bg.b = 0.99f, w->bg.a = 1.0f;
    w->running = 1;
}


static void ctm_window_refresh(struct ctm_window *window,struct ctm_topmenu * topmenu,struct ctm_dialog* dialog)
{

    SDL_GetWindowSize(window->win, &window->win_width, &window->win_height);
    glViewport(0, 0, window->win_width, window->win_height);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(window->bg.r, window->bg.g, window->bg.b, window->bg.a);
}


static void ctm_swapWindow(struct ctm_window *window,struct ctm_topmenu * topmenu,struct ctm_dialog* dialog)
{

    nk_sdl_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_MEMORY, MAX_ELEMENT_MEMORY);

    SDL_Delay(20);
    SDL_GL_SwapWindow(window->win);
    if(window->running!=1)
    {
        ctm_exit(window,topmenu,dialog);

    }
}





