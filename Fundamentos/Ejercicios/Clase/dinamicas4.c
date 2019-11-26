#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct defdato{
  int dato;
  struct defdato *sig;
}tipodato;

void Imprime(tipodato *Inicio);
void BorrarLista(tipodato *Inicio);
void InsertaFin(tipodato **Inicio, int numero);

int main(void){
  tipodato *primero=NULL;
  int valor;
  printf("Inserte numeros(letra para terminar)\n");
  while(scanf("%d",&valor)==1){
    InsertaFin(&primero, valor);
    Imprime(primero);
  }
  printf("Los valores introducidos son:\n");
  Imprime(primero);
  BorrarLista(primero);
}

void Imprime(tipodato *Inicio){
  tipodato *temp;
  temp=Inicio;
  printf("Numeros:\n");
  while(temp!=NULL){
    printf("%i\n",temp->dato);
    temp=temp->sig;
  }
  putchar('\n');
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
  if(*Inicio!=NULL){
    temp=*Inicio;
    while(numero>temp->dato&&temp->sig!=NULL)
      temp=temp->sig;
    if(temp==*Inicio){
      temp2=(tipodato*)malloc(sizeof(tipodato));
      temp2->dato=numero;
      temp2->sig=*Inicio;
      *Inicio=temp2;
    }
    else if(temp->sig==NULL){
      temp2=(tipodato*)malloc(sizeof(tipodato));
      temp2->dato=numero;
      temp->sig=temp2;
      temp2->sig=NULL;
    }
    else{
      temp2=(tipodato*)malloc(sizeof(tipodato));
      temp2->dato=numero;
      temp2->sig=temp->sig;
      temp->sig=temp2;
    }
  }
  else{
    temp=(tipodato*)malloc(sizeof(tipodato));
    temp->dato=numero;
    *Inicio=temp;
    temp->sig=NULL;
  }
}
