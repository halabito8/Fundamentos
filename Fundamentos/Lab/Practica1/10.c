#include<stdio.h>

int main(void){
  int a, b, op;
  a = 1;
  b = 2;
  printf ("\tSeleccione una opcion: \n");
  printf ("1. Numeros pares.\n");
  printf ("2. Numeros impares.\n");
  printf ("Opcion: ");
  scanf ("%i", &op);
  switch (op){
    case 1: for (b=2;b<201;b=b+2){
              printf ("El valor es: %i\n", b);
            }
	      break;
    case 2: for (a=1; a<200;a=a+2){
	      printf("el valor es: %i\n", a);
	    }
	      break;
    default: printf ("Opcion no disponible\n A\t D\t I\tO\tS\n");
	       break;
  }
}

