#include<stdio.h>
#include<string.h>

void leer (char linea[]);
void imprime (char linea[]);
void imprime2 (char *linea);
void reves(char frase[]);

int main(void){
  char frase[200];
  leer (frase);
  printf("La frase es: \n");
  puts(frase);
  imprime(frase);
  imprime2(frase);
  reves(frase);
  return 1;
}

void reves (char frase[]){
  int i;
  for(i=strlen(frase)-1;i>=0;i--)
    printf("%c", frase[i]);
  printf("\n");
}

void leer (char linea[]){
  printf ("Intoduzca una frase de maximo 199 caracteres: \n");
  gets (linea);
}

void imprime (char linea[]){
  int i;
  for(i=0;i<strlen(linea);i++)
    printf("%c", linea[i]);
  printf("\n");
}

void imprime2 (char *linea){
  while(*linea!='\0'){
    printf("%c", *linea);
    linea++;
  }
  printf("\n");
}
