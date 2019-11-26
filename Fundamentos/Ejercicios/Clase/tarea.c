#include <stdio.h>

int main (void){
  int x, k=1, array[100], num,  valor, j, i;
  do{
    printf("Cuantos numeros va a introducir (entre 1 y 100)? ");
    scanf("%i", &x);
    if ((x<0)||(x>100))
      printf ("Porfavor introduzca un numero entre 1 y 100.");
    }while((x<0)||(x>100));
    for(i=0;i<x;i++){
      printf("Cual es el valor numero %i? ", k);
      scanf("%i", &num);
      k++;
      while((i<x)&&(num>array[i]))
        i++;
      if(i<x){
        for(j=x;j>i;j--)
          array[j]=array[j-1];
      }
      array[i]=num;
      x++;
      for(i=0;i<x;i++)
        printf("%i, ", array[i]);
      printf("\n");
  }
}
