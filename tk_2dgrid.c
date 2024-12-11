#include "tk_2dgrid.h"

int tk2dg_rotate(int x, int y, int size, int flag)
{
    int index = 0;
    
    if (flag < 0 || flag > 3)
        return -1;
    
    switch(flag){
        case 0: {index = y * size + x;} break;                        /* 0 degree */
        case 1: {index = (size * (size - 1)) + y - (x * size);} break; /* 90 degrees */
        case 2: {index = ((size * size) - 1) - (y * size) - x;} break; /* 180 degrees */
        case 3: {index = (size - 1) - y + (size * x);} break;          /* 270 degrees */
    }
    
    return index;
}