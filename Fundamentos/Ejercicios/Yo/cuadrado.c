#include<stdio.h>

int main(void){
  int x,y,z;
  printf("Que largo quieres el cuadrado? ");
  scanf("%i", &x);
  for(y=0;y<x;y++){
    for(z=0;z<x;z++)
      printf("* ");
    printf("\n");
  }
}
