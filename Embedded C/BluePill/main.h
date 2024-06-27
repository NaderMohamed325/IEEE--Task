//
// Created by xcite on 3/11/2024.
//

#ifndef BLUEPILL_MAIN_H
#define BLUEPILL_MAIN_H

#include <stdint.h>
#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO.h"
#include "lcd.h"

void clock_init() {

    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
}

void wait_ms(uint32_t time) {
    uint32_t i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 255; j++);
}

void My_String(unsigned char *The_char) {
    lcd_send_string(The_char);
    wait_ms(1000);
    lcd_send_command(LCD_CLEAR);
}

void intToStr(int num, char* str) {
    int i = 0;
    if (num < 0) {
        str[i++] = '-';
        num = -num;
    }
    int temp = num;
    do {
        str[i++] = temp % 10 + '0';
        temp /= 10;
    } while (temp != 0);

    str[i] = '\0';

    // Reverse the string
    int start = (str[0] == '-') ? 1 : 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


#endif //BLUEPILL_MAIN_H
