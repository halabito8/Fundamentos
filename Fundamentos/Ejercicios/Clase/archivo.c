#include<stdio.h>
#include<string.h>

void Nombrearchivo (char nombre[200]);

int main(){
  FILE *Archivo;
  char frase[200],narchivo[200];
  Nombrearchivo(narchivo);
  Archivo=fopen(narchivo,"wt");
  printf("Dame tu frase favorita: ");
  gets(frase);
  fprintf(Archivo,"Tu frase favorita es:\n%s\n",frase);
  fclose(Archivo);
}

void Nombrearchivo (char nombre[200]){
  char extension[200];
  printf("Dame el nombre del archivo a crear: ");
  gets(nombre);
  do{
    printf("Que extension quieres (debe de empezar con punto)? ");
    gets(extension);
    if(extension[0]!='.')
      printf("No empieza con punto.\n");
  }while(extension[0]!='.');
  strcat(nombre,extension);
}
