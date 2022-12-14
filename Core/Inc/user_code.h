/*
 * user_code.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ntpt
 */

#ifndef INC_USER_CODE_H_
#define INC_USER_CODE_H_

#include "main.h"

#define SEG7_PATTERN_0 SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin
#define SEG7_PATTERN_1 SEG1_Pin | SEG2_Pin
#define SEG7_PATTERN_2 SEG0_Pin | SEG1_Pin | SEG3_Pin | SEG4_Pin | SEG6_Pin
#define SEG7_PATTERN_3 SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin
#define SEG7_PATTERN_4 SEG1_Pin | SEG2_Pin | SEG5_Pin | SEG6_Pin
#define SEG7_PATTERN_5 SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin
#define SEG7_PATTERN_6 SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin
#define SEG7_PATTERN_7 SEG0_Pin | SEG1_Pin | SEG2_Pin
#define SEG7_PATTERN_8 SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin
#define SEG7_PATTERN_9 SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin
// assume all seg pattern line is in the same port
#define COMMON_SEG7_PATTERN_PORT SEG0_GPIO_Port

#define CONTROL_LINE_0 EN0_Pin
#define CONTROL_LINE_1 EN1_Pin
#define CONTROL_LINE_2 EN2_Pin
#define CONTROL_LINE_3 EN3_Pin
// assume all control pin is in the same port
#define COMMON_CONTROL_PORT EN0_GPIO_Port

#define COLUMN_CONTROL_LINE_0 ENM0_Pin
#define COLUMN_CONTROL_LINE_1 ENM1_Pin
#define COLUMN_CONTROL_LINE_2 ENM2_Pin
#define COLUMN_CONTROL_LINE_3 ENM3_Pin
#define COLUMN_CONTROL_LINE_4 ENM4_Pin
#define COLUMN_CONTROL_LINE_5 ENM5_Pin
#define COLUMN_CONTROL_LINE_6 ENM6_Pin
#define COLUMN_CONTROL_LINE_7 ENM7_Pin
// assume all column control line is in the same port
#define COMMON_COLUMN_CONTROL_PORT ENM0_GPIO_Port
// assume all matrix pattern pin is in the same port
#define COMMON_MATRIX_PATTERN_PORT ROW0_GPIO_Port

#define NUMBER_OF_SEG7 4
#define LED_MATRIX_SIZE 8

extern uint16_t seg7_pattern_list[];
extern int16_t control_line_list[NUMBER_OF_SEG7];
extern int index_led;
extern int led_buffer[NUMBER_OF_SEG7];

extern int index_led_matrix;
extern uint8_t matrix_buffer[LED_MATRIX_SIZE];
extern int16_t col_enable_list[LED_MATRIX_SIZE];

void set_output_pattern_7seg(int32_t value);
void disable_7seg(int32_t value);
void disable_all_7seg();
void enable_7seg(int32_t value);
void update7SEG(int index);
void increment_time(int *hour, int *minute, int *second);
void updateClockBuffer();

void set_output_pattern_matrix(int32_t value);
void disable_column(int32_t value);
void disable_all_column();
void enable_column(int value);
void updateLEDMatrix(int index);

#endif /* INC_USER_CODE_H_ */
