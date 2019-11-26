#include<stdio.h>

int main(void){
  int n,ex,p;
  do{
    printf ("Introduzca un numero y su exponente (en ese orden y seprado por comas): ");
    scanf ("%d, %d", &n, &ex);
    if (n<0 || ex < 0)
      printf ("Uno de los numeros es negativo, favor de cambiarlo a positivo.\n");
  }while(n<0||ex<0);
  p=n;
  do{
    p=p*n;
    ex--;
  }while(ex>1);
  printf ("Resultado: %d\n", p);
}
