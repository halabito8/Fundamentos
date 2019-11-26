#include<stdio.h>



int main (void){
	int a = 5;
	int* b = NULL;
	printf("Variable: %i\n", a);
	printf("Apuntador: %p\n", &a);

	b = &a;
	printf("B: %i\n", *b);
	*b = 10;
	printf("Variable: %i\n", a);
	printf("Apuntador: %p\n", &a);
}

  

