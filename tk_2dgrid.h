/* date = December 11th 2024 3:40 pm */
#ifndef TK_2DGRID_H
#define TK_2DGRID_H

#include <stddef.h>

/**
* @brief Return index of specified x, y when given size(w&h) of square 2d grid is rotated by 90 dgree. 
* @param x X coordinate in the grid.
* @param y y corrdinate in the grid.
* @param size Size(width & height, they must be same value) of the 2d grid.
* @param flag 0->0 degree, 1->90, 2->180, 3->270
* @return Index value that can be used in an array. Return -1 if passed invalid flag.
*/
int tk2dg_rotate(int x, int y, int size, int flag);

#endif //TK_2DGRID_H
