#include<stdio.h>


int main (void){
int a,b,c,d,e,f,g,h,i,j;
 printf ("Introduzca diez numeros, separados por comas. \n Los numeros introducidos son:");
  scanf ("%i , %i , %i , %i , %i , %i , %i , %i , %i , %i", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);

int tp,ti,sump,sumi;
float mi;
  ti = 0;
  tp = 0;
  sumi = 0;
  sump = 0;
  if (a%2 > 0)
    {ti = ti+1;
      sumi = sumi+a;}
  else
    {tp = tp+1;
      sump = sump+a;}
   if (b%2 > 0)
    {ti = ti+1;
      sumi = sumi+b;}
  else
    {tp = tp+1;
      sump = sump+b;}
   if (c%2 > 0)
    {ti = ti+1;
      sumi = sumi+c;}
  else
    {tp = tp+1;
      sump = sump+c;}
      if (d%2 > 0)
    {ti = ti+1;
      sumi = sumi+d;}
  else
    {tp = tp+1;
      sump = sump+d;}
     if (e%2 > 0)
    {ti = ti+1;
      sumi = sumi+e;}
  else
    {tp = tp+1;
      sump = sump+e;}
        if (f%2 > 0)
    {ti = ti+1;
      sumi = sumi+f;}
  else
    {tp = tp+1;
      sump = sump+f;}  
  if (g%2 > 0)
   {ti = ti+1;
      sumi = sumi+g;}
  else
    {tp = tp+1;
      sump = sump+g;}
   if (h%2 > 0)
    {ti = ti+1;
      sumi = sumi+h;}
  else
    {tp = tp+1;
      sump = sump+h;}
      if (i%2 > 0)
    {ti = ti+1;
      sumi = sumi+i;}
  else
    {tp = tp+1;
      sump = sump+i;}
         if (j%2 > 0)
    {ti = ti+1;
      sumi = sumi+j;}
  else
    {tp = tp+1;
      sump = sump+j;}

  mi= sumi/ti;
  printf ("El total de pares en la funcion son: %i \n", tp);
  printf ("Los pares suman: %i \n", sump);
  printf ("El total de impares en la funcion son: %i \n", ti);
  printf ("La media de los impares es: %f \n", mi);
}
