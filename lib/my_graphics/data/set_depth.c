/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function calculate the depth from the position
*/
#include "../include/data.h"

long double set_depth(sfVector3f position)
{
    long double depth = 0.L;
    depth += position.z;
    if (position.y != 0.f) {
        depth += 1.L / position.y;
    }
    return depth;
}
