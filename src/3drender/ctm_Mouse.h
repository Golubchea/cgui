#pragma once

///MOUSE
typedef struct mouse_t
{
    float mouse_x ;
    float mouse_y ;
    float mouse_x_last ;
    float mouse_y_last ;
    float speed ;
    float mouseSpeed;
}ctm_Mouse;

ctm_Mouse ctm_Mouse_new()
{
    ctm_Mouse m;
    m.speed=10.0f; // 3 units / second
    m.mouseSpeed=0.005f;

    return m;
}



