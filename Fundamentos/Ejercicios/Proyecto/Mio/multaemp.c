#include<stdio.h>
#include<string.h>
#include<time.h>

void copiar(char cadena1[200]);
void dormir(char cadena1[200]);

int main(void){
  char cadena1[200];
  dormir(cadena1);
  copiar(cadena1);
}


void dormir(char cadena1[200]){
  time_t crudo;
  struct tm *tipotiempo;
  time(&crudo);
  tipotiempo=localtime(&crudo);
  strftime(cadena1,199,"%Y%m%d-%H:%M:%S",tipotiempo);
  puts(cadena1);
}

void copiar(char cadena1[200]){
  FILE *time;
  time=fopen("stamp.txt","w");
  fputs(cadena1,time);
  fclose(time);
}
