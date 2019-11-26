#include<stdio.h>
#include <time.h>

void funcion(void);

int main(void){
  funcion(info);
}

void funcion(void){
  time_t rawtime;
  struct tm *info;
  time(&rawtime);
  info = localtime( &rawtime );
  printf("Current local time and date: %i%i%i-%i:%i:%i\n",dia->tm_year+1900,dia->tm_mon+1,dia->tm_mday,dia->tm_hour,dia->tm_min,dia->tm_sec);
}
