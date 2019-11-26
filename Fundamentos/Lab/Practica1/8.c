#include<stdio.h>

int main(void){
  char var;
  printf ("Escribe una letra para identificar si es mayuscula o minuscula: ");
  scanf ("%c", &var);
  if (var>= 'A' && var<='Z')
    printf ("El caracter es mayuscula.\n");
  else
    printf ("El caracter es minuscula.\n");
}
