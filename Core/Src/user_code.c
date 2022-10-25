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
    CONTROL_LINE_0, CONTROL_LINE_1, CONTROL_LINE_2, CONTROL_LINE_3,
};

int index_led = 0;
int led_buffer[NUMBER_OF_SEG7] = { 1, 2, 3, 4 };



void set_output_pattern_7seg(int32_t value)
{
    if (value < 0 || value > 9)
        return;

    COMMON_SEG7_PATTERN_PORT->BSRR = ~seg7_pattern_list[value];
    COMMON_SEG7_PATTERN_PORT->BSRR = (uint32_t) (seg7_pattern_list[value]) << 16u;
}
void disable_7seg(int32_t value)
{
    if (value < 0 || value > NUMBER_OF_SEG7)
        return;

    HAL_GPIO_WritePin(COMMON_CONTROL_PORT, control_line_list[value], SET);
}
void disable_all_7seg()
{
    for (int32_t i = 0; i < NUMBER_OF_SEG7; i++)
        disable_7seg(i);
}
void enable_7seg(int32_t value)
{
    if (value < 0 || value > NUMBER_OF_SEG7)
        return;

    HAL_GPIO_WritePin(COMMON_CONTROL_PORT, control_line_list[value], RESET);
}
void update7SEG(int index)
{
    disable_all_7seg();
    switch (index)
    {
        case 0:
            set_output_pattern_7seg(led_buffer[index]);
            break;
        case 1:
            set_output_pattern_7seg(led_buffer[index]);
            break;
        case 2:
            set_output_pattern_7seg(led_buffer[index]);
            break;
        case 3:
            set_output_pattern_7seg(led_buffer[index]);
            break;

        default:
            break;
    }
    enable_7seg(index);
}
void increment_time(int *hour, int *minute, int *second)
{

    (*second)++;

    if (*second >= 60)
    {
        *second = 0;
        (*minute)++;
    }

    if (*minute >= 60)
    {
        *minute = 0;
        (*hour)++;
    }

    if (*hour >= 24)
    {
        *hour = 0;
    }
}
void updateClockBuffer(int hour, int minute)
{
    led_buffer[0] = hour / 10;
    led_buffer[1] = hour % 10;
    led_buffer[2] = minute / 10;
    led_buffer[3] = minute % 10;
}
