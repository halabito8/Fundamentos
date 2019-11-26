#include<stdio.h>
#include<string.h>
#include<time.h>

void dormir(char cadena1[200]);
void copiar(char cadena1[200]);

int main(void){
  char cadena1[200];
  copiar(cadena1);
  dormir(cadena1);
}

void dormir(char cadena1[200]){
  int ret,ret2,hora,min,seg,temp,dif;
  time_t crudo2,principio,final;
  struct tm *cocinado,tipotiempo2,tiempo3;
  double diff;
  char cadena[200];
  time(&crudo2);
  cocinado=localtime(&crudo2);
  strftime(cadena,sizeof(cadena),"%Y%m%d-%H:%M:%S",cocinado);
  strptime(cadena1,"%Y%m%d-%H:%M:%S",&tipotiempo2);
  strptime(cadena,"%Y%m%d-%H:%M:%S",&tiempo3);
  ret=mktime(&tipotiempo2);
  ret2=mktime(&tiempo3);
  diff=difftime(ret2,ret);
  hora=diff/3600;
  dif=diff;
  temp=dif%3600;
  min=temp/60;
  seg=temp%60;
  printf("El tiempo que me dormi fue de %i:%i:%i.\n",hora,min,seg);
  puts(cadena1);
  puts(cadena);
}

void copiar(char cadena1[200]){
  FILE *time;
  time=fopen("stamp.txt","r");
  fgets(cadena1,199,time);
  fclose(time);
}
