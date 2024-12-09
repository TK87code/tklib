/* date = December 9th 2024 10:56 pm */

#ifndef TK_MATH_H
#define TK_MATH_H

/**
* @brief Clamp the passed value.
* @param value_to_clamp A value to clamp.
* @param A minimum value to return.
* @param A maximum value to return.
* @return A clamped value.
*/
int tkmt_clamp(int value_to_clamp, int min, int max);
/**
* @brief Clamp the passed value.
* @param value_to_clamp A value to clamp.
* @param A minimum value to return.
* @param A maximum value to return.
* @return A clamped value.
*/
float tkmt_clampf(float value_to_clamp, float min, float max);

#endif //TK_MATH_H
