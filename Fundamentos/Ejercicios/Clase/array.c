#include<stdio.h>

int main(void){
  int i, array[2];
  for (i=0; i<2; i++){
    printf("Escribe un numero:");
    scanf("%i", &array[i]);
  }
  for (i=0; i<2; i++){
    printf("Array[%i]: %i\n",i, array[i]);
  }
}
