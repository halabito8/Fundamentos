#include<stdio.h>

int main(void){
  long unsigned  num, cont, suma, ex, aux, aux2;
  double  po, po1, aux1; 
  cont=0;
  suma=0;
  printf ("Inserte un numero positivo: ");
  scanf ("%lu", &num);
  ex=num;
  po=num;
  while(ex>0){
      ex=ex/10;
      cont++;
    }
  while(po>=1){
      po=po/10;
    } 
    do{
      po=po*10;
      aux=po;
      aux1=po-aux;
      po1=po;
      po1=po1-aux1;
      aux2=po1;
      suma=suma+(aux2%10);  
    }while(num>po);
  printf ("El numero tiene: %lu digitos\n", cont);
  printf ("La suma de los digitos es: %lu\n", suma); 
}
