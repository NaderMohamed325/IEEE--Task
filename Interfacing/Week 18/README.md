# Week 18
- **The pdf contains a revision or a brief about these topics** :
1. **Embedded Systems Concepts**
2. **Embedded Systems Implementation**
3. **System Board - System On Chip**
4. **Embedded Systems Definitions**
5. **Introduction to Embedded Systems**
6. **IC - MPU - MCU - GPU - DSP - SOC - ECU**
7. **Processor Components**
8. **Instruction Life Cycle**
9. **RISC vs CISC**
10. **Types of Memory**
11. **Basic Element of Memory**
12. **Volatile Memory - RAM**
13. **Types of RAM**
14. **SRAM vs DRAM**

# Some examples of embedded systems:
1. **Digital watches**
2. **Washing Machine**
3. **Toys**
4. **Televisions**
5. **Electronic Calculators**

![image](https://github.com/NaderMohamed325/IEEE--Task/assets/112278447/0b7420d2-4df4-432b-b46e-e955b62fb391)
![image](https://github.com/NaderMohamed325/IEEE--Task/assets/112278447/f2b83442-66c3-4d17-9fca-a6590b0ff851)


### . Cache Memory

**Cache Memory** is a small, high-speed storage located close to the CPU that temporarily holds frequently accessed data and instructions. The primary purpose of cache memory is to reduce the time it takes to access data from the main memory. By storing copies of frequently used data and instructions, cache memory significantly speeds up processing times, as it allows the CPU to quickly retrieve this information without the delay of accessing the slower main memory. Caches are typically organized in multiple levels (L1, L2, and sometimes L3), with L1 being the fastest and closest to the CPU.

### . FPU, MPU, and MMU

**FPU (Floating Point Unit)** is a specialized component of a microprocessor designed to perform arithmetic operations on floating-point numbers more efficiently than the general-purpose CPU. FPUs are particularly important in applications requiring a high degree of numerical precision, such as scientific computations and graphics processing.

**MPU (Memory Protection Unit)** is a hardware feature used to enforce access control policies within a microcontroller. It prevents accidental or intentional access to restricted memory regions, thereby enhancing system security and stability. MPUs are essential in embedded systems where critical operations must be protected from potential corruption.

**MMU (Memory Management Unit)** is a hardware component responsible for handling virtual memory and memory protection. The MMU translates virtual addresses to physical addresses, allowing the implementation of features such as paging and segmentation. MMUs are crucial in complex operating systems to manage multiple processes and ensure efficient and secure memory use.

### 5. MCU Architecture

#### Von Neumann vs. Harvard Architecture

- **Von Neumann Architecture**: This architecture uses a single memory space for both instructions and data. The CPU fetches instructions and data over the same bus, which can lead to a bottleneck known as the Von Neumann bottleneck. However, it simplifies the design and allows for more flexible memory use.

- **Harvard Architecture**: This architecture has separate memory spaces and buses for instructions and data, allowing simultaneous access to both. This separation increases the throughput and overall performance of the system, as instructions can be fetched in parallel with data operations.

#### Memory Mapped vs. Port Mapped

- **Memory Mapped I/O**: In this approach, I/O devices are treated as if they are memory locations. The CPU uses standard memory instructions to read from and write to these devices. This method allows for a unified address space but can consume valuable address space.

- **Port Mapped I/O**: Here, I/O devices are assigned distinct addresses separate from the memory address space. Special instructions are used to access these ports. This method conserves memory address space but requires additional CPU instructions for I/O operations.

#### MCU Clock Systems

**MCU Clock Systems** are crucial for the timing and synchronization of operations within a microcontroller. The clock system generates a stable signal that drives the operation of the CPU and other peripherals. Common components include:

- **Internal Oscillators**: These provide a low-cost, built-in clock source but might lack precision and stability.
- **External Crystals/Oscillators**: These offer higher accuracy and stability, often used when precise timing is crucial.
- **Phase-Locked Loops (PLLs)**: These are used to multiply the frequency of the clock signal, enabling higher operational speeds without requiring a high-frequency external source.
- **Clock Dividers**: These generate lower frequency clocks from a higher frequency source, allowing for flexible power management and operation of different system components at varying speeds.
