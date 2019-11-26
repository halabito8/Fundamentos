#include<stdio.h>
#include<string.h>

void leer(char frase[]);
void pegarreves(char frase[], char frase2[]); 
void imprimir(char frase[], char frase2[]);

int main(void){
  char linea[200], linea2[200];
  leer(linea);
  pegarreves(linea, linea2);
  imprimir (linea, linea2);
}

void leer(char frase[]){
  printf("Dime una frase: ");
  gets(frase);
}

void pegarreves(char frase[],char frase2[]){
  int i, j;
  j=strlen(frase);
  j--;
  for(i=0;i<strlen(frase);i++){
    frase2[i]=frase[j];
    j--;
  }
  frase2[i]='\0';
}

void imprimir(char frase[],char frase2[]){
  printf("Esta es su frase: ");
  puts(frase);
  printf("Esta es su frase al reves: ");
  puts(frase2);
}
