#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct defdato{
  int dato;
  struct defdato *sig;
}tipodato;

void InsertaInicio(tipodato **Inicio, int numero);
void Imprime(tipodato *Inicio);
void BorrarLista(tipodato *Inicio);
void InsertaFin(tipodato **Inicio, int numero);

int main(void){
  tipodato *primero=NULL;
  int valor;
  printf("Inserte numeros(letra para terminar)\n");
  while(scanf("%i",&valor)==1)
    InsertaFin(&primero, valor);
  Imprime(primero);
  BorrarLista(primero);
}


void InsertaInicio(tipodato **Inicio, int numero){
  tipodato*temp;
  temp=(tipodato*)malloc(sizeof(tipodato));
  temp->dato = numero;
  temp->sig = *Inicio;
  *Inicio = temp;
}


void Imprime(tipodato *Inicio){
  float promedio=0,insertados=0;
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL){
    promedio=promedio+(temp->dato);
    insertados++;
    temp=temp->sig;
  }
  printf("El promedio es: %.2f\n",promedio/insertados);
}


void BorrarLista(tipodato *Inicio){
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL){
    Inicio=Inicio->sig;
    free(temp);
    temp=Inicio;
  }
}


void InsertaFin(tipodato **Inicio, int numero){
  tipodato *temp, *temp2;
  temp=(tipodato*)malloc(sizeof(tipodato));
  temp->dato=numero;
  temp->sig=NULL;
  if(*Inicio!=NULL){
    temp2=*Inicio;
    while(temp2->sig!=NULL)
      temp2= temp2->sig;
    temp2->sig=temp;
    }
  else
    *Inicio=temp;
}
