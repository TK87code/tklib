#include "tk_collision.h"

char tkcol_point_vs_rect(int px, int py, int rx, int ry, int rw, int rh)
{
    return (px >= rx && py >= ry && px <= rx + rw && py <= ry + rh);
}

char tkcol_rect_vs_rect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    return (x1 < x2 + w2 && x2 < x1 + w1 && y1 < y2 + h2 && y2 < y1 + h1);
}