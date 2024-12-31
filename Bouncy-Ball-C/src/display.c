#include "display.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Texture *color_buffer_texture = NULL;
uint32_t *color_buffer = NULL;

unsigned int window_width = 800;
unsigned int window_height = 600;

bool initialize_window(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error Initializing SDL.\n");
        return false;
    }

    // Use SDL to query what is the fullscreen max. width and height
    if (SDL_GetNumVideoDisplays() > 0)
    {
        static int display_in_use = 0; /* Only using first display */

        int i, display_mode_count;
        SDL_DisplayMode mode;
        SDL_DisplayMode *modes = (SDL_DisplayMode *)malloc(sizeof(SDL_DisplayMode) * SDL_GetNumDisplayModes(display_in_use));
        if (modes == NULL)
        {
            fprintf(stderr, "Memmory not allocated");
            return false;
        }
        Uint32 f;

        SDL_Log("SDL_GetNumVideoDisplays(): %i", SDL_GetNumVideoDisplays());

        display_mode_count = SDL_GetNumDisplayModes(display_in_use);

        SDL_Log("SDL_GetNumDisplayModes: %i", display_mode_count);

        for (i = 0; i < display_mode_count; ++i)
        {
            if (SDL_GetDisplayMode(display_in_use, i, &mode) != 0)
            {
                SDL_Log("SDL_GetDisplayMode failed: %s", SDL_GetError());
                return 1;
            }
            f = mode.format;
            modes[i] = mode;

            SDL_Log("Mode %i\tbits per pixel %i\t%s\t%i x %i",
                    i, SDL_BITSPERPIXEL(f),
                    SDL_GetPixelFormatName(f),
                    mode.w, mode.h);
        }
        window_width = modes[15].w;
        window_height = modes[15].h;

        free(modes);
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_width,
        window_height,
        0);

    if (!window)
    {
        fprintf(stderr, "Error creating SDL Window.\n");
        SDL_GetError();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer.\n");
        SDL_GetError();
        return false;
    }
    // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    return true;
}

void draw_pixel(const int x, const int y, const uint32_t color)
{
    if (x >= 0 && x < window_width && y >= 0 && y < window_height)
        color_buffer[(window_width * y) + x] = color;
}

// The main goal is to copy data from color buffer (that we created and populated with data) to color texture of SDL library
void render_color_buffer(void)
{
    SDL_UpdateTexture(
        color_buffer_texture,
        NULL,
        color_buffer,
        (int)window_width * sizeof(uint32_t));

    SDL_RenderCopy(
        renderer,
        color_buffer_texture,
        NULL,
        NULL);
}

void clear_color_buffer(uint32_t color)
{
    for (int y = 0; y < window_height; y++)
    {
        for (int x = 0; x < window_width; x++)
        {
            draw_pixel(x, y, color);
        }
    }
}

void draw_grid(const unsigned int size)
{
    for (int i = 0; i < window_width; i++)
    {
        for (int j = 0; j < window_height; j++)
        {
            if (i % size == 0 && j % size == 0)
                // color_buffer[window_width * j + i] = 0xFF555555;
                draw_pixel(i, j, 0xFF555555);
        }
    }
}

void destroy_window(void)
{
    free(color_buffer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}