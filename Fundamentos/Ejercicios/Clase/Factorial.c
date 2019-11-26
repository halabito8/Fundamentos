#include<stdio.h>

int main (void)
{ int num;
 unsigned  long fac = 1;
    printf ("Introduzca un numero: ");
    scanf ("%d", &num);
    do
      {
	fac=fac*num;
	num--;
	  }
    while (num > 0);
  printf ("El factorial es: %lu\n", fac);
}
