### Clock

- In a microcontroller (MCU), the clocking mechanism is responsible for generating the clock signal
 that synchronizes the operation of the entire system. The clock signal determines the speed at which
 the MCU executes instructions and performs operations
- The clocking mechanism in an MCU typically includes a Clock Control Unit (CCU) that is
  responsible for configuring and controlling the clock sources, as well as generating the clock signals
  that are used throughout the system.

- The clock signal is typically divided into multiple clock domains, each of which can operate at a
 different frequency. This allows the MCU to optimize power consumption and performance by
 adjusting the clock frequency of different subsystems based on their operational requirements.

![image](https://github.com/user-attachments/assets/a4358021-6a1f-4c6e-9c74-3b3c6175aebf)


- The oscillator is the silver coloured part which generates clock pulses .
![image](https://github.com/user-attachments/assets/12e0b408-f638-4f9a-9720-5416b2f6eab8)



### Memory

- In microcontroller programming, base address and offset are used to access memory-mapped
 peripheral registers. The base address is the starting address of the peripheral registers, and the offset
 is the distance between the base address and the register being accessed.

**For Examble**

![image](https://github.com/user-attachments/assets/c49d27b8-4f92-413f-98f3-6c9e96a989e7)

![image](https://github.com/user-attachments/assets/b50adf58-c786-42a2-b402-06129659519f)

### System Bus
- is a single computer bus that connects the major components of a computer system, combining the functions of a data bus to carry information, an address bus to 
 determine where it should be sent or read from, and a control bus to determine its operation.
### Bus Bridges 
- used in embedded systems to divide the memory ranges between different modules
  connected to the bus. A bus bridge is a hardware device that sits between two or more buses in a
  system and translates between the protocols and/or data widths of those buses.
- there are two types of bus interfaces in a microcontroller: Master and Slave. The master is
  the component that initiates the data transfer, whereas the slave is the component that responds to the
  request from the master. The communication between the master and the slave is done through
  signals on the bus.

### AMBA
The Advanced Micro controller Bus Architecture (AMBA) bus protocols is a set of interconnect
specifications from ARM
- that standardizes on chip communication mechanisms between various functional blocks (or IP)
for building high performance SOC designs
- These designs typically have one or more micro controllers or microprocessors along with several
other components
- internal memory or external memory bridge, DSP, DMA, accelerators and various other
peripherals like USB, UART, PCIE, I2C etc
- all integrated on a single chip
