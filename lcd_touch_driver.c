/*
 * lcd_touch_driver.c
 * This source file contains code
 * for the touch screen functions.
 *
 *  Created on: 14-Dec-2019
 *  Author: prayag
 */

#include "lcd_touch_driver.h"

//Read X: read Y1, X2 GND, X1 VCC, Y2 Tristate
//Read Y: read X1, Y2 GND, Y1 VCC, X2 Tristate

volatile uint32_t touchX = 0;
volatile uint32_t touchY = 0;

bool xready = false;
bool yready = false;
uint16_t getTouchX(void)
{
    //X2 GND
    TOUCH_X_MINUS_PORT->SEL0 &= ~TOUCH_X_MINUS_PIN; //GPIO MODE
    TOUCH_X_MINUS_PORT->SEL1 &= ~TOUCH_X_MINUS_PIN; //GPIO MODE
    TOUCH_X_MINUS_PORT->DIR |= TOUCH_X_MINUS_PIN;   //OUTPUT
    TOUCH_X_MINUS_PORT->OUT &= ~TOUCH_X_MINUS_PIN;  //GND

    //X1 VCC
    TOUCH_X_PLUS_PORT->SEL0 &= ~TOUCH_X_PLUS_PIN;   //GPIO MODE
    TOUCH_X_PLUS_PORT->SEL1 &= ~TOUCH_X_PLUS_PIN;   //GPIO MODE
    TOUCH_X_PLUS_PORT->DIR |= TOUCH_X_PLUS_PIN;     //OUTPUT
    TOUCH_X_PLUS_PORT->OUT |= TOUCH_X_PLUS_PIN;     //VCC

    //Y2 TRISTATE
    TOUCH_Y_MINUS_PORT->SEL0 &= ~TOUCH_Y_MINUS_PIN; //GPIO MODE
    TOUCH_Y_MINUS_PORT->SEL1 &= ~TOUCH_Y_MINUS_PIN; //GPIO MODE
    TOUCH_Y_MINUS_PORT->DIR &= ~TOUCH_Y_MINUS_PIN;  //INPUT

    //ADC input Y1
    TOUCH_Y_PLUS_PORT->DIR &= ~TOUCH_Y_PLUS_PIN;

    TOUCH_Y_PLUS_PORT->SEL1 |= TOUCH_Y_PLUS_PIN;                             //ADC mode
    TOUCH_Y_PLUS_PORT->SEL0 |= TOUCH_Y_PLUS_PIN;                              //ADC mode


    //    if(!yready)
    if(!xready){
        //            printf("X\n");
        NVIC->ISER[0] = 1 << ((ADC14_IRQn) & 31);
        xready = true;

    uint32_t result = 0;
    if(result <= 3000){
        return 0;
    } else
        return result;
}

//Read Y: read X1, Y2 GND, Y1 VCC, X2 Tristate
uint16_t getTouchY(void)
{
    //Y2 GND
    TOUCH_Y_MINUS_PORT->SEL0 &= ~TOUCH_Y_MINUS_PIN; //GPIO MODE
    TOUCH_Y_MINUS_PORT->SEL1 &= ~TOUCH_Y_MINUS_PIN; //GPIO MODE
    TOUCH_Y_MINUS_PORT->DIR |= TOUCH_Y_MINUS_PIN;   //OUTPUT
    TOUCH_Y_MINUS_PORT->OUT &= ~TOUCH_Y_MINUS_PIN;  //GND

    //Y1 VCC
    TOUCH_Y_PLUS_PORT->SEL0 &= ~TOUCH_Y_PLUS_PIN;   //GPIO MODE
    TOUCH_Y_PLUS_PORT->SEL1 &= ~TOUCH_Y_PLUS_PIN;   //GPIO MODE
    TOUCH_Y_PLUS_PORT->DIR |= TOUCH_Y_PLUS_PIN;     //OUTPUT
    TOUCH_Y_PLUS_PORT->OUT |= TOUCH_Y_PLUS_PIN;     //VCC

    //X2 TRISTATE
    TOUCH_X_MINUS_PORT->SEL0 &= ~TOUCH_X_MINUS_PIN; //GPIO MODE
    TOUCH_X_MINUS_PORT->SEL1 &= ~TOUCH_X_MINUS_PIN; //GPIO MODE
    TOUCH_X_MINUS_PORT->DIR &= ~TOUCH_X_MINUS_PIN;  //INPUT

    //ADC input X1
    TOUCH_X_PLUS_PORT->DIR &= ~TOUCH_X_PLUS_PIN;
    TOUCH_X_PLUS_PORT->SEL1 |= TOUCH_X_PLUS_PIN;                             //ADC mode
    TOUCH_X_PLUS_PORT->SEL0 |= TOUCH_X_PLUS_PIN;                              //ADC mode

	if(!yready){
		NVIC->ISER[0] = 1 << ((ADC14_IRQn) & 31);
		yready = true;
    }

    uint16_t result = 0;

    if(result <= 2300){
        return 0;
    } else
        return result;
}
