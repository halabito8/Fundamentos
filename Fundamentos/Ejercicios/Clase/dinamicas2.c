#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct defdato{
  int dato;
  struct defdato *sig;
}tipodato;

void InsertaInicio(tipodato **Inicio, int numero);
void Imprime(tipodato *Inicio);
int buscar(tipodato *Inicio,int numero,int *posicion);
void BorrarLista(tipodato *Inicio);
void InsertaFin(tipodato **Inicio, int numero);

int main(void){
  tipodato *primero=NULL;
  int valor,numero,lugar;
  printf("Inserte numeros(letra para terminar)\n");
  while(scanf("%d",&valor)==1)
    InsertaFin(&primero, valor);
  printf("Que numero buscas? ");
  __fpurge(stdin);
  scanf("%i",&numero);
  if(buscar(primero,numero,&lugar)==0)
    printf("Encontrado!\nEsta en la posicion %i.\n",lugar);
  else
    printf("No esta en la lista.\n");
 // Imprime(primero);
  BorrarLista(primero);
}

int buscar(tipodato *Inicio,int numero,int *posicion){
  tipodato *temp;
  temp=Inicio;
  *posicion=1;
  while(temp!=NULL&&numero!=temp->dato){
    temp=temp->sig;
    (*posicion)++;
  }
  if(temp==NULL)
    return 1;
  else
    return 0;
}

void InsertaInicio(tipodato **Inicio, int numero){
  tipodato*temp;
  temp=(tipodato*)malloc(sizeof(tipodato));
  temp->dato = numero;
  temp->sig = *Inicio;
  *Inicio = temp;
}


void Imprime(tipodato *Inicio){
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL){
    temp=temp->sig;
    }
}


void BorrarLista(tipodato *Inicio)
{
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
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
