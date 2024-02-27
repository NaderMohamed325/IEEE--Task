# Startup Code for [STM32 ARM CORTEX-4 Linkerscript and startupcode]

## Description

This repository contains the startup code for [STM32 ARM CORTEX-4 Linkerscript and startupcode]. The startup code initializes the microcontroller, sets up the vector table, and performs essential setup tasks before transferring control to the main application.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)



## Getting Started

### Prerequisites

Make sure you have the following tools installed on your system:

- [Arm GNU Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)


You should know Makefile and linkerscript syntax
For more details, refer to the [startup.c](https://github.com/NaderMohamed325/IEEE--Task/blob/main/Stm32/startup.c) and [linker.ld](https://github.com/NaderMohamed325/IEEE--Task/blob/main/Stm32/linker.ld) files.

### Installation
1. Clone the repository:

    ```bash
    git clone https://github.com/NaderMohamed325/IEEE--Task.git
    ```

2. Navigate to the project directory:

    ```bash
    cd IEEE--Task
    ```

3. Build the project using make:

    ```bash
    make all
    ```



