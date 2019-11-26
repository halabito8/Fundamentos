#include<stdio.h>

int main(void){
  int a,b,c,aux;
  printf ("Introduzca A:");
  scanf ("%i", &a); 
  printf ("Introduzca B:");
  scanf ("%i", &b);
  printf ("Introduzca C:");
  scanf ("%i", &c);
  aux = a;
  a = c;
  c = b;
  b = aux;
  printf ("El valor de A intercambiado con C es:%i\n", a );
  printf ("El valor de B intercambiado con A es:%i\n", b );
  printf ("El valor de C intercambiado con B es:%i\n", c );
}

