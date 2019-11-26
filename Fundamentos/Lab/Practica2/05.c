#include<stdio.h>
#include<math.h>
#include<string.h>

void imprimir(char string2[], char string3[]);
void arreglar(char string[], char string2[], char string3[]);

int main (void){
  char string[200], string2[200], string3[200];
  int i;
  printf("Dame una frase para ver si es un palindromo: ");
  gets(string);
  for(i=0;i<strlen(string);i++){
    string[i]=tolower(string[i]);
  }
  arreglar(string, string2, string3);
  imprimir(string2, string3);
}

void imprimir(char string2[],char string3[]){
  if(strcmp(string2,string3)==0)
    printf("Su frase es palindroma.\n");
  else
    printf("Su frase no es palindroma.\n");
}

void arreglar(char string[], char string2[], char string3[]){
  int i,j,l;
  j=0;
  l=0;
  for(i=0;i<strlen(string);i++){
    if(string[i]!=' '){
      string2[j]=string[i];
      j++;
      l++;
    }
  }
  string2[l]='\0';
  j=strlen(string2);
  j--;
  for(i=0;i<strlen(string2);i++){
    string3[i]=string2[j];
    j--;
  }
  string3[l]='\0';
}
