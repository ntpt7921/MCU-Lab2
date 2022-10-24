/*
 * software_timer.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ntpt
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define TIMER_TICK_DURATION_MS 10
extern int TIMER_CYCLE;

extern int timer0_counter;
extern int timer0_flag;

extern int timer1_counter;
extern int timer1_flag;

extern int timer2_counter;
extern int timer2_flag;


void setTimer0(int duration);
void timer0_run();

void setTimer1(int duration);
void timer1_run();

void setTimer2(int duration);
void timer2_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
