#ifndef SHAPES_H
#define SHAPES_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "vector.h"

typedef struct
{
    vec2_t position;
    float diameter;
    vec2_t velocity;
    float mass;
} circle_t;

typedef struct
{
    vec2_t position;
    float width;
    float height;
    vec2_t velocity;
    float mass;
} rectangle_t;

void draw_rectangle(const rectangle_t rect, const u_int32_t color);
void draw_circle(const circle_t cir, const u_int32_t color);

#endif