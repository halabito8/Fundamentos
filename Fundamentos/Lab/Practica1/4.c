#include<stdio.h>

int main(void){
  int var,mod1,mod2,mod3,mod4;
  do{
    printf ("Favor de insertar un numero para verificar si es primo: ");
    scanf ("%i", &var);
    if (var < 0)
      printf ("Su numero no es positivo, favor de introducir un numero positivo: \n");
  }while(var<0);
  mod1 = var%2;
  mod2 = var%3;
  mod3 = var%5;
  mod4 = var%7;
  if((mod1 && mod2 && mod3 && mod4)>0)
    printf ("El numero %i es primo\n", var);
  else
    printf ("El numero %i no es primo\n", var);
}
