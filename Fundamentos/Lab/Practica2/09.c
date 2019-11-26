#include<stdio.h>
#include<string.h>

void espacios(char string[], int array[], int *j);
void cambiar(char string[],int array[],int j);

int main(void){
  char string[200];
  int array[200],i,j=0;
  printf("Dame una frase: ");
  gets(string);
  espacios(string,array,&j);
  for(i=0;i<strlen(string);i++){
    string[i]=tolower(string[i]);
  }
  cambiar(string,array,j);
  puts(string);
}

void espacios(char string[], int array[], int *j){
  int i;
  for(i=0;i<strlen(string);i++){
    if(string[i]==' '){
      array[*j]=i;
      (*j)++;
    }
  }
}

void cambiar(char string[],int array[],int j){
  int i,k;
  string[0]=toupper(string[0]);
  k=strlen(string)-1;
  string[k]=toupper(string[k]);
  for(i=0;i<j;i++){
    string[(array[i])-1]=toupper(string[(array[i])-1]);
    string[(array[i])+1]=toupper(string[(array[i])+1]);
  }
}
