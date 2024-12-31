#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vector.h"
#include "shapes.h"
#include "display.h"

#define A_GRAVITY 9.8

void potential_energy(circle_t *circle);

#endif