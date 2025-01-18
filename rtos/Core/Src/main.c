#include <stdint.h>
#include "oskernel.h"


uint32_t i0,i1,i2;
uint32_t semaphore1,semaphore2;

void Task0(){
	while(1){
		//task0 inform to task1 that it reach the point
		osSemaphore_Give(&semaphore2);
		//task0 wait task1 for reaching point
		osCooperative_Wait(&semaphore1);
		i0++;

	}
}
void Task1(){
	while(1){
		//task1 wait task0 for reaching point
		osCooperative_Wait(&semaphore2);
		//task1 inform to task0 that it reach the point
		osSemaphore_Give(&semaphore1);
		i1++;
	}
}


void Task2(){
	while(1)
	{
		i2++;
	}
}
int main(){


	osKernelAddThread(Task0, Task1, Task2);
	osSemaphore_Init(&semaphore1, 1);
	osSemaphore_Init(&semaphore2, 0);
	osKernelInit();

	while(1){
	
	}
}
