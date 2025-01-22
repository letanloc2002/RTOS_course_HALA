#include "stm32f446xx.h"


uint8_t osKernelAddThread(void (*task0)(void),void (*task1)(void), void (*task2)(void));
void osKernelInit(void);
void osKernelLaunch(uint32_t quanta);
void osThreadYield();
void osSpinLock_Wait(uint32_t *semaphore);
void osSemaphore_Give(uint32_t *semaphore);
void osSemaphore_Init(uint32_t *semaphore, uint32_t val);
void osCooperative_Wait(uint32_t *semaphore);