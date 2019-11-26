#include<stdio.h>
#include<math.h>
#include<string.h>

void calcular (int lista[100][2]);
void imprimir (int lista[100][2]);

int main(void){
  int cuadrados[100][2];
  calcular (cuadrados);
  imprimir (cuadrados);
}

void calcular (int lista[100][2]){
  int i, j;
  j=1;
  for(i=0;i<100;i++){
    lista[i][0]= j;
    j++;
  }
  j=1;
  for(i=0;i<100;i++){
    lista[i][1]=j * j;
    j++;
  }
}

void imprimir (int lista[100][2]){
  int i, j;
  printf("Numero Cuadrado\n");
  for(i=0;i<100;i++){
    j=0;
    printf("%i,     ", lista[i][j]);
    j++;
    printf("%i\n", lista[i][j]);
  }
}
