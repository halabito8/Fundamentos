#include<stdio.h>
#include<string.h>

void espacios(char string[], int array[], int *j);
void imprimir(char string[], int array[], int j);

int main (void){
  char string[200];
  int j, array[200];
  j=0;
  printf("Dame una frase: ");
  gets(string);
  espacios(string, array, &j);
  imprimir(string, array, j);
}

void espacios(char string[], int array[], int *j){
  int i;
  for(i=strlen(string);i>0;i--){
    if(string[i]==' '){
      array[*j]=i;
      (*j)++;
    }
  }
}

void imprimir(char string[], int array[], int j){
  int i, k;
  for(i=0;i<j;i++){
    if(i==0){
      for(k=array[i]+1;k<strlen(string);k++)
        printf("%c", string[k]);
    }
    else
      for(k=array[i]+1;string[k]!=' ';k++)
        printf("%c", string[k]);
      printf(" ");
  }
  for(i=0;string[i]!=' ';i++)
    printf("%c", string[i]);
  printf("\n");
}
