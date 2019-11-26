#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct defUsuarios{
char Nombre[200];
char Direccion[200];
char PW[20];
int long TC;
int NumUs;
int Bandera;
int NumB;
struct defUsuarios *ptrsig;
}TipoUs;//estructura donde se guardan todos los datos de los usuarios

void BorrarLista(TipoUs *Inicio);
void Imprime(TipoUs *Inicio);
void leer(TipoUs **Inicio);
void copiar(TipoUs *Inicio);//copia los datos a un archhivo externo y borra la lista dinamica para liberar espacio
void alta(TipoUs **Inicio);//da de alta a los usuarios
void baja(TipoUs **Inicio);

int main(void){
  TipoUs *primero=NULL;
  int opcion,usuarios=1000;
  char op;
  leer(&primero);
  do{
  printf("1. alta\n2. baja\n3. imprime\n");
  scanf("%i",&opcion);
    switch(opcion){
      case 1: alta(&primero);
        break;
      case 2: baja(&primero);
        break;
      case 3:Imprime(primero);
        break;
      default: printf("opcion no disponible\n");
        break;
    }
    printf(".");
    __fpurge(stdin);
    scanf("%c",&op);
  }while(op=='y');
  copiar(primero);
  BorrarLista(primero);
}

void baja(TipoUs **Inicio){
  int us;
  TipoUs *temp,*temp2;
  temp=*Inicio;
  printf("Que usuario quieres dar de baja? ");
  __fpurge(stdin);
  scanf("%i",&us);
  while(temp!=NULL&&temp->NumUs!=us)//busca el usuario que se quiere borrar.
    temp=temp->ptrsig;
  if(temp==NULL)//si no se encuentra el usuario, no hace nada.
    printf("Usuario no existente\n");
  else{//si si lo encontro lo borra
    if(temp==*Inicio){//si esta al comienzo cambia el inicio a la siguiente estructura.
      temp2=temp->ptrsig;
      *Inicio=temp2;
      free(temp);
    }
    else if(temp->ptrsig==NULL){//si esta al final pone al penultimo elemento su pointer NULL.
      temp2=*Inicio;
      while(temp2->ptrsig!=temp)
        temp2=temp2->ptrsig;
      temp2->ptrsig=NULL;
      free(temp);
    }
    else{//si esta en medio se salta ese elemento.
      temp2=*Inicio;
      while(temp2->ptrsig!=temp)
        temp2=temp2->ptrsig;
      temp2->ptrsig=temp->ptrsig;
      free(temp);
    }
  }
}

void BorrarLista(TipoUs *Inicio){
  TipoUs *temp;
  temp=Inicio;
  while(temp!=NULL){
    Inicio=Inicio->ptrsig;
    free(temp);
    temp=Inicio;
  }
}

void Imprime(TipoUs *Inicio){
  TipoUs *temp;
  temp=Inicio;
  printf("Usuarios:\n");
  while(temp!=NULL){
    printf("%i\n",temp->NumUs);
    temp=temp->ptrsig;
  }
}

void leer(TipoUs **Inicio){
  char string[200];
  TipoUs *temp,*temp2;
  FILE *usuarios;
  usuarios=fopen("us.txt","r");
  if(usuarios!=NULL){
    while(fgets(string,198,usuarios)!=NULL){
      temp=(TipoUs*)malloc(sizeof(TipoUs));
      strcpy(temp->Nombre,string);
      temp->Nombre[strlen(temp->Nombre)-1]='\0';
      fgets(temp->Direccion,198,usuarios);
      temp->Direccion[strlen(temp->Direccion)-1]='\0';
      fscanf(usuarios,"%li\n",&temp->TC);
      fscanf(usuarios,"%i\n",&temp->Bandera);
      fgets(temp->PW,198,usuarios);
      temp->PW[strlen(temp->PW)-1]='\0';
      fscanf(usuarios,"%i\n",&temp->NumUs);
      temp->ptrsig=NULL;
      if(*Inicio!=NULL){
        temp2=*Inicio;
        while(temp2->ptrsig!=NULL)
	  temp2=temp2->ptrsig;
        temp2->ptrsig=temp;
      }
      else
        *Inicio=temp;
    }
  fclose(usuarios);
 }
}


void copiar(TipoUs *Inicio){
  FILE *usuarios;
  TipoUs *temp;
  usuarios=fopen("us.txt","wt");//abre el archivo en sobreescribir para guardar todos los datos en un archivo
  temp=Inicio;
  while(temp!=NULL){
    fputs(temp->Nombre,usuarios);
    fprintf(usuarios,"\n");
    fputs(temp->Direccion,usuarios);
    fprintf(usuarios,"\n");
    fprintf(usuarios,"%li",temp->TC);
    fprintf(usuarios,"\n");
    fprintf(usuarios,"%i",temp->Bandera);
    fprintf(usuarios,"\n");
    fputs(temp->PW,usuarios);
    fprintf(usuarios,"\n");
    fprintf(usuarios,"%i\n",temp->NumUs);//copia todos los datos al documento
    temp=temp->ptrsig;//se mueve a la siguiente estructura
  }
  fclose(usuarios);
}

void alta(TipoUs **Inicio){
  system("clear");//limpia la pantalla  
  TipoUs *temp, *temp2;
  temp=(TipoUs*)malloc(sizeof(TipoUs));//reserva espacio para la nueva estructura
  printf("Nombre?");
  __fpurge(stdin);
  gets(temp->Nombre);
  printf("Direccion del usuario?");
  __fpurge(stdin);
  gets(temp->Direccion);
   printf("Que tarjeta de credito?");
  __fpurge(stdin);
  scanf("%li",&temp->TC);
  printf("Que contrasena quieres poner(maximo 19 caracteres)?\n");
  __fpurge(stdin);
  gets(temp->PW);//lee la contrasena
  printf("Usuario? ");
  __fpurge(stdin);
  scanf("%i",&temp->NumUs);
  do{
    printf("Administrador (0) o usuario (1)?");
    __fpurge(stdin);
    scanf("%i",&temp->Bandera);
    if(temp->Bandera!=0&&temp->Bandera!=1)
      printf("Invalido\n");
  }while(temp->Bandera!=0&&temp->Bandera!=1);
  temp->ptrsig=NULL;
  if(*Inicio!=NULL){
    temp2=*Inicio;
    while(temp2->ptrsig!=NULL)
      temp2= temp2->ptrsig;
    temp2->ptrsig=temp;
  }
  else
    *Inicio=temp;
}
