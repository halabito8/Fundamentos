#include<stdio.h>
#include<string.h>

void leer(char string[]);
void minusculas(char string[]);
void contar (char string[], int contadora[]);
void imprimir (int contadora[]);

int main(void){
  char string[200];
  int i, j, contadora[26]={0};
  j=0;
  leer (string);
  minusculas (string);
  contar(string, contadora);
  imprimir (contadora);
}

void leer(char string[]){
  printf("Dame una frase, maximo de 199 caracteres: ");
  gets(string);
}

void minusculas(char string[]){
  int i;
  for(i=0;i<strlen(string);i++){
    string[i]=tolower(string[i]);
  }
}

void imprimir(int contadora []){
  int i;
  for(i=0;i<26;i++){
    if(contadora[i]!=0)
      printf("El caracter %c aparece %i veces en la funcion.\n", i+'a', contadora[i]);
  }
}

void contar(char string[], int contadora[]){
  int c, x;
  c=0;
  while(string[c]!='\0'){
    if((string[c]>='a')&&(string[c]<='z'));
      contadora[string[c]-'a']++;
  c++;
  }  
  printf("%i\n", contadora[0]);
}
