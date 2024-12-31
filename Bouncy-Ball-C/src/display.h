#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "vector.h"
#include "shapes.h"

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS) // The Constant Delta
#define PI 3.141592653589793

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern SDL_Texture *color_buffer_texture;
extern uint32_t *color_buffer;

extern unsigned int window_width;
extern unsigned int window_height;

bool initialize_window(void);
void draw_grid(const unsigned int size);
void draw_pixel(const int x, const int y, const uint32_t color);

void render_color_buffer(void);
void clear_color_buffer(uint32_t color);
void destroy_window(void);

#endif