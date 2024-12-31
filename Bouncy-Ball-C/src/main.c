#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>

#include "display.h"
#include "vector.h"

bool is_running = false;
int previous_frame_time = 0;

void setup(void)
{
    color_buffer = (u_int32_t *)malloc(sizeof(uint32_t) * window_width * window_height);

    /// Creating a SDL texture that is use to display the color buffer
    color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        window_width,
        window_height);

    if (color_buffer_texture == NULL)
    {
        fprintf(stderr, "Error creating color buffer texture.\n");
    }
}

void process_input(void)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;

    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            is_running = false;
            break;
        }
    }
}

void update()
{
    // Wait some time untill reach the target frame time in milliseconds
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - previous_frame_time);

    // Only delay execuation if we are running too fast
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
    // How many milli seconds has passed since the last frame
    previous_frame_time = SDL_GetTicks(); // Started since SDL_Init
}

circle_t circle1 = {.position = {.x = 200, .y = 100}, .diameter = 100, .velocity = {.x = 0, .y = 0}, .mass = 2};

void render(void)
{
    SDL_RenderClear(renderer);

    clear_color_buffer(0xFF399145);

    draw_grid(10);

    draw_circle(circle1, 0xffffffff);

    render_color_buffer();
    SDL_RenderPresent(renderer);
}

int main()
{
    is_running = initialize_window();
    setup();

    while (is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();
}