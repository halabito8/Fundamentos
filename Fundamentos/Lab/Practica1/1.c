#include<stdio.h>
#include<ctype.h>

int main(void){
  int a, contar;
  a = 1;
  contar = 0;
  while (a != 0){
    printf ("Inserte un numero (cero para terminar):");
    scanf ("%i", &a);
    if (a == 0)
      break;
    contar++;
   }
    printf ("\nNumeros introducidos: %i\n", contar);
}
