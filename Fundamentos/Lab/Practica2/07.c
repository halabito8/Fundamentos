#include<stdio.h>
#include<string.h>

void designar(char string[], char palabra1[], char palabra3[]);
void imprimir(char palabra1[], char palabra3[]);

int main(void){
  char string[200], palabra1[200], palabra3[200];
  printf("Dame una frase de tres palabras: ");
  gets(string);
  designar(string,palabra1,palabra3);
  imprimir(palabra1,palabra3);
}

void designar(char string[], char palabra1[], char palabra3[]){
  int i,k,j;
  j=0;
  for(i=0;string[i]!=' ';i++){
    palabra1[j]=string[i];
    j++;
  }
  i=strlen(string);
  while(string[i]!=' '){
    i--;
  }
  i++;
  k=0;
  for(j=i;j<strlen(string);j++){
    palabra3[k]=string[j];
    k++;
  }
}

void imprimir(char palabra1[], char palabra3[]){
  printf("%s %s\n", palabra1, palabra3);
}
