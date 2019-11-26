#include<stdio.h>

int main(void){
  int x,y,z;
  printf("De cuanto quieres la base del triangulo? ");
  scanf("%i", &x);
  for(y=0;y<x;y++){
    z=0;
    while(z<=y){
      printf("*");
      z++;
    }
    printf("\n");
  }
}
