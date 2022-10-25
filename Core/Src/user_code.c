/*
 * user_code.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ntpt
 */
#include "user_code.h"

uint16_t seg7_pattern_list[] = {
    SEG7_PATTERN_0, SEG7_PATTERN_1, SEG7_PATTERN_2, SEG7_PATTERN_3,
    SEG7_PATTERN_4, SEG7_PATTERN_5, SEG7_PATTERN_6, SEG7_PATTERN_7,
    SEG7_PATTERN_8, SEG7_PATTERN_9,
};

int16_t control_line_list[NUMBER_OF_SEG7] = {
    CONTROL_LINE_0, CONTROL_LINE_1, CONTROL_LINE_2, CONTROL_LINE_3,
};

int index_led = 0;
int led_buffer[NUMBER_OF_SEG7] = { 1, 2, 3, 4 };
int index_led_matrix = 0;
uint8_t matrix_buffer[LED_MATRIX_SIZE] = {
    0b00011111, 0b00111111, 0b01101100, 0b11001100, 0b11001100, 0b01101100, 0b00111111, 0b00011111,
};
int16_t col_enable_list[LED_MATRIX_SIZE] = {
    COLUMN_CONTROL_LINE_0, COLUMN_CONTROL_LINE_1, COLUMN_CONTROL_LINE_2, COLUMN_CONTROL_LINE_3,
    COLUMN_CONTROL_LINE_4, COLUMN_CONTROL_LINE_5, COLUMN_CONTROL_LINE_6, COLUMN_CONTROL_LINE_7,
};


void set_output_pattern_7seg(int32_t value)
{
    if (value < 0 || value > 9)
        return;

    uint32_t pattern_set = (~seg7_pattern_list[value]) & 0x00FF;
    uint32_t pattern_reset = (seg7_pattern_list[value] << 16u) & 0x00FF0000;

    COMMON_SEG7_PATTERN_PORT->BSRR = pattern_set | pattern_reset;
}
void disable_7seg(int32_t value)
{
    if (value < 0 || value >= NUMBER_OF_SEG7)
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
    if (value < 0 || value >= NUMBER_OF_SEG7)
        return;

    HAL_GPIO_WritePin(COMMON_CONTROL_PORT, control_line_list[value], RESET);
}
void update7SEG(int index)
{
    disable_all_7seg();

    set_output_pattern_7seg(led_buffer[index]);

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
void set_output_pattern_matrix(int32_t value)
{
    if (value < 0 || value > 9)
        return;

    // assume row control from 0 to 8 lies on pin PB8->PB15
    uint32_t required_pattern_set =  ((~matrix_buffer[value]) << 8u) & 0xFF00;
    uint32_t required_pattern_reset = (matrix_buffer[value] << 24u) & 0xFF000000;

    COMMON_MATRIX_PATTERN_PORT->BSRR = required_pattern_set | required_pattern_reset;
}
void disable_column(int32_t value)
{
    if (value < 0 || value >= LED_MATRIX_SIZE)
        return;

    HAL_GPIO_WritePin(COMMON_COLUMN_CONTROL_PORT, col_enable_list[value], SET);
}
void disable_all_column()
{
    for (int32_t i = 0; i < LED_MATRIX_SIZE; i++)
        disable_column(i);
}
void enable_column(int value)
{
    if (value < 0 || value >= LED_MATRIX_SIZE)
        return;

    HAL_GPIO_WritePin(COMMON_COLUMN_CONTROL_PORT, col_enable_list[value], RESET);
}
void updateLEDMatrix(int index)
{
    disable_all_column();

    set_output_pattern_matrix(index);

    enable_column(index);
}
