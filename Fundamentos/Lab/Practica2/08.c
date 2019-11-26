#include<stdio.h>
#include<string.h>

void convertir(char string[], char may[], char min[]);

int main(void){
  char string[200],may[200],min[200];
  printf("Dame una frase: ");
  gets(string);
  convertir(string,may,min);
  printf("Tu frase en mayusculas es: ");
  puts(may);
  printf("Tu frase en minusculas es: ");
  puts(min);
}

void convertir(char string[],char may[],char min[]){
  int i;
  for(i=0;i<strlen(string);i++){
    min[i]=tolower(string[i]);
  } 
  for(i=0;i<strlen(string);i++){
    may[i]=toupper(string[i]);
  }
}
