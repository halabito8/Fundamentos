#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct defdato
{
  int dato;
  struct defdato *ant;
  struct defdato *sig;
}tipodato;

void InsertaInicio(tipodato **Inicio, int numero);
void Imprime(tipodato *Inicio);
void BorrarLista(tipodato *Inicio);
void InsertaFin(tipodato **Inicio, int numero);

int main ()
{
  tipodato *primero=NULL;
  int valor;
  printf("inserte numeros(letra para terminar)\n");
  while(scanf("%d",&valor)==1)
    InsertaFin(&primero, valor);
  printf("Los valores introducidos son:\n");
  Imprime(primero);
  BorrarLista(primero);
}


void InsertaInicio(tipodato **Inicio, int numero){
  tipodato*temp;
  temp=(tipodato*)malloc(sizeof(tipodato));
  temp->dato = numero;
  temp->ant=NULL;
  temp->sig = *Inicio;
  *Inicio = temp;
}


void Imprime(tipodato *Inicio){
  tipodato *temp;
  temp=Inicio;
  while(temp->sig!=NULL)
    temp=temp->sig;
  while(temp!=NULL){
    printf("%i\n",temp->dato);
    temp=temp->ant;
  }
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
  tipodato *temp,*temp2;
  temp=(tipodato*)malloc(sizeof(tipodato));
  temp->dato=numero;
  temp->sig=NULL;
  if(*Inicio!=NULL){
    temp2=*Inicio;
    while(temp2->sig!=NULL)
      temp2=temp2->sig;
    temp2->sig=temp;
    temp->ant=temp2;
  }
  else{
    *Inicio=temp;
    temp->ant=NULL;
  }
}
