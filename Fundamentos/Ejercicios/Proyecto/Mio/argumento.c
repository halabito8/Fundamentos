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
}TipoUs;

void Imprime(TipoUs *Inicio);
void BorrarLista(TipoUs *Inicio);
void leer(TipoUs **Inicio);
void copiar(TipoUs *Inicio);
void argumento(char parg[200],TipoUs *Inicio);
void Creadores(int hola);
void Help(int hola);
void Tres_Argumentos(int hola);


int main(int argc,char *argv[]){
  TipoUs *primero;
  int narg;
  char parg[200];
  leer(&primero);
  if(argc>2){//si hay mas de dos argumentos te dice q no se puede correr asi.
    printf("Asi no se corre.\n");
    exit(1);
  }
  if(argc==2){//en caso que sean sean dos argumentos pega el segundo argumento en otra cadena y se va comparar que tipo de argumento puso.
    strcpy(parg,argv[1]);
    argumento(parg,primero);
  }
  else
    printf("Se corre todo.\n");
  copiar(primero);
  BorrarLista(primero);
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

void BorrarLista(TipoUs *Inicio){
  TipoUs *temp;
  temp=Inicio;
  while(temp!=NULL){
    Inicio=Inicio->ptrsig;
    free(temp);
    temp=Inicio;
  }
}

void argumento(char parg[200],TipoUs *Inicio){
  int hola;
  char usu[10],crea[10],help[10];
  strcpy(usu,"-usu");//son todas las opciones posibles.
  strcpy(crea,"-c");
  strcpy(help,"-h");
  if(strcmp(usu,parg)==0)//va a comparar todas la opciones posibles
    Imprime(Inicio);
  else if(strcmp(crea,parg)==0)
    Creadores(hola);
  else if(strcmp(help,parg)==0)
    Help(hola);
  else//si no se corrio bien te dice como se puede correr y cuales son las posibilidades.
    Tres_Argumentos(hola);
}

void Creadores(int hola){
  system ("clear");
  printf ("     Programa creado por: \n");
  printf ("      David Halabe Husny \n");
  printf ("     Rafael Melgoza Romero \n");
  printf (" Maria Fernanda Sakai Salazar \n");
}

void Help(int hola){
  system ("clear");
  printf ("Bienvenido a la pantalla de ayuda \n");
  printf ("\n");
  printf ("Funcionamiento del programa: \n");
  printf ("- Para poder ingresar a tu cuenta deberas ingresar tu usuario de la manera: **** \n");
  printf ("- Una vez ingresado al programa podras hacer las siguientes cosas: \n");
  printf ("   - Rentar una bicicleta \n");
  printf ("   - Estacionar una bicicleta \n");
  printf ("   - Mostrar saldo \n");
  printf ("- Para rentar o dejar una bicicleta deberas ingresar la estacion que tengas mas cercana, para poder revisar si hay bicicletas disponibles o lugares disponibles, de acuerdo a lo necesario. \n");
  printf ("- Si deseas rentar una bicicleta: \n");
  printf ("   - El sistema revisara si no tienes una bicicleta en renta, recuerda que no puedes rentar dos unidades a la vez. \n");
  printf ("   - EL sistema te dira si hay bicicletas disponibles, de ser asi te dara la placa de la misma y te habilitara agarrarla. \n");
  printf ("   - Recuerda que tienes un maximo de 30 minutos por renta, por lo que se te aconseja buscar de antemano las estaciones mas cercanas a tu destino. \n");
  printf ("\n");
  printf ("- Si deseas dejar una bicicleta: \n");
  printf ("   - El sistema revisara si hay lugares disponibles para que puedes dejar la bicicleta, de no haber, te dira la estacion mas cercana para que puedas dejarla \n");
  printf ("\n");
  printf ("Reglamento: \n");
  printf ("- Cada renta de bicicleta tendra una duración maxima de 30 minutos, si por alguna razon rebasas este tiempo tendras que pagar una multa de 500 pesos. \n");
  printf ("- Para dejar una bicicleta debes asegurarte que haya espacios de antemano, es tu responsabilidad dejarla a tiempo \n");
}

void Tres_Argumentos(int hola){
  system ("clear");
  printf ("Recuerda que solo ṕuedes correr el programa de las siguientes maneras: \n");
  printf ("- Bicirenta.exe -h (Esta es la forma de accesar al menu de ayuda) \n");
  printf ("- Bicirenta.exe -c (Despliega los creditos de los desarrolladores del sistema) \n");
  printf ("- Bicirenta.exe -usu (despliega el listado de todos los usuarios de servicio) \n");
  printf ("- Bicirenta.exe (Para correr el programa de forma natural) \n");
}


