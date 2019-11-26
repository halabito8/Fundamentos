#include<stdio.h>

int main(void){
  int a,b,c;
  b=0;
  c=0;
  do{
    printf ("Introduzca un numero: ");
    scanf ("%i", &a);
    b=b+a;
    c++;
  }while(c<10);
  printf ("La suma de los diez numeros introducidos es: %i\n", b);
}
