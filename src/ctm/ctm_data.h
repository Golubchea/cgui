#pragma once

#define MAX_PATH_LEN 512


#include <SDL.h>

struct icons {
    struct nk_image desktop;
    struct nk_image home;
    struct nk_image computer;
    struct nk_image directory;

    struct nk_image default_file;
    struct nk_image text_file;
    struct nk_image music_file;
    struct nk_image font_file;
    struct nk_image img_file;
    struct nk_image movie_file;
};


enum file_groups {
    FILE_GROUP_DEFAULT,
    FILE_GROUP_TEXT,
    FILE_GROUP_MUSIC,
    FILE_GROUP_FONT,
    FILE_GROUP_IMAGE,
    FILE_GROUP_MOVIE,
    FILE_GROUP_MAX
};

enum file_types {
    FILE_DEFAULT,
    FILE_TEXT,
    FILE_C_SOURCE,
    FILE_CPP_SOURCE,
    FILE_HEADER,
    FILE_CPP_HEADER,
    FILE_MP3,
    FILE_WAV,
    FILE_OGG,
    FILE_TTF,
    FILE_BMP,
    FILE_PNG,
    FILE_JPEG,
    FILE_PCX,
    FILE_TGA,
    FILE_GIF,
    FILE_MAX
};

struct file_group {
    enum file_groups group;
    const char *name;
    struct nk_image *icon;
};

struct file {
    enum file_types type;
    const char *suffix;
    enum file_groups group;
};

struct media {
    int font;
    int icon_sheet;
    struct icons icons;
    struct file_group group[FILE_GROUP_MAX];
    struct file files[FILE_MAX];
};

struct file_browser {
    /* path */
    char file[MAX_PATH_LEN];
    char home[MAX_PATH_LEN];
    char desktop[MAX_PATH_LEN];
    char directory[MAX_PATH_LEN];

    /* directory content */
    char **files;
    char **directories;
    size_t file_count;
    size_t dir_count;
    struct media *media;
    bool visible;
    bool isSave;
     char savebuffer[256];
};


struct ctm_dialog
{
    struct file_browser browser;
    struct media media;

};

struct ctm_window
{
    SDL_Window *win;
    SDL_GLContext glContext;
    int win_width, win_height;
    int running ;
    struct nk_context *ctx;
    struct nk_colorf bg;


};

struct ctm_topmenu
{
    struct nk_image minIcon;
    struct nk_image maxIcon;
    struct nk_image closeIcon;

    char min[9];
    char max[11];
    char close[12];
    struct nk_rect about_size ;
};


