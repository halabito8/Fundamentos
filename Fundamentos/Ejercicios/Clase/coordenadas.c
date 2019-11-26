#include<stdio.h>

typedef struct coordenada{
  int,x,y;
}tipo.coordenada;

void pedir(tipo.coordenada *p1,tipo.coordenada *p2);

int main(void){
  tipo.coordenada punto1,punto2;
  pedir(&punto1,&punto2);
  
}

void pedir(tipo.coordenada *p1,tipo.coordenada *p2){
  printf("Dame las primeras coordenadas(x,y): ");
  scanf("%i,%i",p1->x,p1->y);
  printf("Dame las segundas coordenadas(x,y): ");
  scanf("%i,%i",p2->x,p2->y);
}
