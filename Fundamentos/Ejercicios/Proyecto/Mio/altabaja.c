#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct defUsuarios{
char Nombre[200];
char Direccion[200];
char PW[50];
int long TC;
int NumUs;
int Bandera;
int NumB;
struct defUsuarios *ptrsig;
}TipoUs;//estructura donde se guardan todos los datos de los usuarios

void login(TipoUs *Inicio,int *band,int *NumUs);
void BorrarLista(TipoUs *Inicio);
void Imprime(TipoUs *Inicio);
void leer(TipoUs **Inicio,int *ultusu);
void copiar(TipoUs *Inicio,int ultusu);//copia los datos a un archhivo externo y borra la lista dinamica para liberar espacio
void alta(TipoUs **Inicio,int *ultusu);//da de alta a los usuarios
void baja(TipoUs **Inicio);
void bitacora(int accion,int NumUs,int UsBici);

int main(void){
  TipoUs *primero=NULL;
  int opcion,ultusu,op=0,basu,band,NumUs,accion;
  char log;
  leer(&primero,&ultusu);
  login(primero,&band,&NumUs);
  if(band==0){
    do{
      do{
        printf("1. alta\n2. baja\n3. Logout\nOpcion: ");
        __fpurge(stdin);
        basu=scanf("%i",&opcion);
      }while(basu!=1);
      switch(opcion){
        case 1: alta(&primero,&ultusu);
          break;
        case 2: baja(&primero);
          break;
        case 3: printf("Seguro que quieres hacer Logout?  (S/N)\n");
                __fpurge(stdin);
                scanf("%c",&log);
	        if(log=='s'||log=='S'){
	    	  op=1;
		  accion=21;
		  bitacora(accion,NumUs,basu);
		}
                else
	  	  op=0;
           break;
        default: printf("Opcion no disponible\n");
          break;
      }
    }while(op==0);
  }
  else{
    printf("Usuario.\n");
  }
  copiar(primero,ultusu);
  BorrarLista(primero);
}

void bitacora(int accion,int NumUs,int UsBici){
  time_t crudo;
  struct tm *tipotiempo;
  char cadena1[200],cadena2[200];
  FILE *bitacora;
  time(&crudo);
  tipotiempo=localtime(&crudo);
  strftime(cadena1,199,"%Y%m%d-%H:%M:%S",tipotiempo);
  bitacora=fopen("bitacora.txt","a");
  if(accion==20){
    strcpy(cadena2,"Login");
    fprintf(bitacora,"%s %s %i\n",cadena1,cadena2,NumUs);
  }
  else if(accion==21){
    strcpy(cadena2,"Logout");
    fprintf(bitacora,"%s %s %i\n",cadena1,cadena2,NumUs);
  }
  else
    fprintf(bitacora,"%s %i %i\n",cadena1,accion,UsBici);
  fclose(bitacora);
}

void login(TipoUs *Inicio,int *band,int *NumUs){
  int us,bas,accion=20,nada;
  char contra[200];
  TipoUs *temp;
  system("clear");
  do{
    temp=Inicio;
    do{
      printf("Usuario: ");
      __fpurge(stdin);
      bas=scanf("%i",&us);
      if(bas!=1)
        printf("Hay una letra en el usuario.\n");
    }while(bas!=1);
    while(temp!=NULL&&temp->NumUs!=us)//Verifica el usuario con la estructura actual, si no concuerda avanza.
      temp=temp->ptrsig;
    if(temp==NULL)//Si llego al final significa que no existe tal usuario.
      printf("Usuario no existente.\n");
  }while(temp==NULL);
  do{
    printf("Contrasena: ");
    __fpurge(stdin);
    gets(contra);
    if(strcmp(contra,temp->PW)!=0)
      printf("Contrasena incorrecta.\n");
  }while(strcmp(contra,temp->PW)!=0);
  *band=temp->Bandera;
  *NumUs=temp->NumUs;
  bitacora(accion,temp->NumUs,nada);
}

void baja(TipoUs **Inicio){
  int us,accion=302,bas;
  TipoUs *temp,*temp2;
  temp=*Inicio;
  printf("Que usuario quieres dar de baja? ");
  __fpurge(stdin);
  scanf("%i",&us);
  while(temp!=NULL&&temp->NumUs!=us)//busca el usuario que se quiere borrar.
    temp=temp->ptrsig;
  if(temp==NULL)//si no se encuentra el usuario, no hace nada.
    printf("Usuario no existente\n");
  else if(temp->NumB!=0)
    printf("No se puede dar de baja un usuario si tiene una bicicleta rentada\n");
  else if(us==999)
    printf("No se puede dar de baja ese usuario.\n");
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
  bitacora(accion,bas,us);
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

void leer(TipoUs **Inicio,int *ultusu){
  char string[200];
  TipoUs *temp,*temp2;
  FILE *usuarios,*ult;
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
      fgets(temp->PW,49,usuarios);
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
    ult=fopen("ultvar.txt","r");
  if(ult!=NULL){
    fscanf(ult,"%i\n",ultusu);
    fclose(ult);
  }
}


void copiar(TipoUs *Inicio,int ultusu){
  FILE *usuarios,*ult;
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
  ult=fopen("ultvar.txt","w");
  fprintf(ult,"%i",ultusu);
  fclose(ult);
}

void alta(TipoUs **Inicio,int *ultusu){
  system("clear");//limpia la pantalla  
  TipoUs *temp, *temp2;
  int tc,accion=301,bas;
  temp=(TipoUs*)malloc(sizeof(TipoUs));//reserva espacio para la nueva estructura
  printf("Nombre?\n");
  __fpurge(stdin);
  gets(temp->Nombre);
  printf("Direccion del usuario?\n");
  __fpurge(stdin);
  gets(temp->Direccion);
  do{
     printf("Que tarjeta de credito?\n");
    __fpurge(stdin);
    tc=scanf("%li",&temp->TC);
    if(tc!=1)
      printf("En una tarjeta de credito solo hay numeros.\n");
  }while(tc!=1);
  printf("Que contrasena quieres poner(maximo 49 caracteres)?\n");
  __fpurge(stdin);
  gets(temp->PW);//lee la contrasena
  temp2=*Inicio;
  temp->NumUs=++(*ultusu);
  printf("Tu usuario es: %i\n",temp->NumUs);
  do{
    printf("Administrador (0) o usuario (1)?\n");
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
  bitacora(accion,bas,temp->NumUs);
}
