#include<stdio.h>
#include<time.h>

int main(void){
  time_t empieza,acaba;
  struct tm tiempo;
  double dift;
  printf("Empieza el programa...\n");
  time(&empieza);
  printf("Me duermo...\n");
  sleep(10);
  time(&acaba);
  dift=difftime(acaba,empieza);
  printf("Tiempo de ejecucion: %f\n",dift);
}
