#include<stdio.h>

int main(void){
  int x,y=0,z,a;
  printf("Cuanto la base del cuadrado? ");
  scanf("%i", &x);
  while(y<x){
    printf("*");
    y++;
  }
  printf("\n");
  z=x-2;
  y=0;
  while(y<z){
    printf("*");
    a=0;
    while(a<z){
      printf(" ");
      a++;
    }
    printf("*\n");
    y++;
  }
  y=0;
  while(y<x){
    printf("*");
    y++;
  }
  printf("\n");
}
