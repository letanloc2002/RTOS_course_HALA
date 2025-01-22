#include <stdint.h>
#include "osKernel.h"


uint32_t volatile i0,i1,i2;
uint32_t semaphore1,semaphore2;

void Task0(){
	while(1)
	{
		osSpinLock_Wait(&semaphore1);
		i0++;
		 osSemaphore_Give(&semaphore2);
	}
}
void Task1(){
	while(1)
	{
		osSpinLock_Wait(&semaphore2);
		i0++;
		osSemaphore_Give(&semaphore1);
	}
}


void Task2(){
	while(1)
		i2++;
}
int main(){
	osKernelAddThread(Task0, Task1, Task2);
	//osSemaphore_Init(&semaphore1, 1);
	//osSemaphore_Init(&semaphore2, 0);
	osKernelInit();
	while(1){
	
	}
}
