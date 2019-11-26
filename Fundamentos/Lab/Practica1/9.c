#include<stdio.h>

  int main(void){
  char var1, var2;
  printf ("Favor de introducir dos caracteres para comparar (separar por comas): ");
  scanf ("%c, %c", &var1, &var2);
  if (var1>var2)
    printf ("No estan en orden alfabetico.\n");
  else
    printf ("Estan en orden alfabetico.\n");
}
