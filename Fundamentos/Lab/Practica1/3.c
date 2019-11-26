#include<stdio.h>

int main(void){
  int a,b,c,d;
  printf ("Introduzca cuatro numeros para compararlos(separados por comas):");
  scanf ("%i, %i, %i, %i", &a, &b, &c, &d);
  if (a>b && a>c && a>d)
   printf("El numero mas grande es:%i\n", a);
  if (b>a && b>c && b>d)
   printf("El numero mas grande es:%i\n", b);
  if (c>a && c>b && c>d)
   printf("El numero mas grande es:%i\n", c);
  if (d>b && d>a && d>c)
   printf("El numero mas grande es:%i\n", d);
}
