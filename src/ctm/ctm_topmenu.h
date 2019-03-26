#pragma once
#include "ctm_data.h"


static void ctm_topmenu_init(struct  ctm_topmenu* topmenu)
{

    topmenu->closeIcon=icon_load("resources/icon/close.png");
    topmenu->maxIcon=icon_load("resources/icon/fullscreen.png");
    topmenu->minIcon=icon_load("resources/icon/minimize.png");


    topmenu->about_size=nk_rect(20, 100, 300, 190);
}



static void ctm_topmenu_draw(struct ctm_window * window,struct ctm_dialog * dialog,struct  ctm_topmenu * topmenu )
{

    struct nk_context* ctx;
    struct file_browser *browser=&dialog->browser;
    int * running=&window->running;
    int * win_width=&window->win_width;

    SDL_Window * win=window->win;

    if (nk_begin(ctx, "MAIN_MENU", nk_rect(0, 0, 220, 32),NK_WINDOW_NO_SCROLLBAR))
    {
        nk_menubar_begin(ctx);

        nk_layout_row_begin(ctx, NK_STATIC, 25, 3);
        nk_layout_row_push(ctx, 35);
        if (nk_menu_begin_label(ctx, "Файл", NK_TEXT_LEFT, nk_vec2(120, 200))) {
            nk_layout_row_dynamic(ctx, 30, 1);
            nk_menu_item_label(ctx, "Новый", NK_TEXT_LEFT);
            if(nk_menu_item_label(ctx, "Открыть", NK_TEXT_LEFT))
            {
                browser->isSave=false;
                browser->visible=true;
                //printf( browser->file);
            }

            nk_menu_item_label(ctx, "Сохранить", NK_TEXT_LEFT);
            if( nk_menu_item_label(ctx, "Сохранить как...", NK_TEXT_LEFT) )
            {
                browser->isSave=true;
                browser->visible=true;
                // printf( browser->file);
            }


            if( nk_menu_item_label(ctx, "Закрыть", NK_TEXT_LEFT) )
            {
                window->running=0;
            }

            nk_menu_end(ctx);
        }
        nk_layout_row_push(ctx, 95);
        if (nk_menu_begin_label(ctx, "Редактировать", NK_TEXT_LEFT, nk_vec2(120, 200))) {
            nk_layout_row_dynamic(ctx, 30, 1);
            nk_menu_item_label(ctx, "Копировать", NK_TEXT_LEFT);
            nk_menu_item_label(ctx, "Вырезать", NK_TEXT_LEFT);
            nk_menu_item_label(ctx, "Вставить", NK_TEXT_LEFT);

            nk_menu_end(ctx);
        }
        static int show_app_about = nk_false;


        nk_layout_row_push(ctx, 75);
        if ( nk_menu_begin_label(ctx, "Настройки", NK_TEXT_LEFT, nk_vec2(120, 200))   ) {
            nk_layout_row_dynamic(ctx, 30, 1);
            nk_menu_item_label(ctx, "Документация", NK_TEXT_LEFT);
            if(nk_menu_item_label(ctx, "О программе", NK_TEXT_LEFT)  )
            {
                show_app_about = nk_true;
            }
            nk_menu_end(ctx);
        }
        nk_layout_row_end(ctx);
        nk_menubar_end(ctx);

        if (show_app_about)
        {
            /* about popup */

            if (nk_popup_begin(ctx, NK_POPUP_STATIC, "О программе", NK_WINDOW_CLOSABLE|NK_WINDOW_MOVABLE, topmenu->about_size))
            {
                nk_layout_row_dynamic(ctx, 20, 1);
                nk_label(ctx, "Программа для чтения dcm", NK_TEXT_LEFT);
                nk_label(ctx, "библиотеки:", NK_TEXT_LEFT);
                nk_label(ctx, "nuklear",  NK_TEXT_LEFT);
                nk_label(ctx, "stb_image",  NK_TEXT_LEFT);
                nk_label(ctx, "SDL2",  NK_TEXT_LEFT);
                nk_popup_end(ctx);
            } else show_app_about = nk_false;
        }

        nk_end(ctx);
    }



    if (nk_begin(ctx, "WINDOW MANAGER", nk_rect(*win_width-95, 0,*win_width , 32),NK_WINDOW_NO_SCROLLBAR))
    {


        nk_layout_row_begin(ctx, NK_STATIC, 24, 3);
        nk_layout_row_push(ctx, 24);
        if (    nk_menu_begin_image(ctx,topmenu->min,topmenu->minIcon,nk_vec2(32,32))   )
        {

            SDL_MinimizeWindow(win);

            //                    SDL_Delay(100);
            //                        SDL_RestoreWindow(win);
            nk_layout_row_dynamic(ctx, 30, 30);
            nk_menu_end(ctx);
        }
        else
        {
            SDL_RestoreWindow(win);
        }
        nk_layout_row_push(ctx, 24);

        if (   nk_menu_begin_image(ctx,topmenu->max,topmenu->maxIcon,nk_vec2(32,32))  )
        {


            nk_layout_row_dynamic(ctx, 30, 30);
            nk_menu_end(ctx);
            nk_layout_row_end(ctx);
            SDL_SetWindowFullscreen( win,SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
        else
        {
            SDL_RestoreWindow(win);
        }
        nk_layout_row_push(ctx, 24);
        if ( nk_menu_begin_image(ctx,topmenu->close,topmenu->closeIcon,nk_vec2(32,32))   )
        {

            nk_layout_row_dynamic(ctx, 30, 30);
            nk_menu_end(ctx);
            nk_layout_row_end(ctx);
            window->running=0;
        }



    }
    nk_end(ctx);



}



static void ctm_topmenu_delete(struct  ctm_topmenu *topmenu)
{
    glDeleteTextures(1,(const GLuint*)&topmenu->maxIcon.handle.id);
    glDeleteTextures(1,(const GLuint*)&topmenu->closeIcon.handle.id);
    glDeleteTextures(1,(const GLuint*)&topmenu->minIcon.handle.id);
}



