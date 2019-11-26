#include<stdio.h>
#include<string.h>

int minusculas(char cadena[200]);
int mayusculas(char cadena[200]);
int letras(char cadena[200]);
int espacios(char cadena[200]);
int palabras(char cadena[200]);

int main(void){
  char cadena[200];
  printf("Dame una frase: ");
  gets(cadena);
  printf("En su frase hay %i letras minusculas.\n", minusculas(cadena));
  printf("En su frase hay %i letras mayusculas.\n", mayusculas(cadena));
  printf("En su frase hay %i espacios.\n", espacios(cadena));
  printf("En su frase hay %i letras.\n", letras(cadena));
  printf("En su frase hay %i palabras.\n", palabras(cadena));
}

int minusculas(char cadena[]){
  int i,minu=0;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]>='a' && cadena[i]<='z')
      minu++;
  }
  return minu;
}

int mayusculas(char cadena[]){
   int i,mayu=0;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]>='A' && cadena[i]<='Z')
      mayu++;
  }
  return mayu;
}

int letras(char cadena[]){
   int i,letras=0;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]>='a' && cadena[i]<='z' || cadena[i]>='A' && cadena[i]<='Z' )
      letras++;
  }
  return letras;
}

int espacios(char cadena[]){
   int i,espa=0;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]==' ')
      espa++;
  }
  return espa;
}

int palabras(char cadena[]){
   int i,palab=1;
  for(i=0;i<strlen(cadena);i++){
    if(cadena[i]==' ' && cadena[i-1]!=' ')
      palab++;
  }
  return palab;
}
