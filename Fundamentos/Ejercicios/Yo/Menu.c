#include<stdio.h>
#define Pi 3.141592

int main (void){
  float area, lado1, lado2;
  int opcion;
  printf ("\t Menu \n");
  printf ("1. Area del circulo \n");
  printf ("2. Area del cuadrado \n");
  printf ("3. Area del rectangulo \n");
  printf ("4. Area del triangulo \n");
  printf ("Opcion:");
  scanf ("%d", &opcion);
  switch (opcion){
    case 1: printf("Introduzca el radio del circulo.");
      scanf ("%f", &lado1);
      area = lado1*Pi;
      printf ("El area es: %f \n", area);
        break;
    case 2: printf ("Introduzca el lado del cuadrado.");
      scanf ("%f", &lado1);
      area = lado1 * lado1;
      printf ("El area es: %f \n", area);
	break;
    case 3: printf ("Introduzca la base y la altura del rectangulo.");
      scanf ("%f %f", &lado1, &lado2);
      area = lado1*lado2;
      printf ("El area es: %f \n", area);
	break;
    case 4: printf ("Introduzca la base y la altura del triangulo.");
      scanf ("%f %f", &lado1, &lado2);
      area = lado1*lado2/2;
      printf ("El area es: %f \n", area);
	break;
    default: printf ("Opcion invalida, adios");
	break;
}
}
