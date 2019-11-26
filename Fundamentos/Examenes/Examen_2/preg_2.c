#include<stdio.h>
#include<string.h>

void LeeTiempoDePistas(int array[10][2],int can);
void Calcula_hh_mm_ss(int array[10][2],int can,int mm,int *mmh,int *hh);
void Calcula_mm_ss(int array[10][2],int can,int *mm,int *ss);
void DespliegaTiempo(int mm,int ss,int hh,int mmh);

int main(void){
  int i,k=1,can,array[10][2],mm=0,ss=0,mmh=0,hh=0;
  do{
    printf("Cuantas canciones va a meter(no mas de 10)? ");
    scanf("%i", &can);
    if(can>10)
      printf("No puedes meter mas de 10.\n");
  }while(can>10);
  LeeTiempoDePistas(array,can);
  Calcula_mm_ss(array,can,&mm,&ss);
  Calcula_hh_mm_ss(array,can,mm,&mmh,&hh);
  DespliegaTiempo(mm,ss,hh,mmh);
}

void LeeTiempoDePistas(int array[10][2],int can){
  int i,k=1;
  printf("Favor de poner el tiempo de en mm:ss!!!\n");
  for(i=0;i<can;i++){
    do{
      printf("Cuanto dura la cancion %i? ",k);
      scanf("%i:%i",&array[i][0],&array[i][1]);
      if(array[i][1]>=60)
	printf("La cancion %i no puede tener mas de 59 segundos.\n",k);
    }while(array[i][1]>=60);
  k++;
  }
}

void Calcula_mm_ss(int array[10][2],int can,int *mm,int *ss){
  int i;
  for(i=0;i<can;i++)
    *mm=(*mm)+array[i][0];
  for(i=0;i<can;i++)
    *ss=(*ss)+array[i][1];
  *mm=*mm+((*ss)/60);
  *ss=*ss%60;
}

void DespliegaTiempo(int mm,int ss,int hh,int mmh){
  printf("El disco tiene un tiempo total de %i:%i.\n",mm,ss);
  printf("El disco tiene un tiempo total de %i:%i:%i.\n",hh,mmh,ss);
}

void Calcula_hh_mm_ss(int array[10][2],int can,int mm,int *mmh,int *hh){
  *hh=*hh+(mm/60);
  *mmh=mm%60;
}
