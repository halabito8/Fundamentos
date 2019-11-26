-CEDC-FODX-QUHN

int main(void){
  int var1, var2, ter;
  ter = -99;
  do{
    printf ("Introduzca dos numeros, separados por comas, para ser comparados (-99 para terminar):");
    scanf ("%i, %i", &var1, &var2);
    if ((var1 && var2) > 0)
      if(var1>var2)
        printf ("El numero mayor es: %i\n", var1);
      else
        printf ("El numero mayor es: %i\n", var2);
  }while((var1 && var2)>0);
  if ((var1||var2) == ter)
    printf ("Usted termino el programa.\n");
}    
