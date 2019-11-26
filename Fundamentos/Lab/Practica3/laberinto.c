#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void leerarch(char nombre[],char laberinto[30][30]);
void entrada(char laberinto[30][30],int *xe,int *ye);
void encontrarcamino(char laberinto[30][30],int x,int y,int *caminos,int pasos,int *min,int *i,int *insertados,char cammin[30][30],int xe,int ye,int val);
void imprimir(char laberinto[30][30],int xe,int ye);
void imprimir2(char cammin[30][30]);

int main(int argc,char *argv[]){
  if(argc<2||argc>3){
    printf("Error al correr el programa. Muchos/pocos argumentos.\n");
    exit(0);
  }
  char argumento[200];
  if(argc==3){
    strcpy(argumento,argv[2]);
    if(strcmp(argumento,"-pasos")!=0){
      printf("Error, opcion incorrecta.\n");
      exit(0);
    }
  }
  char nombre[200];
  strcpy(nombre,argv[1]);
  char laberinto[30][30]={' '},cammin[30][30];
  int i=0,x=1,y=1,caminos=0,pasos=0,min=99999,insertados=0,xe=0,ye=0,val=argc;
  leerarch(nombre,laberinto);
  entrada(laberinto,&xe,&ye);
  x=xe;
  y=ye;
  encontrarcamino(laberinto,x,y,&caminos,pasos,&min,&i,&insertados,cammin,xe,ye,val);
  imprimir(laberinto,xe,ye);
  imprimir2(cammin);
  printf("Hay %i caminos.\n",caminos);
  printf("El camino mas optimo es de %i pasos.\n",min);
}

void entrada(char laberinto[30][30],int *xe,int *ye){
  *xe=0;
  *ye=0;
  while(laberinto[*xe][*ye]!='E'){
    (*xe)++;
    if(laberinto[*xe][*ye]=='\0'){
      (*ye)++;
      *xe=0;
    }
  }
}

void encontrarcamino(char laberinto[30][30],int x,int y,int *caminos,int pasos,int *min,int *i,int *insertados,char cammin[30][30],int xe,int ye,int val){
  int jn;
  if(laberinto[x][y]==laberinto[xe][ye])
    laberinto[x][y]='E';
  else{
    laberinto[x][y]='.';
    if(val==3){
      imprimir(laberinto,xe,ye);
      for(jn=0;jn<500000000;jn++);
    }
  }
  int kl,gf;
  if(laberinto[x+1][y]==' '){
    encontrarcamino(laberinto,x+1,y,caminos,pasos+1,min,i,insertados,cammin,xe,ye,val);
    }
  if(laberinto[x-1][y]==' '){
    encontrarcamino(laberinto,x-1,y,caminos,pasos+1,min,i,insertados,cammin,xe,ye,val);
    } 
  if(laberinto[x][y+1]==' '){
    encontrarcamino(laberinto,x,y+1,caminos,pasos+1,min,i,insertados,cammin,xe,ye,val);
    }
  if(laberinto[x][y-1]==' '){
    encontrarcamino(laberinto,x,y-1,caminos,pasos+1,min,i,insertados,cammin,xe,ye,val);
    }
  if(laberinto[x+1][y]=='S'||laberinto[x-1][y]=='S'||laberinto[x][y+1]=='S'||laberinto[x][y-1]=='S'){
    (*caminos)++;
    if(pasos<*min){
      *min=pasos;
      for(kl=0;kl<30;kl++){
        for(gf=0;gf<30;gf++)
          cammin[kl][gf]=laberinto[kl][gf];
      }
    }
  }
  laberinto[x][y]=' ';
  if(val==3){
    imprimir(laberinto,xe,ye);
    for(kl=0;kl<500000000;kl++);
  }
}

void imprimir(char laberinto[30][30],int xe,int ye){
  int i,j;
  system("clear");
  for(i=0;i<30;i++){
    for(j=0;j<30;j++){
      laberinto[xe][ye]='E';
      putchar(laberinto[i][j]);
    }
  }
  putchar('\n');
}

void imprimir2(char cammin[30][30]){
  int i,j;
  printf("Laberinto resuelto:\n");
  for(i=0;i<30;i++){
    for(j=0;j<30;j++)
      putchar(cammin[i][j]);
  }
  putchar('\n');
}

void leerarch(char nombre[],char laberinto[30][30]){
  FILE *laber;
  laber=fopen(nombre,"rt");
  char a;
  int i=0,j=0;
  if(laber!=NULL){
    while(!feof(laber)){
      fread(&a,sizeof(char),1,laber);
      laberinto[i][j]=a;
      if(a=='\n'){
        i++;
        j=-1;
      }
      j++;
    }
  fclose(laber);
  }
  else{
    printf("El archivo no contiene nada.\n");
    exit(0);
  }
}
