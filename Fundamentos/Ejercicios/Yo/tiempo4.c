#include<stdio.h>
#include<time.h>

int main(void){
  time_t crudo;
  struct tm *tiempo;
  time(&crudo);
  tiempo=localtime(&crudo);
  printf("Esto es daylight: %i\n",tiempo->tm_isdst);
}
