#include <stdint.h>

#define RAM_START 0x20000000U
#define RAM_SIZE  (20*1024)
#define RAM_END  (RAM_START+RAM_SIZE)
#define STACK_START 0x20002800U


extern uint32_t _etext;
extern uint32_t _ebss;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _sdata;

extern void main(void);
void Default_Handler(void){
    while(1);
}
    void Reset_Handler(void) {
//copy data

    uint32_t *SRC = (uint32_t * )(&_etext);
    uint32_t *DEST = (uint32_t * )(&_sdata);
    while (DEST < SRC) {
        *(DEST++) = *(SRC++);
    }
    uint32_t bss_size = (uint32_t)(&_ebss - &_sbss);
    DEST = (uint32_t * )(&_sbss);
    for (uint32_t i = 0; i < bss_size; ++i) {
        *(DEST++) = 0U;
    }


//call the main
    main();

//reset

    while (1) {}

}



void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));

void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t Vectors[] __attribute__((section(".isr_vector"))) =
        {
                STACK_START,
                (uint32_t) &Reset_Handler,
                (uint32_t) &NMI_Handler,
                (uint32_t) &HardFault_Handler,

        };
