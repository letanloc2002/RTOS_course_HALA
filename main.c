#include <stdint.h>
#include "oskernel.h"


uint32_t i0,i1,i2;
void Task0(){
	while(1)
		i0++;

}
void Task1(){
	while(1)
		i1++;

}
void Task2(){
	while(1)
		i2++;

}
int main (){
	osKernelAddThread(Task0,Task1,Task2);
	osKernelInit();
	while(1){
	
	}

}