#include<stdio.h>

int main (void){
  float b,h,a;
  printf ("Favor de introducir la base y la altura (es ese orden y sparados por comas):");
  scanf ("%f, %f", &b,&h);
  a = b*h/2;
  printf ("El area es: %f\n", a);
}
