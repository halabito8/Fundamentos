#include<stdio.h>
#include<time.h>

void dormir();

int main(void){
  dormir();
}

void dormir(){
  int ret,ret2;
  time_t crudo,crudo2,principio,final;
  struct tm *tipotiempo,*cocinado,tipotiempo2,tiempo3;
  double diff;
  char cadena[200],cadena1[200];
  time(&crudo);
  tipotiempo=localtime(&crudo);
  strftime(cadena1,sizeof(cadena),"%Y%m%d-%H:%M:%S",tipotiempo);
  puts(cadena1);
  printf("Me duermo...\n");
  sleep(5);
  time(&crudo2);
  cocinado=localtime(&crudo2); 
  strftime(cadena,sizeof(cadena),"%Y%m%d-%H:%M:%S",cocinado);
  strptime(cadena1,"%Y%m%d-%H:%M:%S",&tipotiempo2);
  strptime(cadena,"%Y%m%d-%H:%M:%S",&tiempo3);
  ret=mktime(&tipotiempo2);
  ret2=mktime(&tiempo3);
  diff=difftime(ret2,ret);
  printf("El tiempo que me dormi fue de %f.\n",diff);
  puts(cadena);
}
