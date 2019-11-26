#include<stdio.h>
#include<math.h>
#include<string.h>

void Inserta (float Lista [], float Numero, int *Insertados);
void calcular (float lista[], float intro, float *media);
void Imprime (float Lista [], int Insertados, float media);

int main (void){
  int  Introducidos, i, k;
  float Numeros [100], media, Valor, x;
  k=1;
  Introducidos=0;
  do{
    printf ("Cuantas temperaturas va a introducir (entre 5 y 100)? ");
    scanf ("%f", &x);
    if ((x>100)||(x<5))
      printf ("Favor de poner un valor dentro de los parametros.\n");
    }while ((x>100)||(x<5));
  for(i=0;i<x;i++){
    printf ("Cual es la temperatura numero %i? ", k);
    scanf ("%f", &Valor);
    k++;
    Inserta (Numeros, Valor, &Introducidos);
    }
  calcular (Numeros, Introducidos, &media);
  Imprime(Numeros, Introducidos, media);
}

void Inserta (float Lista [], float Numero, int *Insertados){
  int i, j;
  i=0;
  while ((i<*Insertados)&&(Numero>Lista[i]))
    i++;
  if(i<*Insertados){
    for (j=*Insertados;j>i;j--)
      Lista [j] = Lista [j-1];
    }
  Lista[i]=Numero;
  (*Insertados)++;
}

void calcular (float lista[], float intro, float *media){
  int i;
  float suma=0;
  for(i=0;i<intro;i++){
    suma=suma+lista[i];
  }
  *media=suma/intro;
}


void Imprime (float Lista [], int Insertados, float media){
  int i;
  printf("El valor menor es: %.2f\n", Lista[0]);
  printf("El valor mayor es: %.2f\n", Lista[Insertados-1]);
  printf("La media es: %.2f\n", media);
  printf("Estos valores son iguales o estan arriba de la media: ");
  for(i=0;i<Insertados;i++){
    if(Lista[i]>=media){
      if(Lista[i]!=Lista[Insertados-1])
        printf("%.2f, ", Lista[i]);
      else
        printf("%.2f.\n", Lista[i]);
    }
  }
}
