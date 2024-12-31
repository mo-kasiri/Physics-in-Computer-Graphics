#include "physics.h"

void potential_energy(circle_t *circle)
{
    float h = window_height - circle->position.y;
    float E_potential = circle->mass * A_GRAVITY * h;
    circle->position.y +=
}
