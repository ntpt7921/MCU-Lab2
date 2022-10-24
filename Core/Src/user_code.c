/*
 * user_code.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ntpt
 */
#include "user_code.h"

int16_t seg7_pattern_list[] = {
    SEG7_PATTERN_0, SEG7_PATTERN_1, SEG7_PATTERN_2, SEG7_PATTERN_3,
    SEG7_PATTERN_4, SEG7_PATTERN_5, SEG7_PATTERN_6, SEG7_PATTERN_7,
    SEG7_PATTERN_8, SEG7_PATTERN_9,
};

int16_t control_line_list[NUMBER_OF_SEG7] = {
    CONTROL_LINE_0, CONTROL_LINE_1,
};



void set_output_pattern_7seg(int32_t value)
{
    if (value < 0 || value > 9)
        return;

    COMMON_SEG7_PATTERN_PORT->BSRR = ~seg7_pattern_list[value];
    COMMON_SEG7_PATTERN_PORT->BSRR = (uint32_t) (~seg7_pattern_list[value]) << 16u;
}
void disable_7seg(int32_t value)
{
    if (value < 0 || value > NUMBER_OF_SEG7)
        return;

    HAL_GPIO_WritePin(COMMON_CONTROL_PORT, control_line_list[value], RESET);
}
void enable_7seg(int32_t value)
{
    if (value < 0 || value > NUMBER_OF_SEG7)
        return;

    HAL_GPIO_WritePin(COMMON_CONTROL_PORT, control_line_list[value], SET);
}

