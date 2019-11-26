#include<stdio.h>

int main(void){
  double a, kg, g;
  printf ("Introduzca su peso en libras: ");
  scanf ("%lf", &a);
  kg = a*0.453592;
  g = 1000*kg;
  printf ("Su peso en kilogramos es: %lf\t Y en gramos es: %lf \n", kg, g);
}
