#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Estructuras
typedef struct Bicicletas
{
  int NumB;
  int NumE;
  int NumUs;
  int Rentas;
  char TimeS[100];
  struct Bicicletas *ptrsig;
}TipoBici;

typedef struct Estaciones
{
  int NumE;
  char Nombre[100];
  char Calle_y_Num[100];
  int CP;
  char Ciudad[100];
  struct Estaciones *ptrsig;
  TipoBici *ptrbici;
}TipoEstacion;

typedef struct Usuarios
{
  char Nombre[200];
  char Direccion[200];
  char PW[20];
  int long TC;
  int NumUs;
  int Bandera;
  int multa;
  TipoBici *ptrbici;
  struct Usuarios *ptrsig;
}TipoUs;

//Primer grupo de funciones
void MostrarMenuAdmin(void);
void MostrarMenuUsuario(void);
void Alta_Estacion(TipoEstacion **InicioEst, int *AcumNumE);
void ValidarBajaEstacion(TipoEstacion **InicioEst, TipoUs *InicioUs);
void Baja_Estacion(TipoEstacion **InicioEst, int Est);
void Alta_Bici(TipoEstacion **InicioEst, int *AcumNumB);
void ValidarBajaBici(TipoEstacion **InicioEst);
void Baja_Bicicleta(TipoEstacion *InicioEst, int Est, TipoBici *BuscaBici, int Bici);
void ValidarReasignacion(TipoEstacion **InicioEst);
void Reasignar_Bici(TipoEstacion **InicioEst, int EstO, int EstD, TipoEstacion *Busca2, int Bici);
void TieneBicisAncladas(TipoEstacion *InicioEst,int Est,int *Bicis);
void ImprimeEst(TipoEstacion *InicioEst);
void BorrarListaEst(TipoEstacion *InicioEst);


//Segundo grupo de funciones
void LeerArchivoUs(TipoUs **Inicio);
void Login(TipoUs *InicioUs, int *Bandera, int *NumUs);
void AltaUsuario(TipoUs **Inicio, int *ultusu);//da de alta a los usuarios
void ImprimeUs(TipoUs *InicioUs);
void BajaUsuario(TipoUs **Inicio);
void GuardarArchivoUs(TipoUs *Inicio);//copia los datos a un archivo externo y borra la lista dinamica para liberar espacio
void BorrarListaUs(TipoUs *InicioUs);
void LeerArchivoEst(TipoEstacion **InicioEst);
void GuardarArchivoEst(TipoEstacion *Inicio);
void LeerUltimaVariable(int *AcumNumUs, int *AcumNumE, int *AcumNumB);
void GuardarUltimaVariable(int AcumNumUs, int AcumNumE, int AcumNumB);

//Tercer grupo de funciones
void Argumento(char parg[200],TipoUs *Inicio);
void Creadores();
void Help();
void Error_Ejecucion();

//Cuarto grupo de funciones
void ValidarRentaBici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs);
void ValidarDevolucionBici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs);
void Rentar_Bici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs, int Est);
void Dejar_Bici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs, int EstD, int NumB);
int TieneRenta(TipoUs *InicioUs, int NumUs, int *NumB);

//Quinto grupo de funciones
void GuardarArchivoBiciEst(TipoEstacion *InicioEst);
void GuardarArchivoBiciUs(TipoUs *InicioUs);
void LeerArchivoBiciEst(TipoEstacion **InicioEst);
void LeerArchivoBiciUs(TipoUs **InicioUs);
void saldo(TipoUs *InicioUs,int NumUs);
void bitacora(int accion,int var,int var2);
void MostrarEst(TipoEstacion *BuscaEst);

//MAIN
int main(int argc,char *argv[])
{
  system("clear");
  char Arg[200];//Cadena donde se copia el contenido de argv para ser analizado.
  TipoEstacion *InicioEst= NULL;//Inicio de la lista de estaciones (y por tanto de bicicletas)
  TipoUs *InicioUs= NULL;//Inicio de la lista de usuarios
  int AcumNumE;//Lleva la cuenta de las estaciones creadas. Obtiene del archivo el número correcto.
  int AcumNumB;//Lleva la cuenta de las bicicletas creadas. Obtiene del archivo el número correcto.
  int AcumNumUs;//Lleva la cuenta de los usuarios creados. Obtiene del archivo el número correcto.
  int opcion,i=0;
  int Bandera;//Indica al programa si el usuario es Administrador o Usuario
  int NumUs;//Indica número de usuario para trámite de renta/devolución de bicis
  int accion;//Número de acción que se pasa a la bitácora
  char enter;//Basura para indicar el inicio del programa
  if(argc>2)//Si hay más de dos argumentos indica que no se puede ejecutar así.
    {
      Error_Ejecucion();
    }
  else
    {
      LeerArchivoUs(&InicioUs);
      LeerArchivoEst(&InicioEst);
      LeerArchivoBiciEst(&InicioEst);
      LeerArchivoBiciUs(&InicioUs);
      LeerUltimaVariable(&AcumNumUs,&AcumNumE,&AcumNumB);
      if(argc==2)
        {//en caso que sean sean dos argumentos pega el segundo argumento en otra cadena y compara qué tipo de argumento puso.
          strcpy(Arg,argv[1]);
          Argumento(Arg,InicioUs);
        }
      else
        {
          Creadores();
	  __fpurge(stdin);
	  enter=getchar();
          Login(InicioUs, &Bandera, &NumUs);
	  if(Bandera==0)
            {
              do
                {
                  MostrarMenuAdmin();
                  __fpurge(stdin);
                  scanf("%d",&opcion);
                  switch(opcion)
                    {
                    case 1: Alta_Estacion(&InicioEst, &AcumNumE);
                      break;
                    case 2: ValidarBajaEstacion(&InicioEst, InicioUs);
                      break;
                    case 3: Alta_Bici(&InicioEst, &AcumNumB);
                      break;
                    case 4: ValidarBajaBici(&InicioEst);
                      break;
                    case 5: ValidarReasignacion(&InicioEst);
                      break;
                    case 6: ImprimeEst(InicioEst);
                      break;
                    case 7: AltaUsuario(&InicioUs, &AcumNumUs);
                      break;
                    case 8: BajaUsuario(&InicioUs);
                      break;
                    case 9: i=1;
		      accion=21;
		      bitacora(accion,NumUs,i);
                      system("clear");
                      printf("\n\n\t\tSalida del Sistema\n\n");
                      break;
                    default:printf("\nOpción inválida.Intenta de nuevo\n\n");
                      break;
                    }
                }while(i!=1);
	      }
          else
	  {
              do
                {
                  MostrarMenuUsuario();
                  __fpurge(stdin);
                  scanf("%d",&opcion);
                  switch(opcion)
                    {
                    case 1:ValidarRentaBici(InicioEst,InicioUs,NumUs);
                      break;
                    case 2:ValidarDevolucionBici(InicioEst,InicioUs,NumUs);
                      break;
                    case 3:saldo(InicioUs,NumUs);
                      break;
                    case 4: i=1;
                      system("clear");
                      printf("\n\n\t\tSalida del Sistema\n\n");
                      break;
                    default: system("clear");
		      printf("\nOpción inválida.Intenta de nuevo\n\n");
                      break;
                    }
                }while(i!=1);
	    }
        }
      GuardarArchivoEst(InicioEst);
      GuardarArchivoBiciEst(InicioEst);
      GuardarArchivoBiciUs(InicioUs);
      GuardarArchivoUs(InicioUs);
      GuardarUltimaVariable(AcumNumUs,AcumNumE,AcumNumB);
      BorrarListaEst(InicioEst);
      BorrarListaUs(InicioUs);
    }
}


//PRIMER GRUPO DE FUNCIONES
void Alta_Estacion(TipoEstacion **InicioEst, int *AcumNumE)
{
  int accion=101,var,basura;//Variables usadas para imprimir bitácora
  if((*InicioEst)==NULL)
    {
      system("clear");
      TipoEstacion *Nuevo;
      Nuevo = (TipoEstacion*)malloc(sizeof(TipoEstacion));
      (*AcumNumE)++;
      Nuevo->NumE= *AcumNumE;
      printf("\nCreación de la estación número %d\n\n\n",Nuevo->NumE);
      printf("Introduce el nombre genérico de la estación (max. 100 caracteres)\n");
      __fpurge(stdin);
      gets(Nuevo->Nombre);
      printf("Introduce la calle y número de la estación\n");
      __fpurge(stdin);
      gets(Nuevo->Calle_y_Num);
      do
	{
	  printf("Introduce el código postal de la estación\n");
	  __fpurge(stdin);
	  basura=scanf("%d",&(Nuevo->CP));
	  if(basura!=1)
	    printf("Los códigos postales no tienen letras.\n");
	}while(basura!=1);
      printf("Introduce la ciudad en la que se encuentra.\n");
      __fpurge(stdin);
      gets(Nuevo->Ciudad);
      Nuevo->ptrsig = NULL;
      Nuevo->ptrbici= NULL;
      *InicioEst=Nuevo;
      system("clear");
      printf("\nSe creó correctamente la estación %d\n\n",*AcumNumE);
    }
  else
    {
      system("clear");
      TipoEstacion *Busca;
      Busca=*InicioEst;
      TipoEstacion *Nuevo;
      Nuevo = (TipoEstacion*)malloc(sizeof(TipoEstacion));
      (*AcumNumE)++;
      Nuevo->NumE= *AcumNumE;
      printf("\nCreación de la estación número %d\n\n\n",Nuevo->NumE);
      printf("Introduce el nombre genérico de la estación (max. 100 caracteres)\n");
      __fpurge(stdin);
      gets(Nuevo->Nombre);
      printf("Introduce la calle y número de la estación\n");
      __fpurge(stdin);
      gets(Nuevo->Calle_y_Num);
      do
	{
	  printf("Introduce el código postal de la estación\n");
	  __fpurge(stdin);
	  basura=scanf("%d",&(Nuevo->CP));
	  if(basura!=1)
	    printf("Los códigos postales no tienen letras.\n");
	}while(basura!=1);
      printf("Introduce la ciudad en la que se encuentra\n");
      __fpurge(stdin);
      gets(Nuevo->Ciudad);
      Nuevo->ptrsig = NULL;
      Nuevo->ptrbici= NULL;
      while(Busca->ptrsig != NULL)
        Busca = Busca->ptrsig;
      Busca->ptrsig=Nuevo;
      system("clear");
      printf("\nSe creó correctamente la estación %d\n\n",*AcumNumE);
    }
  var=*AcumNumE;
  bitacora(accion,var,basura);
}

void ValidarBajaEstacion(TipoEstacion **InicioEst, TipoUs *InicioUs)
{
  system("clear");
  int Est;
  int Bandera;//Bandera que permite saber si la estación que se elimina es la única que puede recibir a una bicicleta actualmente rentada
  TipoEstacion *Busca;
  TipoUs *RecorreUs;
  if(*InicioEst!=NULL)
    {
      system("clear");
      printf("Introduce el número de la estación que quieres dar de baja:\t");
      __fpurge(stdin);
      scanf("%d",&Est);
      Busca=*InicioEst;
      while((Busca->NumE!=Est)&&(Busca->ptrsig!=NULL))
        {
          Busca=Busca->ptrsig;
        }
      if(Busca->NumE!=Est)
        {
          system("clear");
          printf("\nLa estación introducida no existe. Verifica por favor.\n\n");
        }
      else
	{
	  if(Busca->ptrbici!=NULL)
	    {
	      system("clear");
	      printf("\nEsta estación aún tiene bicicletas asignadas. Reasígnalas primero para poder darla de baja.\n\n");
	    }
	  else
	    {
	      Busca=*InicioEst;
	      if(Busca->ptrsig==NULL)
		{
		  RecorreUs=InicioUs;
		  while(RecorreUs!=NULL)
		    {
		      if(RecorreUs->ptrbici!=NULL)
			Bandera=1;
		      RecorreUs=RecorreUs->ptrsig;
		    }
		  if(Bandera==0)
		    {
		      system("clear");
		      Baja_Estacion(InicioEst,Est);
		    }
		  else
		    {
		      system("clear");
		      printf("\nEsta es la última estación y hay bicicletas rentadas. No se permite darla de baja.\n\n");
		    }
		}
	      else
		{
		  system("clear");
		  Baja_Estacion(InicioEst,Est);
		}
	    }
	}

    }
  else
    {
      system("clear");
      printf("\nNo existen estaciones que puedan ser dadas de baja.\n\n");
    }
}

void Baja_Estacion(TipoEstacion **InicioEst, int Est)
{
  int accion=102,basura;
  TipoEstacion *Busca;
  Busca=*InicioEst;
  if(Busca->NumE==Est)
    {
      *InicioEst=Busca->ptrsig;
      free(Busca);
      printf("\nSe dio de baja correctamente la estación %d\n\n",Est);
    }
  else
    {
      TipoEstacion *BuscaAnt;
      BuscaAnt=*InicioEst;
      Busca=BuscaAnt->ptrsig;
      while(Busca->NumE!=Est)
        {
          Busca=Busca->ptrsig;
          BuscaAnt=BuscaAnt->ptrsig;
        }
      BuscaAnt->ptrsig=Busca->ptrsig;
      Busca->ptrsig=NULL;
      Busca->ptrbici=NULL;
      free(Busca);
      printf("\nSe dio de baja correctamente la estación %d\n\n",Est);
    }
  bitacora(accion,Est,basura);
}

void Alta_Bici(TipoEstacion **InicioEst, int *AcumNumB)
{
  int Est, Espacios, Bicis,accion=201,var,basura;
  TipoEstacion *Busca;
  TipoBici *NuevaBici;
  if(*InicioEst!=NULL)
    {
      system("clear");
      printf("\nIntroduce el número de la estación en la que quieras dar de alta la bicicleta\n");
      __fpurge(stdin);
      scanf("%d",&Est);
      Busca=*InicioEst;
      while((Busca->NumE!=Est)&&(Busca->ptrsig!=NULL))
        {
          Busca=Busca->ptrsig;
        }
      if(Busca->NumE!=Est)
        {
          printf("\nLa estación introducida no existe\n\n");
        }
      else
        {
          TieneBicisAncladas(*InicioEst,Est,&Bicis);//Función que recorre la lista de estaciones para contar cuántas están ancladas al momento
          Espacios = 10 - Bicis;
          if(Espacios>0)
            {
              system("clear");
              printf("\nSe han encontrado en esta estación %d espacios disponibles\n",Espacios);
              if(Busca->ptrbici==NULL)
                {
                  NuevaBici=(TipoBici*)malloc(sizeof(TipoBici));
                  (*AcumNumB)++;
                  NuevaBici->NumB= *AcumNumB;
                  NuevaBici->NumE=Est;
		  NuevaBici->NumUs=0;
                  NuevaBici->Rentas=0;
                  strcpy(NuevaBici->TimeS,"\0");
                  NuevaBici->ptrsig=NULL;
                  Busca->ptrbici=NuevaBici;
                  printf("\nSe creó correctamente la bicicleta %d en la estación %d\n\n",*AcumNumB,Est);
                }
              else
                {
                  TipoBici *BuscarBici;
                  BuscarBici=Busca->ptrbici;
                  while(BuscarBici->ptrsig!=NULL)
                    {
                      BuscarBici=BuscarBici->ptrsig;
                    }
                  TipoBici *NuevaBici;
                  NuevaBici=(TipoBici*)malloc(sizeof(TipoBici));
                  (*AcumNumB)++;
                  NuevaBici->NumB= *AcumNumB;
                  NuevaBici->NumE=Est;
		  NuevaBici->NumUs=0;
                  NuevaBici->Rentas=0;
                  strcpy(NuevaBici->TimeS,"\0");
                  NuevaBici->ptrsig=NULL;
                  BuscarBici->ptrsig=NuevaBici;
                  system("clear");
                  printf("\nSe creó correctamente la bicicleta %d en la estación %d\n\n",*AcumNumB,Est);
                }
	      var=*AcumNumB;
	      bitacora(accion,var,basura);
            }
          else
            {
              system("clear");
              printf("\nEsta estación no tiene espacios para asignar bicicletas por el momento\n\n");
            }
        }
    }
  else
    {
      system("clear");
      printf("\nNo existen estaciones para anclar las bicicletas\n\n");
    }
}

void ValidarBajaBici(TipoEstacion **InicioEst)
{
  int Bici, Est;
  int E=0; //Indica si ya fue encontrada la bicicleta
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  if(*InicioEst!=NULL)
    {
      system("clear");
      printf("\nIntroduce el número de la bicicleta que quieres dar de baja\n");
      __fpurge(stdin);
      scanf("%d",&Bici);
      Busca=*InicioEst;
      while((Busca!=NULL)&&(E==0))
        {
          Est=Busca->NumE;
          if(Busca->ptrbici!=NULL)
            {
              BuscaBici=Busca->ptrbici;
              while((BuscaBici->NumB!=Bici)&&(BuscaBici->ptrsig!=NULL))
                {
                  BuscaBici=BuscaBici->ptrsig;
                }
              if(BuscaBici->NumB==Bici)
                E=1;
              Busca=Busca->ptrsig;
            }
          else
            {
              Busca=Busca->ptrsig;
            }
        }
      if(E==0)
        {
          system("clear");
          printf("\nLa bicicleta introducida no existe o se encuentra rentada por un usuario.\n\n");
        }
      else
        {
          Baja_Bicicleta(*InicioEst, Est, BuscaBici, Bici);
        }
    }
  else
    {
      system("clear");
      printf("\nNo existen estaciones, por lo tanto, tampoco existen bicicletas\n\n");
    }
}

void Baja_Bicicleta(TipoEstacion *InicioEst, int Est, TipoBici *BuscaBici, int Bici)
{
  int accion=202,basura;
  TipoBici *BuscaBiciAnt;
  TipoEstacion *Busca;
  Busca=InicioEst;
  while(Busca->NumE!=Est)
    {
      Busca=Busca->ptrsig;
    }
  if((BuscaBici)==Busca->ptrbici)
    {
      Busca->ptrbici=BuscaBici->ptrsig;
      free(BuscaBici);
      system("clear");
      printf("\nLa bicicleta %d se ha dado de baja correctamente de la estación %d\n\n",Bici,Est);
    }
  else
    {
      BuscaBiciAnt=Busca->ptrbici;
      while(BuscaBiciAnt->ptrsig!=BuscaBici)
        {
          BuscaBiciAnt=BuscaBiciAnt->ptrsig;
        }
      BuscaBiciAnt->ptrsig=BuscaBici->ptrsig;
      free(BuscaBici);
      system("clear");
      printf("\nLa bicicleta %d se ha dado de baja correctamente de la estación %d\n\n",Bici,Est);
    }
  bitacora(accion,Bici,basura);
}

void ValidarReasignacion(TipoEstacion **InicioEst)
{
  TipoEstacion *Busca;//Busca la estación Origen
  TipoEstacion *Busca2;//Busca la estación Destino
  TipoBici *BuscaBici;//Busca la bicicleta a mover
  int Bici, E=0;//Número de la bicicleta a dar de baja y bandera de Encontrado
  int EstO, EstD;//Estaciones de Origen y Destino, respectivamente
  int Espacios, Bicis;//Espacios y Bicicletas en la Estación Destino
  if(*InicioEst!=NULL)
    {
      Busca=*InicioEst;
      if(Busca->ptrsig!=NULL)
        {
          system("clear");
          printf("\nIntroduce el número de la bicicleta que quieres reasignar\n");
	  __fpurge(stdin);
          scanf("%d",&Bici);
          while((Busca!=NULL)&&(E==0))
            {
              EstO=Busca->NumE;
              if(Busca->ptrbici!=NULL)
                {
                  BuscaBici=Busca->ptrbici;
                  while((BuscaBici->NumB!=Bici)&&(BuscaBici->ptrsig!=NULL))
                    {
                      BuscaBici=BuscaBici->ptrsig;
                    }
                  if(BuscaBici->NumB==Bici)
                    E=1;
                  Busca=Busca->ptrsig;
                }
              else
                {
                  Busca=Busca->ptrsig;
                }
            }
          if(E==0)
            {

              system("clear");
              printf("\nLa bicicleta introducida no existe o se encuentra rentada por un usuario.\n\n");
            }
          else
            {
              system("clear");
              printf("\nSe encontró la bicicleta en la estación %d. ¿A qué estación la quieres mover?\n",EstO);
	      __fpurge(stdin);
              scanf("%d",&EstD);
              Busca2=*InicioEst;
              while((Busca2->NumE!=EstD)&&(Busca2->ptrsig!=NULL))
                {
                  Busca2=Busca2->ptrsig;
                }
              if(Busca2->NumE!=EstD)
                {
                  system("clear");
                  printf("\nLa estación introducida no existe.\n\n");
                }
              else
                {
                  if(EstO==EstD)
                    {
                      system("clear");
                      printf("\nLa estación origen y destino son iguales. No se realizaron cambios.\n\n");
                    }
                  else
                    {
                      TieneBicisAncladas(*InicioEst,EstD,&Bicis);//Función que recorre la lista de estaciones para contar cuántas están ancladas al momento
                      Espacios = 10 - Bicis;
                      if(Espacios>0)
                        {
                          system("clear");
                          printf("\nLa estación %d tiene %d espacios disponibles\n\n",EstD,Espacios);
                          Reasignar_Bici(InicioEst,EstO,EstD,Busca2,Bici);
                        }
                      else
                        {
                          system("clear");
                          printf("\nLa estación %d no tiene ningún espacio disponible.\n\n",EstD);
                        }
                    }
                }
            }
        }
      else
        {
          system("clear");
          printf("\nPor el momento sólo existe una estación. No se puede mover una bicicleta a otro lugar.\n\n");
        }
    }
  else
    {
      system("clear");
      printf("\nNo existen estaciones, por lo tanto, tampoco existen bicicletas\n\n");
    }
}

void Reasignar_Bici(TipoEstacion **InicioEst, int EstO, int EstD, TipoEstacion *Busca2, int Bici)
{
  int accion=203;
  TipoBici *BuscaBiciAnt; //Sigue a BuscaBici para ayudar a quitarla de EstO y ponerla en EstD
  TipoEstacion *Busca; //Encuentra la estación origen
  TipoBici *BuscaBici;//Se posiciona como la bicicleta a mover

  Busca=*InicioEst;
  while(Busca->NumE!=EstO)
    {
      Busca=Busca->ptrsig;
    }
  BuscaBici=Busca->ptrbici;
  while(BuscaBici->NumB!=Bici)
    {
      BuscaBici=BuscaBici->ptrsig;
    }
  //Quitar bicicleta de la estación origen
  if(BuscaBici==Busca->ptrbici)
    {
      Busca->ptrbici=BuscaBici->ptrsig;
    }
  else
    {
      BuscaBiciAnt=Busca->ptrbici;
      while(BuscaBiciAnt->ptrsig!=BuscaBici)
        {
          BuscaBiciAnt=BuscaBiciAnt->ptrsig;
        }
      BuscaBiciAnt->ptrsig=BuscaBici->ptrsig;
    }
  //Ponerla en la estación destino
  if(Busca2->ptrbici==NULL)
    {
      Busca2->ptrbici=BuscaBici;
      BuscaBici->NumE=EstD;
      BuscaBici->ptrsig=NULL;
      printf("\nSe reasignó correctamente la bicicleta %d a la estación %d desde la estación %d.\n\n",Bici,EstD,EstO);
    }
  else
    {
      BuscaBiciAnt=Busca2->ptrbici;
      while(BuscaBiciAnt->ptrsig!=NULL)
        {
          BuscaBiciAnt=BuscaBiciAnt->ptrsig;
        }
      BuscaBici->NumE=EstD;
      BuscaBici->ptrsig=NULL;
      BuscaBiciAnt->ptrsig=BuscaBici;
      printf("\nSe reasignó correctamente la bicicleta %d a la estación %d desde la estación %d.\n\n",Bici,EstD,EstO);
    }
  bitacora(accion,Bici,EstD);
}

void TieneBicisAncladas(TipoEstacion *InicioEst,int Est,int *Bicis)
//Función que recorre la lista para contar las bicicletas ancladas al momento
{
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  Busca=InicioEst;
  while(Busca->NumE!=Est)
    {
      Busca=Busca->ptrsig;
    }
  if(Busca->ptrbici==NULL)
    *Bicis = 0;
  else
    {
      BuscaBici= Busca->ptrbici;
      *Bicis = 1;
      while(BuscaBici->ptrsig!=NULL)
        {
          BuscaBici=BuscaBici->ptrsig;
          (*Bicis)++;
        }
    }
}

void ImprimeEst(TipoEstacion *InicioEst)
{
  int Bicis=0, Espacios;
  int Est;
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  Busca=InicioEst;
  if(Busca==NULL)
    {
      system("clear");
      printf("\nNo existen estaciones.\n");
    }
  else
    {
      system("clear");
      printf("\n\t\tEstatus de Estaciones\n\n");
      printf("\nIntroduce el número de la estación cuyo estatus quieres saber, o un número negativo para verlas todas.\n\n");
      __fpurge(stdin);
      scanf("%d",&Est);
      if(Est<0)
	{
	  system("clear");
	  printf("\n\t\tEstatus de Estaciones\n\n");
	  printf("\nSe encuentran en la lista las estaciones:\n\n");
	  while(Busca!=NULL)
	    {
	      printf("Estacion %d - %s:\t",Busca->NumE,Busca->Nombre);
	      BuscaBici=Busca->ptrbici;
	      while(BuscaBici!=NULL)
		{
		  printf("Bicicleta %d\t",BuscaBici->NumB);
		  Bicis++;
		  BuscaBici=BuscaBici->ptrsig;
		}
	      printf("\n");
	      Espacios = 10 - Bicis;
	      printf("Bicicletas disponibles:\t%d\n",Bicis);
	      printf("Lugares disponibles:\t%d",Espacios);
	      Busca=Busca->ptrsig;
	      Bicis=0;
	      printf("\n\n");
	    }
	}
      else
	{
	  while((Busca->NumE!=Est)&&(Busca->ptrsig!=NULL))
	    {
	      Busca=Busca->ptrsig;
	    }
	  if(Busca->NumE!=Est)
	    {
	      system("clear");
	      printf("\nLa estación introducida no existe. Verifica por favor.\n");
	    }
	  else
	    {
	      system("clear");
	      printf("\n\t\tEstatus de Estaciones\n\n");
	      printf("Estacion %d - %s:\t",Busca->NumE,Busca->Nombre);
	      BuscaBici=Busca->ptrbici;
	      while(BuscaBici!=NULL)
		{
		  printf("Bicicleta %d\t",BuscaBici->NumB);
		  Bicis++;
		  BuscaBici=BuscaBici->ptrsig;
		}
	      printf("\n");
	      Espacios = 10 - Bicis;
	      printf("Bicicletas disponibles:\t%d\n",Bicis);
	      printf("Lugares disponibles:\t%d",Espacios);
	      printf("\n\n");
	    }
	}
    }
  printf("\n");
}

void BorrarListaEst(TipoEstacion *InicioEst)
{
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  Busca=InicioEst;
  while(Busca!=NULL)
    {
      BuscaBici=Busca->ptrbici;
      while(BuscaBici!=NULL)
	{
	  Busca->ptrbici=BuscaBici->ptrsig;
	  free(BuscaBici);
	  BuscaBici=Busca->ptrbici;
	}
      InicioEst=InicioEst->ptrsig;
      free(Busca);
      Busca=InicioEst;
    }
}
void MostrarMenuAdmin(void)
{
  printf("===================================================================");
  printf("\n\t\tMENÚ PRINCIPAL ADMINISTRADOR\n\n");
  printf("\n ¿Qué te gustaría hacer ahora?\n");
  printf("\n\t1. Alta de una bici-estación.\n");
  printf("\n\t2. Baja de una bici-estación.\n");
  printf("\n\t3. Alta de bicicletas en una bici-estación.\n");
  printf("\n\t4. Baja de bicicletas en una bici-estación.\n");
  printf("\n\t5. Reasignar bicicletas entre bici-estaciones.\n");
  printf("\n\t6. Mostrar el estatus de una o todas las bici-estaciones.\n");
  printf("\n\t7. Alta de un usuario del servicio.\n");
  printf("\n\t8. Baja de un usuario del servicio.\n");
  printf("\n\t9. Salida del sistema.\n");
  printf("===================================================================");
  printf("\n\n");
}

void MostrarMenuUsuario(void)
{
  printf("===================================================================");
  printf("\n\t\tMENÚ PRINCIPAL USUARIO\n\n");
  printf("\n ¿Qué te gustaría hacer ahora?\n");
  printf("\n\t1. Rentar una bicicleta.\n");
  printf("\n\t2. Estacionar una bicicleta.\n");
  printf("\n\t3. Consultar tu saldo.\n");
  printf("\n\t4. Salida del sistema.\n");
  printf("===================================================================");
  printf("\n\n");
}

//SEGUNDO GRUPO DE FUNCIONES

void LeerArchivoUs(TipoUs **Inicio){
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
      fscanf(usuarios,"%i\n%i\n",&temp->NumUs,&temp->multa);
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

void LeerArchivoEst(TipoEstacion **InicioEst)
{
  int num,i=1;
  TipoEstacion *temp,*temp2;
  FILE *esta;
  esta=fopen("estaciones.txt","rt");
  if(esta!=NULL)
    {
      while(fscanf(esta,"%i\n",&num)==1)
	{
	  temp=(TipoEstacion*)malloc(sizeof(TipoEstacion));
	  temp->NumE=num;
	  fgets(temp->Nombre,99,esta);
	  temp->Nombre[strlen(temp->Nombre)-1]='\0';
	  fgets(temp->Calle_y_Num,99,esta);
	  temp->Calle_y_Num[strlen(temp->Calle_y_Num)-1]='\0';
	  fscanf(esta,"%i\n",&temp->CP);
	  fgets(temp->Ciudad,99,esta);
	  temp->Ciudad[strlen(temp->Ciudad)-1]='\0';
	  temp->ptrbici=NULL;
	  temp->ptrsig=NULL;
	  if(*InicioEst!=NULL)
	    {
	      temp2=*InicioEst;
	      while(temp2->ptrsig!=NULL)
		temp2=temp2->ptrsig;
	      temp2->ptrsig=temp;
	    }
	  else
	    *InicioEst=temp;
	}
      fclose(esta);
    }
}

void Login(TipoUs *Inicio,int *band,int *NumUs){
  int us,bas,accion=20;
  char contra[200];
  TipoUs *temp;
  system("clear");
  printf("\n\t\tPantalla de Ingreso al Sistema\n\n");
  printf("\tPor favor introduce tu Número de Usuario y Contraseña\n\n");
  do{
    temp=Inicio;
    do{
      printf("\nUsuario: ");
      __fpurge(stdin);
      bas=scanf("%i",&us);
      if(bas!=1)
        printf("\nHay una letra en el usuario.\n");
    }while(bas!=1);
    while(temp!=NULL&&temp->NumUs!=us)//Verifica el usuario con la estructura actual, si no concuerda avanza.
      temp=temp->ptrsig;
    if(temp==NULL)//Si llego al final significa que no existe tal usuario.
      printf("\nUsuario no existente.\n");
  }while(temp==NULL);
  do{
    printf("\nContraseña: ");
    __fpurge(stdin);
    gets(contra);
    if(strcmp(contra,temp->PW)!=0)
      printf("\nContraseña incorrecta.\n");
  }while(strcmp(contra,temp->PW)!=0);
  *band=temp->Bandera;
  *NumUs=temp->NumUs;
  system("clear");
  if(temp->Bandera==0)
    bitacora(accion,us,bas);
}


void AltaUsuario(TipoUs **Inicio, int *ultusu)
{
  system("clear");//limpia la pantalla
  TipoUs *temp, *temp2;
  int tc,accion=301,basura;
  temp=(TipoUs*)malloc(sizeof(TipoUs));//reserva espacio para la nueva estructura
  printf("\n\t\tAlta de Nuevo Usuario\n\n");
  printf("\nIntroduce el Nombre del Usuario\n");
  __fpurge(stdin);
  gets(temp->Nombre);
  printf("\nIntroduce la Direccion del Usuario.\n");
  __fpurge(stdin);
  gets(temp->Direccion);
  do{
    do{
      printf("\nIntroduce los 16 digitos de la Tarjeta de Crédito\n");
      __fpurge(stdin);
      tc=scanf("%li",&temp->TC);
      if(tc!=1)
	printf("\nEn una tarjeta de crédito solo hay números.\n");
    }while(tc!=1);
    if(temp->TC<=999999999999999||temp->TC>=10000000000000000)
      printf("\nLas tarjetas de credito tienen solo 16 digitos.\n");
  }while(temp->TC<=999999999999999||temp->TC>=10000000000000000);
  printf("\nIntroduce la Contraseña (máximo 49 caracteres)\n");
  __fpurge(stdin);
  gets(temp->PW);//lee la contrasena
  temp->NumUs=++(*ultusu);
  do{
    do{
      printf("\nIntroduce 0 para dar permisos de Administrador o 1 para dar permisos de Usuario.\n");
      __fpurge(stdin);
      basura=scanf("%i",&temp->Bandera);
      if(basura!=1)
	printf("Solo se puede poner 1 o 0.\n");
    }while(basura!=1);
      if(temp->Bandera!=0&&temp->Bandera!=1)
	printf("Invalido\n");
    }while(temp->Bandera!=0&&temp->Bandera!=1);
  temp->multa=0;
  temp->ptrsig=NULL;
  temp->ptrbici=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->ptrsig!=NULL)
	     temp2= temp2->ptrsig;
      temp2->ptrsig=temp;
    }
  else
    *Inicio=temp;

  system("clear");
  printf("\nEl usuario fue dado de alta correctamente con el número: %i\n\n",temp->NumUs);
  bitacora(accion,temp->NumUs,basura);
}



void ImprimeUs(TipoUs *InicioUs)
{
  TipoUs *Recorre;
  int Us=0,Adm=0;//Contadores de usuarios y administradores
  Recorre=InicioUs;
  if(Recorre==NULL)
    {
      system("clear");
      printf("\nNo existen usuarios.\n\n");
    }
  else
    {
      system("clear");
      printf("\nSe encuentran en la lista los usuarios:\n\n\n");
      printf("\tNúmero\t\t   Usuario/Admin\t\t   Nombre\n\n\n");
      do
        {
          printf("\t%d\t\t",Recorre->NumUs);
          if(Recorre->Bandera==0)
            {
              printf("\tA\t\t\t");
              Adm++;
            }
          else
            {
              printf("\tU\t\t\t");
              Us++;
	    }
	  puts(Recorre->Nombre);
          Recorre=Recorre->ptrsig;
        }while(Recorre!=NULL);
        printf("\n\n");
        printf("Se tienen en total %d Cuentas, de las cuales son %d de Usuario y %d de Administrador.\n\n\n",Us+Adm,Us,Adm);
    }
}

void BajaUsuario(TipoUs **Inicio){
  int us,accion=302,basura;
  TipoUs *temp,*temp2;
  temp=*Inicio;
  system("clear");
  printf("\n\t\tBaja de Usuario\n\n");
  printf("\nIntroduce el número del usuario que quieres dar de baja\n");
  __fpurge(stdin);
  scanf("%i",&us);
  while(temp!=NULL&&temp->NumUs!=us)//busca el usuario que se quiere borrar.
    temp=temp->ptrsig;
  if(temp==NULL)//si no se encuentra el usuario, no hace nada.
    {
      system("clear");
      printf("\n\tEl número de usuario introducido no existe.\n");
    }
  else if(temp->ptrbici!=NULL)
    {
      system("clear");
      printf("\nEste usuario tiene una bicicleta rentada. No puede ser dado de baja ahora.\n\n");
    }
  else if(us==999)
    printf("\nNo se puede dar de baja este usuario.\n");
  else{//si si lo encontro lo borra
    if(temp==*Inicio){//si esta al comienzo cambia el inicio a la siguiente estructura.
      temp2=temp->ptrsig;
      *Inicio=temp2;
      free(temp);
      system("clear");
      printf("\nEl usuario con número %d fue dado de baja correctamente.\n\n",us);
    }
    else{//si esta en medio se salta ese elemento.
      temp2=*Inicio;
      while(temp2->ptrsig!=temp)
        temp2=temp2->ptrsig;
      temp2->ptrsig=temp->ptrsig;
      free(temp);
      system("clear");
      printf("\nEl usuario con número %d fue dado de baja correctamente.\n\n",us);
    }
     bitacora(accion,us,basura);
  }
}



void GuardarArchivoUs(TipoUs *Inicio)
{
  FILE *usuarios,*ult;
  TipoUs *temp;
  usuarios=fopen("us.txt","wt");//abre el archivo en sobreescribir para guardar todos los datos en un archivo
  temp=Inicio;
  while(temp!=NULL)
    {
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
      fprintf(usuarios,"%i\n%i\n",temp->NumUs,temp->multa);//copia todos los datos al documento
      temp=temp->ptrsig;//se mueve a la siguiente estructura
    }
  fclose(usuarios);
}

void GuardarArchivoEst(TipoEstacion *Inicio){
  FILE *esta;
  TipoEstacion *temp;
  esta=fopen("estaciones.txt","wt");//abre el archivo en sobreescribir para guardar todos los datos en un archivo
  temp=Inicio;
  while(temp!=NULL){
    fprintf(esta,"%i\n",temp->NumE);
    fputs(temp->Nombre,esta);
    fprintf(esta,"\n");
    fputs(temp->Calle_y_Num,esta);
    fprintf(esta,"\n");
    fprintf(esta,"%i\n",temp->CP);
    fputs(temp->Ciudad,esta);
    fprintf(esta,"\n");
    temp=temp->ptrsig;
  }
  fclose(esta);
}

void BorrarListaUs(TipoUs *InicioUs)
{
  TipoUs *temp;
  temp=InicioUs;
  while(temp!=NULL)
    {
      InicioUs=InicioUs->ptrsig;
      free(temp);
      temp=InicioUs;
    }
}

void LeerUltimaVariable(int *AcumNumUs, int *AcumNumE, int *AcumNumB)
{
  FILE *ultima;
  ultima=fopen("ultvar.txt","r");
  fscanf(ultima,"%i\n%i\n%i",AcumNumUs,AcumNumE,AcumNumB);
  fclose(ultima);
}

void GuardarUltimaVariable(int AcumNumUs, int AcumNumE, int AcumNumB)
{
  FILE *ultima;
  ultima=fopen("ultvar.txt","w");
  fprintf(ultima,"%i\n%i\n%i",AcumNumUs,AcumNumE,AcumNumB);
  fclose(ultima);
}

//TERCER GRUPO DE FUNCIONES

void Argumento(char Arg[200],TipoUs *InicioUs)
{
  char usu[10],crea[10],help[10];
  strcpy(usu,"-usu");//Se crean cadenas con todas las opciones posibles.
  strcpy(crea,"-c");
  strcpy(help,"-h");
  if(strcmp(usu,Arg)==0)//Compara todas la opciones posibles.
    ImprimeUs(InicioUs);
  else if(strcmp(crea,Arg)==0)
    Creadores();
  else if(strcmp(help,Arg)==0)
    Help();
  else//Si no se ejecutó correctamente, indica al usuario las posibilidades de ejecución.
    Error_Ejecucion();
}

void Creadores(int hola)
{
  system ("clear");
  printf("\n\n");
  printf ("\t\t Este programa fue creado por: \n\n\n");
  printf ("\t\t      David Halabe Husny \n\n");
  printf ("\t\t     Rafael Melgoza Romero \n\n");
  printf ("\t\t Maria Fernanda Sakai Salazar \n\n");
  printf("\n\n");
  printf("\n\t  Proyecto Final Fundamentos de Programación\n");
  printf("\n\n");
  printf("\t\t   Universidad Iberoamericana\n\n");
  printf("\t\t          Otoño 2018\n\n\n\n\n");
}

void Help(int hola)
{
  system ("clear");
  printf("\n\n");
  printf ("\t\t\t\t\tBienvenido a la pantalla de ayuda \n");
  printf ("\t\t\t\t\t================================= \n\n");
  printf ("\tFuncionamiento del programa: \n");
  printf ("\t- Para poder ingresar a tu cuenta deberás ingresar tu usuario y contraseña. Ej: 1234, abcd \n");
  printf ("\t- Una vez ingresado al programa podrás hacer las siguientes cosas: \n");
  printf ("\t   - Rentar una bicicleta \n");
  printf ("\t   - Estacionar una bicicleta \n");
  printf ("\t   - Mostrar saldo \n");
  printf ("\t- Para rentar o dejar una bicicleta deberás ingresar la estación que tengas más cercana,\n");
  printf ("\t  para poder revisar si hay bicicletas disponibles o lugares disponibles, de acuerdo a lo necesario. \n");
  printf ("\t- Si deseas rentar una bicicleta: \n");
  printf ("\t   - El sistema revisará si no tienes una bicicleta en renta, recuerda que no puedes rentar dos unidades a la vez. \n");
  printf ("\t   - EL sistema te dirá si hay bicicletas disponibles, de ser así te dará el número de la placa de la misma y te permitirá tomarla. \n");
  printf ("\t   - Recuerda que tienes un máximo de 30 minutos por renta, por lo que se te aconseja buscar de antemano las estaciones más cercanas a tu destino. \n");
  printf ("\n");
  printf ("\t- Si deseas dejar una bicicleta: \n");
  printf ("\t   - El sistema revisará si hay lugares disponibles para que puedas dejar la bicicleta.\n");
  printf ("\t     De no contar con lugares, indicará que no se puede hacer uso del servicio en esa estación. \n");
  printf ("\n");
  printf ("\tReglamento: \n");
  printf ("\t- Cada renta de bicicleta tendrá una duración máxima de 30 minutos. Si por alguna razón rebasas este tiempo tendrás que pagar una multa de 500 pesos. \n");
  printf ("\t- Podrás consultar tu saldo acumulado de multas en el Menú de Usuario, si lo deseas.\n");
  printf ("\t- Para dejar una bicicleta debes asegurarte que haya espacios de antemano. Es tu responsabilidad dejarla a tiempo. \n");
  printf("\n\n\n");
}

void Error_Ejecucion()
{
  system ("clear");
  printf("\n\t\t\t\t\tError en la Ejecución\n");
  printf("\t====================================================================================\n\n");
  printf ("\tRecuerda que sólo se puede ejecutar el programa de las siguientes maneras: \n\n");
  printf ("\t- bicirenta.exe -h\t| Esta es la forma de accesar al Menú de Ayuda. \n\n");
  printf ("\t- bicirenta.exe -c\t| Despliega los créditos de los desarrolladores del sistema. \n\n");
  printf ("\t- bicirenta.exe -usu\t| Despliega el listado de todos los usuarios de servicio. \n\n");
  printf ("\t- bicirenta.exe\t\t| Ejecuta el programa de forma natural. \n\n\n\n");
}


//CUARTO GRUPO DE FUNCIONES

void ValidarRentaBici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs)
{
  int NumB;
  TipoEstacion *Busca;
  int Est, Bicis;
  Busca=InicioEst;
  if(InicioEst!=NULL)
    {
      if(TieneRenta(InicioUs,NumUs,&NumB)==1)//Función que recorre la estructura de usuarios para saber si tiene una bicicleta rentada al momento
        {
          system("clear");
          printf("\nHemos detectado que tienes una bicicleta rentada. Por favor devuélvela para poder rentar otra.\n\n");
        }
      else
        {
	  system("clear");
	  printf("\n\t\tPantalla de Renta\n\n\n");
	  MostrarEst(InicioEst);
          printf("\n\nPor favor indica en qué número de estación te encuentras ahora\n");
	  __fpurge(stdin);
          scanf("%d",&Est);
	  while((Busca->NumE!=Est)&&(Busca->ptrsig!=NULL))
	    {
	      Busca=Busca->ptrsig;
	    }
	  if(Busca->NumE!=Est)
	    {
	      printf("\nLa estación introducida no existe\n\n");
	    }
	  else
	    {
	      TieneBicisAncladas(InicioEst,Est,&Bicis);//Función que recorre la lista de estaciones para contar cuántas están ancladas al momento
	      if(Bicis>0)
		{
		  Rentar_Bici(InicioEst,InicioUs,NumUs,Est);//Función que realiza ajustes de renta
		}
	      else
		{
		  system("clear");
		  printf("\nEsta estación no tiene bicicletas disponibles en este momento. Por favor intenta en otra estación.\n\n");
		}
	    }
	}
    }
  else
    {
      system("clear");
      printf("\nPor el momento no tenemos estaciones ni bicicletas. Por favor prueba después.\n\n");
    }
}


void ValidarDevolucionBici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs)
{
  int NumB, EstD;
  int Bicis, Espacios;
  TipoEstacion *Busca;
  Busca=InicioEst;

  if(TieneRenta(InicioUs,NumUs,&NumB)!=1) /*Función que recorre la estructura de usuarios para saber si tiene una bicicleta rentada al momento*/
    {
      system("clear");
      printf("\nPor el momento no tienes ninguna bici rentada.\n\n");
    }
  else
    {
      system("clear");
      printf("\n\t\tPantalla de Renta\n\n");
      printf("\nPor favor indica en qué estación te encuentras ahora\n");
      __fpurge(stdin);
      scanf("%d",&EstD);
      while((Busca->NumE!=EstD)&&(Busca->ptrsig!=NULL))
	{
	  Busca=Busca->ptrsig;
	}
      if(Busca->NumE!=EstD)
	{
	  printf("\nLa estación introducida no existe\n\n");
	}
      else
	{
	  TieneBicisAncladas(InicioEst,EstD,&Bicis);/*Función que recorre la estructura de Estaciones para contar cuántas bicicletas están ancladas al momento*/
	  Espacios=10-Bicis;
	  if(Espacios>0)
	    {
	      Dejar_Bici(InicioEst, InicioUs, NumUs, EstD, NumB); /*Función que realiza los ajustes de devolución*/
	    }
	  else
	    {
	      system("clear");
	      printf("\nEsta estación no tiene espacios disponibles en este momento. Por favor intenta en otra estación.\n\n");
	    }
	}
    }
}

void Rentar_Bici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs, int Est)
//Función que realiza los ajustes de renta
{
  time_t crudo;
  struct tm *tipotiempo;
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  TipoBici *BuscaBiciAnt;
  TipoUs *BuscaUs;
  int NumB;

  //Se coloca en la bici
  Busca=InicioEst;
  while(Busca->NumE!=Est)
    {
      Busca=Busca->ptrsig;
    }
  BuscaBici=Busca->ptrbici;
  NumB=BuscaBici->NumB;

  //Quitar bicicleta de la estación origen
  if(BuscaBici==Busca->ptrbici)
    {
      Busca->ptrbici=BuscaBici->ptrsig;
    }
  else
    {
      BuscaBiciAnt=Busca->ptrbici;
      while(BuscaBiciAnt->ptrsig!=BuscaBici)
        {
          BuscaBiciAnt=BuscaBiciAnt->ptrsig;
        }
      BuscaBiciAnt->ptrsig=BuscaBici->ptrsig;
    }

  //Busca al usuario que la va a rentar
  BuscaUs=InicioUs;
  while(BuscaUs->NumUs!=NumUs)
    {
      BuscaUs=BuscaUs->ptrsig;
    }

  //Liga al usuario a la bicicleta
  BuscaUs->ptrbici=BuscaBici;
  BuscaBici->NumE=Est;
  (BuscaBici->Rentas)++;
  BuscaBici->NumUs=NumUs;
  BuscaBici->ptrsig=NULL;

  //Hace los ajustes de tiempo
  time(&crudo);
  tipotiempo=localtime(&crudo);
  strftime(BuscaBici->TimeS,99,"%Y%m%d-%H:%M:%S",tipotiempo);

  /*Se libera bicicleta para que el usuario la tome*/
  printf("\n%s: Por favor toma la bicicleta %d de la estación %d. La bicicleta ha sido rentada correctamente.\n\n",BuscaUs->Nombre,NumB,Est);
}

void Dejar_Bici(TipoEstacion *InicioEst, TipoUs *InicioUs, int NumUs, int EstD, int NumB)
{
  int ret,ret2,dif,hora,min,seg,temp;
  time_t crudo2;
  struct tm *cocinado,*cocinado2,tipotiempo2,tiempo3;
  double diff;
  char cadena[200],ordenado1[200],ordenado2[200];
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  TipoBici *BuscaBiciAnt;
  TipoUs *BuscaUs;

  //Busca al usuario que la va a devolver y se coloca en la bici
  BuscaUs=InicioUs;
  while(BuscaUs->NumUs!=NumUs)
    {
      BuscaUs=BuscaUs->ptrsig;
    }
  BuscaBici=BuscaUs->ptrbici;

  //Quitar bicicleta del usuario
  BuscaUs->ptrbici=BuscaBici->ptrsig;

  //Busca la estación de devolución, se coloca en la última bici y devuelve la rentada
  Busca=InicioEst;
  while(Busca->NumE!=EstD)
    {
      Busca=Busca->ptrsig;
    }
  if(Busca->ptrbici==NULL)
    {
      Busca->ptrbici=BuscaBici;
    }
  else
    {
      BuscaBiciAnt=Busca->ptrbici;
      while(BuscaBiciAnt->ptrsig!=NULL)
	{
	  BuscaBiciAnt=BuscaBiciAnt->ptrsig;
	}
      BuscaBiciAnt->ptrsig=BuscaBici;
    }
  BuscaBici->NumE=EstD;
  BuscaBici->NumUs=0;

  time(&crudo2);
  cocinado=localtime(&crudo2);
  strftime(cadena,sizeof(cadena),"%Y%m%d-%H:%M:%S",cocinado);
  strptime(BuscaBici->TimeS,"%Y%m%d-%H:%M:%S",&tipotiempo2);
  strptime(cadena,"%Y%m%d-%H:%M:%S",&tiempo3);
  strftime(ordenado2,sizeof(ordenado2),"el dia %d de %m de %Y a las %H:%M:%S",cocinado);
  ret=mktime(&tipotiempo2);
  ret2=mktime(&tiempo3);
  diff=difftime(ret2,ret);
  hora=diff/3600;
  dif=diff;
  temp=dif%3600;
  min=temp/60;
  seg=temp%60;
  printf("\nRentaste tu bicleta %s.\nLa regresaste %s.\nTuviste un tiempo total de %i:%i:%i.\n",BuscaBici->TimeS,cadena,hora,min,seg);
  if(diff>1800){
    printf("\nEso equivale a una multa de 500 pesos.\n");
    (BuscaUs->multa)++;
  }

  /*Se ancla la bicicleta para que que otro usuario la pueda tomar*/
  printf("\nLa bicicleta %d ha sido devuelta correctamente a la estación %d.\n\n",NumB,EstD);
}

int TieneRenta(TipoUs *InicioUs, int NumUs, int *NumB)
{//Función que recorre la estructura de usuarios para saber si tiene una bicicleta rentada al momento
  TipoUs *Busca;
  TipoBici *BuscaBici;
  Busca=InicioUs;
  *NumB = 0;
  while(Busca->NumUs!=NumUs)
    {
      Busca=Busca->ptrsig;
    }

  if(Busca->ptrbici==NULL)
    {
      return 0;
    }
  else
    {
      BuscaBici=Busca->ptrbici;
      (*NumB)=BuscaBici->NumB;
      return 1;
    }
}

//QUINTO GRUPO DE FUNCIONES

void LeerArchivoBiciEst(TipoEstacion **InicioEst)
{
  int NumB,NumE,i=1;
  TipoEstacion *Busca;
  TipoBici *Nuevo, *BuscaBici;
  FILE *ArchBici;
  ArchBici=fopen("BiciEst.txt","rt");
  Busca=*InicioEst;
  if(ArchBici!=NULL)
    {
      while(fscanf(ArchBici,"%i\n",&NumB)==1)
	{
	  Nuevo=(TipoBici*)malloc(sizeof(TipoBici));
	  Nuevo->NumB=NumB;
	  fscanf(ArchBici,"%i\n",&NumE);
	  Nuevo->NumE=NumE;
	  fscanf(ArchBici,"%i\n",&Nuevo->Rentas);
	  Nuevo->ptrsig=NULL;
	  while(NumE!=Busca->NumE)
	    {
	      Busca=Busca->ptrsig;
	    }
	  if(Busca->ptrbici!=NULL)
	    {
	      BuscaBici=Busca->ptrbici;
	      while(BuscaBici->ptrsig!=NULL)
		BuscaBici=BuscaBici->ptrsig;
	      BuscaBici->ptrsig=Nuevo;
	    }
	  else
	    {
	      Busca->ptrbici=Nuevo;
	    }
	}
      fclose(ArchBici);
    }
}


void LeerArchivoBiciUs(TipoUs **InicioUs)
{
  int NumB,NumUs,i=1;
  TipoUs *Busca;
  TipoBici *Nuevo, *BuscaBici;
  FILE *ArchBici;
  ArchBici=fopen("BiciUs.txt","rt");
  Busca=*InicioUs;
  if(ArchBici!=NULL)
    {
      while(fscanf(ArchBici,"%i\n",&NumB)==1)
	{
	  Nuevo=(TipoBici*)malloc(sizeof(TipoBici));
	  Nuevo->NumB=NumB;
	  fscanf(ArchBici,"%i\n",&Nuevo->NumE);
	  fscanf(ArchBici,"%i\n",&NumUs);
	  Nuevo->NumUs=NumUs;
	  fscanf(ArchBici,"%i\n",&Nuevo->Rentas);
	  fgets(Nuevo->TimeS,50,ArchBici);
	  Nuevo->TimeS[strlen(Nuevo->TimeS)-1]='\0';
	  Nuevo->ptrsig=NULL;
	  while(NumUs!=Busca->NumUs)
	    {
	      Busca=Busca->ptrsig;
	    }
	  Busca->ptrbici=Nuevo;
	}
      fclose(ArchBici);
    }
}


void GuardarArchivoBiciEst(TipoEstacion *InicioEst)
{
  FILE *ArchBici;
  TipoEstacion *Busca;
  TipoBici *BuscaBici;
  ArchBici=fopen("BiciEst.txt","wt");//abre el archivo de bicicletas en estaciones
  Busca=InicioEst;
  while(Busca!=NULL)
    {
      BuscaBici=Busca->ptrbici;
      while(BuscaBici!=NULL)
	{
	  fprintf(ArchBici,"%i\n",BuscaBici->NumB);
	  fprintf(ArchBici,"%i\n",BuscaBici->NumE);
	  fprintf(ArchBici,"%i\n",BuscaBici->Rentas);
	  BuscaBici=BuscaBici->ptrsig;
	}
      Busca=Busca->ptrsig;
    }
  fclose(ArchBici);
}

void GuardarArchivoBiciUs(TipoUs *InicioUs)
{
  FILE *ArchBici;
  TipoUs *Busca;
  TipoBici *BuscaBici;
  ArchBici=fopen("BiciUs.txt","wt");//abre el archivo de bicicletas en estaciones
  Busca=InicioUs;
  while(Busca!=NULL)
    {
      BuscaBici=Busca->ptrbici;
      while(BuscaBici!=NULL)
	{
	  fprintf(ArchBici,"%i\n",BuscaBici->NumB);
	  fprintf(ArchBici,"%i\n",BuscaBici->NumE);
	  fprintf(ArchBici,"%i\n",BuscaBici->NumUs);
	  fprintf(ArchBici,"%i\n",BuscaBici->Rentas);
	  fputs(BuscaBici->TimeS,ArchBici);
	  BuscaBici=BuscaBici->ptrsig;
	}
      Busca=Busca->ptrsig;
    }
  fclose(ArchBici);
}

void saldo(TipoUs *InicioUs,int NumUs){
  TipoUs *temp;
  temp=InicioUs;
  system("clear");
  while(temp->NumUs!=NumUs)
    temp=temp->ptrsig;
  printf("\nTienes %i multas, que es equivalente a $%i.\n\n",temp->multa,(temp->multa)*500);
}

void bitacora(int accion,int var,int var2){
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
    fprintf(bitacora,"%s %s %i\n",cadena1,cadena2,var);
  }
  else if(accion==21){
    strcpy(cadena2,"Logout");
    fprintf(bitacora,"%s %s %i\n",cadena1,cadena2,var);
  }
  else if(accion==203)
    fprintf(bitacora,"%s %i %i %i\n",cadena1,accion,var,var2);
  else
    fprintf(bitacora,"%s %i %i\n",cadena1,accion,var);
  fclose(bitacora);
}

void MostrarEst(TipoEstacion *BuscaEst){
  TipoEstacion *temp;
  temp=BuscaEst;
  while(temp!=NULL){
    printf("\nExiste la estacion %s con número %i ubicada en %s.\n",temp->Nombre,temp->NumE,temp->Calle_y_Num);
    temp=temp->ptrsig;
  }
}
