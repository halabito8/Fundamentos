#include<stdio.h>
#include<string.h>

void invertir(char cadena[200]);

int main (void){
  char frase[200];
  printf("Dame un frase: ");
  gets(frase);
  printf("Tu frase invertida es: ");
  invertir(frase);
  printf("\n");
}

void invertir(char cadena[200]){
  if(*cadena!='\0')
    invertir(cadena+1);
    printf("%c", *cadena);
  
}
