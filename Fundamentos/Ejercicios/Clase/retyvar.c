#include<stdio.h>
#include<string.h>

int encuentra(char cadena[],char caracter,int *esp);

int main (void){
  char frase[200];
  char letra;
  int en=1;
  printf("Cual es tu frase? ");
  gets(frase);
  printf("Que caracter buscas? ");
  scanf("%c", &letra);
  if(encuentra(frase,letra,&en)){
    printf("Esa letra esta en la frase.\n");
    printf("Su letra esta en el espacio numero %i.\n",en);
  }
  else
    printf("Esa letra no esta en la frase.\n");
}

int encuentra(char cadena[],char caracter,int *esp){
  int i=0;
  while((i<strlen(cadena))&&(caracter!=cadena[i])){
    i++;
    (*esp)++;
  }
  if(i<strlen(cadena))
    return 1;
  else
    return 0;
}
