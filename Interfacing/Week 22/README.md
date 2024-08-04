


## Traffic Light Example

### **Description:**
This example initializes three pins for a traffic light system using LEDs. Each LED will turn on and off sequentially with a delay in between to simulate traffic light signals.

### **Code Example:**

```c
#include "MCAL/gpio/gpio.h"

int main(void) {
    Pin_config_t Pin;
    Pin.port = C; // Assuming the LEDs are connected to Port C

    while (1) {
        // Red Light
        Pin.pin = 0;
        Pin.logic = High;
        Pin_logic_init(&Pin);
        _delay_ms(2000);
        Pin.logic = Low;
        Pin_logic_init(&Pin);

        // Yellow Light
        Pin.pin = 1;
        Pin.logic = High;
        Pin_logic_init(&Pin);
        _delay_ms(2000);
        Pin.logic = Low;
        Pin_logic_init(&Pin);

        // Green Light
        Pin.pin = 2;
        Pin.logic = High;
        Pin_logic_init(&Pin);
        _delay_ms(2000);
        Pin.logic = Low;
        Pin_logic_init(&Pin);
    }

    return 0;
}
```

---

## Binary Counter Example

### **Description:**
This example initializes an entire port as output and uses it to display a binary counter. The value of the counter is incremented and displayed on the port with a small delay.

### **Code Example:**

```c
#include "MCAL/gpio/gpio.h"

int main(void) {
    uint8_t counter = 0;
    Port_Direction(C, Output); // Initialize Port C as output

    while (1) {
        Port_Set(C, counter++); // Set the current counter value to Port C
        _delay_ms(100);         // Delay between each increment
    }

    return 0;
}
```

---

### **Explanation:**

1. **Traffic Light Example**:
   - **Pin Configuration**: The pins for Red, Yellow, and Green LEDs are configured one by one.
   - **Logic Levels**: Each LED is turned on (`High`), held for 2 seconds (`_delay_ms(2000)`), and then turned off (`Low`).
   - **Cycle**: This cycle repeats indefinitely, simulating a traffic light.

2. **Binary Counter Example**:
   - **Port Initialization**: The entire port is set to output mode.
   - **Counter**: A `uint8_t` counter variable is incremented in each loop iteration.
   - **Port Output**: The counter value is output to the port, and the binary representation is displayed on the connected LEDs or output devices.
   - **Delay**: A delay of 100ms is used between increments to slow down the counting.

