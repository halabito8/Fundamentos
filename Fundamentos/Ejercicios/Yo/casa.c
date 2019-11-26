#include<stdio.h>

int main(void){
  int base,i,j;
  printf("De cuanto quieres la base de la casa? ");
  scanf("%i", &base);
  for(i=1;i<=base;i++){
    for(j=0;j<i;j++)
      printf("*");
    printf("\n");
  }
  i=0;
  while(i<base){
    printf("-");
    i++;
  }
  printf("\n");
  for(i=0;i<base;i++){
    for(j=0;j<base;j++)
      printf("*");
    printf("\n");
  }
}
