#include<stdio.h>
#include<math.h>
#include<string.h>

void imprimir(char cadena[]);

int main (void){
  char string[200];
  printf("Dame una frase: ");
  gets(string);
  imprimir(string);
}

void imprimir(char cadena[]){
  int i;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]!= ' ' && cadena[i]!='\0')
      printf("%c", cadena[i]);
    if(cadena[i]==' ')
      printf("\n");
  }
  printf("\n");
}
