#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct defcomplejo{
  int numero;
  int imaginario;
}tipo_complejo;

typedef struct defimprimir{
  char imp[200];
}tipoimprimir;

void suma(tipo_complejo cosa[2],int *snum,int *sima);
void resta(tipo_complejo cosa[2],int *snum,int *sima);
void multi(tipo_complejo cosa[2],int *snum,int *sima);
void archivo3(int snum,int sima,char nombre[200],char arg[200]);
void archivo2(char nombre[200]);

int main(int argc,char *argv[]){
  tipo_complejo cosa[2];
  char argumento[200],operacion,basura[2],arch[200];
  int snum=0,sima=0;
  if(argc<2||argc>3){
    printf("Asi no se corre.\nSaliendo...\n");
    exit(0);
  }
  if(argc==3){
    strcpy(argumento,argv[1]);
    sscanf(argumento,"[%i%i%c]%c[%i%i%c]",&cosa[0].numero,&cosa[0].imaginario,&basura[0],&operacion,&cosa[1].numero,&cosa[1].imaginario,&basura[1]);
    if(operacion=='+')
      suma(cosa,&snum,&sima);
    else if(operacion=='-')
      resta(cosa,&snum,&sima);
    else if(operacion=='x'||operacion=='X')
      multi(cosa,&snum,&sima);
    else
      printf("No puedo hacer esa operacion.\n");
    printf("El resultado es: %i%+ii\n",snum,sima);
    strcpy(arch,argv[2]);
    strcat(arch,".txt");
    archivo3(snum,sima,arch,argumento);
  }
  if(argc==2){
    strcpy(arch,argv[1]);
    printf("Las operaciones del archivo son:\n");
    archivo2(arch);
  }
}

void suma(tipo_complejo cosa[2],int *snum,int *sima){
  *snum=(cosa[0].numero)+(cosa[1].numero);
  *sima=(cosa[0].imaginario)+(cosa[1].imaginario);
}


void resta(tipo_complejo cosa[2],int *snum,int *sima){
  *snum=(cosa[0].numero)-(cosa[1].numero);
  *sima=(cosa[0].imaginario)-(cosa[1].imaginario);
}

void multi(tipo_complejo cosa[2],int *snum,int *sima){
  int ac=0,bd=0,ad=0,bc=0;
  ac=(cosa[0].numero)*(cosa[1].numero);
  bd=(cosa[0].imaginario)*(cosa[1].imaginario);
  ad=(cosa[0].numero)*(cosa[1].imaginario);
  bc=(cosa[0].imaginario)*(cosa[1].numero);
  *snum=ac-bd;
  *sima=ad+bc;
}

void archivo3(int snum,int sima,char nombre[200],char arg[200]){
  FILE *resultados;
  resultados=fopen(nombre,"at");
  fprintf(resultados,"%s = %i%+ii\n",arg,snum,sima);
  fclose(resultados);
}

void archivo2(char nombre[200]){
  int i=0,j;
  tipoimprimir resp[200];
  FILE *resultados;
  resultados=fopen(nombre,"rt");
  while(!feof(resultados)){
    fgets(resp[i].imp,198,resultados);
    resp[i].imp[strlen(resp[i].imp)-1]='\0';
    i++;
  }
  fclose(resultados);
  for(j=0;j<i;j++)
    puts(resp[j].imp);
}
