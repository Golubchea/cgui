#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <memory.h>


#include "3drender/ctm_Render_obj.h"

#include "3drender/vbm.h"
#include "3drender/vutils.h"
#include "Linear_math/Linear_math.h"

#include "3drender/LoadShaders.h"
#include "3drender/ctm_Render.h"
#include "3drender/ctm_Camera.h"
#include "3drender/ctm_Screen.h"
#include "3drender/ctm_Mouse.h"


#include "project.h"

int main(void)
{
    SDL_Event evt;

    struct ctm_window window;
    struct ctm_topmenu topmenu;
    struct ctm_dialog dialog;

    ctm_window_init(& window);
    ctm_topmenu_init( & topmenu);
    ctm_dialog_init(&dialog);

    ctm_Camera c=ctm_Camera_new();
    ctm_Mouse m=ctm_Mouse_new();
    ctm_Screen s=ctm_Screen_new();

    ctm_Render r=ctm_Render_new();
    ctm_light_uniforms lu;
    ctm_scene_uniforms su;

    ctm_3dobject obj;

    Initialize(&r,&su,&lu,2048);
     VBObject_LoadFromVBM(&obj.object,"resources/models/armadillo_low.vbm", 0, 1, 2);

    while (window.running)
    {
        // Input
        nk_input_begin(window.ctx);
        while (SDL_PollEvent(&evt)) {
            nk_sdl_handle_event(&evt);
              ctm_Camera_handle(&evt,window.win,&m,&c,&s);
        } nk_input_end(window.ctx);



        // Draw commands
        ctm_topmenu_draw(&window,&dialog,&topmenu);
        ctm_dialog_listener(&window,&dialog);

        //overview(window.ctx);
        ctm_window_refresh(&window,&topmenu,&dialog);


         ctm_Display(&m,&c,&s,&obj,&r,&lu,&su);

        ctm_swapWindow(&window,&topmenu,&dialog);
    }
    ctm_finalize(&r);
    return 0;
}

