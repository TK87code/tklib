#include "tk_math.h"

int tkmt_clamp(int value_to_clamp, int min, int max)
{
    if (value_to_clamp < min) 
        return  min;
    if (value_to_clamp > max)
        return max;
    
    return value_to_clamp;
}

float tkmt_clampf(float value_to_clamp, float min, float max)
{
    if (value_to_clamp < min) 
        return  min;
    if (value_to_clamp > max)
        return max;
    
    return value_to_clamp;
}
