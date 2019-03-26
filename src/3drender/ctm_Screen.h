#pragma once
typedef struct screen_t
{
    GLint current_width;
    GLint current_height;
    int window_width;
    int window_height;
}ctm_Screen;


ctm_Screen ctm_Screen_new()
{
    ctm_Screen m;
    m.window_width=800;
    m.window_height=600;
    return m;
}


