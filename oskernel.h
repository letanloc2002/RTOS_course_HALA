#include "
#include <stdint.h>
uint8_t osKernelAddThread(void (*task0)(void),void (*task1)(void), void (*task2)(void));
void osKernelLaunch(uint32_t quanta);
void osKernelInit(void);