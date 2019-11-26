#include<stdio.h>
#include<string.h>

void eliminar(char cadena[200]);
void poner(char codigo[200],int guion);

int main(void){
  int guion;
  char codigo[200];
  printf("Cual es el codigo?\n");
  gets(codigo);
  eliminar(codigo);
  printf("Cada cuanto quieres el guion?\n");
  scanf("%i",&guion);
  printf("\n");
  if(guion<strlen(codigo)){
    poner(codigo,guion);
    puts(codigo);
  }
  else
    puts(codigo);
}

void eliminar(char cadena[200]){
  int i,j;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]=='-'){
      j=i;
      j++;
      while(j<strlen(cadena)){
        cadena[j-1]=cadena[j];
        j++;
      }
      cadena[strlen(cadena)-1]='\0';
    }
  }
}

void poner(char codigo[200],int guion){
  int i,k;
  char gu[1]="-";
  for(i=strlen(codigo)-guion;i>0;i=i-guion){
    k=strlen(codigo);
    while(k>=i){
      codigo[k+1]=codigo[k];
      k--;
    }
    codigo[strlen(codigo)]='\0';
    codigo[i]=gu[0];
  }
}

