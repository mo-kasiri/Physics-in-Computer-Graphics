#include "shapes.h"
#include "display.h"

void draw_rectangle(const rectangle_t rect, const u_int32_t color)
{
    for (int i = 0; i <= rect.height; i++)
    {
        for (int j = 0; j <= rect.width; j++)
        {
            draw_pixel(j + rect.position.x, i + rect.position.y, color);
        }
    }
}

void draw_circle(const circle_t cir, const u_int32_t color)
{
    float radius = cir.diameter / 2;
    for (unsigned int i = 0; i <= cir.diameter; i++)
    {
        for (unsigned int j = 0; j <= cir.diameter; j++)
        {
            if (sqrt(pow(j - radius, 2) + pow(i - radius, 2)) <= radius)
            {
                draw_pixel(j + cir.position.x, i + cir.position.x, color);
            }
        }
    }
}