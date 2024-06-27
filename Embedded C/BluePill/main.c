/*  File -> main.c
 *  Author Nader Mohamed Nader
 */

#include "main.h"

// Define GPIO pins for motor control and push button
#define Motor_CTRL  GPIOB
#define motor_pin1  GPIO_PIN_3
#define motor_pin2  GPIO_PIN_4
#define motor_pin3  GPIO_PIN_5
#define motor_pin4  GPIO_PIN_6
#define push_button GPIO_PIN_7

#define led_pin1  GPIO_PIN_0
#define led_pin2  GPIO_PIN_1
#define led_pin3  GPIO_PIN_10
#define led_pin4  GPIO_PIN_11

// Structure for GPIO pin configuration
GPIO_PIN_CONFIG_T PinCfg_motor;
GPIO_PIN_CONFIG_T PinCfg_push_1;
GPIO_PIN_CONFIG_T PinCfg_led;

// Function prototypes
void motor_display(void);

void motors_init();

void led_init();

int main(void) {
    // Initialize clock and LCD
    clock_init();
    lcd_init();

    // Initialize motor control and led
    motors_init();
    led_init();

    // Display messages on LCD
    My_String("Hello I'm Nader");
    My_String("This is me from IEEE");
    My_String("From STM32F103C8");

    while (1) {
        motor_display();
    }
}

// Function to initialize the push button
void push_init() {
    PinCfg_push_1.GPIO_PIN_NUMBER = push_button;
    PinCfg_push_1.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_push_1);
}

// Function to initialize the motor control pins
void motors_init() {
    // Initialize motor_pin1
    PinCfg_motor.GPIO_PIN_NUMBER = motor_pin1;
    PinCfg_motor.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_motor.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_motor);

    // Initialize motor_pin2
    PinCfg_motor.GPIO_PIN_NUMBER = motor_pin2;
    PinCfg_motor.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_motor.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_motor);

    // Initialize motor_pin3
    PinCfg_motor.GPIO_PIN_NUMBER = motor_pin3;
    PinCfg_motor.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_motor.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_motor);

    // Initialize motor_pin4
    PinCfg_motor.GPIO_PIN_NUMBER = motor_pin4;
    PinCfg_motor.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_motor.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_motor);
}

// Function to initialize the leds control pins
void led_init() {

    PinCfg_led.GPIO_PIN_NUMBER = led_pin1;
    PinCfg_led.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_led.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_led);


    PinCfg_led.GPIO_PIN_NUMBER = led_pin2;
    PinCfg_led.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_led.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_led);


    PinCfg_led.GPIO_PIN_NUMBER = led_pin3;
    PinCfg_led.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_led.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_led);


    PinCfg_led.GPIO_PIN_NUMBER = led_pin4;
    PinCfg_led.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg_led.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHz;
    MCAL_GPIO_Init(Motor_CTRL, &PinCfg_led);
}

void motor_display(void) {
    // Motor control sequence

    // Turn off all motors
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin1, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin2, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin3, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin4, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin1, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin2, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin3, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin4, GPIO_PIN_RESET);

    // Turn on Motor 1
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin1, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin2, GPIO_PIN_RESET);
    lcd_send_string("Motor 1 is ON");
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin4, GPIO_PIN_SET);
    wait_ms(3000);
    lcd_clear();
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin1, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin2, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin4, GPIO_PIN_RESET);

    // Turn on Motor 2
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin3, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin4, GPIO_PIN_RESET);
    lcd_send_string("Motor 2 is ON");
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin3, GPIO_PIN_SET);
    wait_ms(3000);
    lcd_clear();
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin3, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin4, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin3, GPIO_PIN_RESET);


    // Turn on all motors
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin1, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin3, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin2, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin4, GPIO_PIN_RESET);
    lcd_send_string("Motors are ON");
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin3, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin4, GPIO_PIN_SET);
    wait_ms(3000);
    lcd_clear();
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin3, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin4, GPIO_PIN_RESET);

    // Toggle motors
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin1, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin2, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin3, GPIO_PIN_RESET);
    MCAL_GPIO_WritePin(Motor_CTRL, motor_pin4, GPIO_PIN_SET);
    lcd_send_string("Motors are Toggled");
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin1, GPIO_PIN_SET);
    MCAL_GPIO_WritePin(Motor_CTRL, led_pin2, GPIO_PIN_SET);
    wait_ms(3000);
    lcd_clear();
}

