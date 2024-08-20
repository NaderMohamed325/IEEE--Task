### ARM Fundamentals

#### ARM Instruction Set
- **32-bit (ARM Instructions)**: High performance.
- **16-bit (Thumb Instructions)**: Optimized for high code density.
- **Additional Instruction Sets**: Some cores have additional sets such as VFP (Vector Floating Point) and NEON.

#### Operating Modes and States

**Operating Modes:**
- **Thread Mode**: Primary mode of execution.
- **Handler Mode**: Used for handling exceptions and interrupts.

**Operating States:**
- **Thumb State**: Executes 16-bit Thumb instructions.
- **Debug State**: Used by debuggers.

**Privilege Levels:**
- **Privileged Access (PAL)**
- **Non-Privileged Access (NPAL)**

#### ARM Mode Transitions

- **Reset**: Enters Thread mode.
- **Interrupt**: Switches from Thread mode to Handler mode.
- **Software Exception**: Handler mode takes control.
- **Debugger**: Can force entry into Debug state.

**State Transitions:**
- **Thread Mode**: User level, can be NPAL or PAL.
- **Handler Mode**: Always PAL.
- **Thumb State ↔ 32-bit State**
- **Debug State ↔ Halt State**

#### Registers

**General Purpose Registers (GPR):**
- **R0 - R7**: Low registers.
- **R8 - R12**: High registers.

**Special Registers:**
- **R13 (SP)**: Stack Pointer (shadow register).
  - Two stack pointers: MSP (Main Stack Pointer) and PSP (Process Stack Pointer).
- **R14 (LR)**: Link Register, stores the return address of a function.
- **R15 (PC)**: Program Counter.
- **MSR**: Special purpose registers.
- **PSP**: Process Stack Pointer for user-level operations.

**Additional Notes:**
- In Thread mode, the Control register determines whether the thread is running with privileged or unprivileged access.
- Handler mode always runs with privileged access.

#### T-bit (Thumb Bit) in EPSR (Execution Program Status Register)
- **T-bit**: Indicates whether the processor is in Thumb state (T=1) or ARM state (T=0).
- **Thumb State**: Supports a compact instruction set, improving code density.

**Mask Registers:**
- **Base Priority Mask Register**: Defines the priority threshold for interrupts.
- **Priority Mask Register**: Disables all interrupts except for hard faults and non-maskable interrupts.
- **Fault Mask Register**: Used to disable all interrupts except for non-maskable interrupts.

**Cortex-M4:**
- Has control over a new element, the Floating Point Unit (FPU).

#### Thumb / ARM / Thumb-2 Instructions

- **ARM (T=0)**: 
  - 32-bit powerful instruction set.
  - Supports 58 instructions.
- **Thumb (T=1)**: 
  - 16-bit instructions, 2-cycle execution.
  - Supports 30 instructions.
  - Optimized for high code density.
- **Thumb-2**: 
  - Hybrid instruction set (16-bit and 32-bit instructions).
  - No state switching required.
  - Provides easier, more efficient, and better-performing instruction sets.
  - Achieves 98% of ARM performance and 125% of Thumb's code density.
