#include <stm32f10x.h>

int main(){
	GPIOA->CRL|=1<<0;
  GPIOA->ODR|=1<<0;
}