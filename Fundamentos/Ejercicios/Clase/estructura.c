#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct def_Alumno{
  char nombre[30];
  char cuenta[15];
  float cal[3];
}tipoAlumno;

void Pedir(tipoAlumno Alumnos[5]);
void Imprimir(tipoAlumno Alumno[5]);

int main(void){
  tipoAlumno Alumnos[5];
  Pedir(Alumnos);
  Imprimir(Alumnos);
  exit(0);
}

void Pedir(tipoAlumno Alumnos[5]){
  int i,j;
  printf("Introduce los 5 alumnos:\n");
  for(i=0;i<2;i++){
    printf("Introduce al alumno #%d: ", i+1);
    __fpurge(stdin);
    gets(Alumnos[i].nombre);
    printf("Introduce el numero de cuenta: ");
    gets(Alumnos[i].cuenta);
    for(j=0;j<3;j++){
      printf("Introduce la calificacion #%d: ",j+1);
      scanf("%f",&Alumnos[i].cal[j]);
    }
    putchar('\n');
  }
}

void Imprimir(tipoAlumno Alumno[5]){
  int i,j;
   for(i=0;i<2;i++){
      printf("El promedio de %s con cuenta %s es: %.2f\n", Alumno[i].nombre,Alumno[i].cuenta,(Alumno[i].cal[0]+Alumno[i].cal[1]+Alumno[i].cal[2])/3);
      puts(Alumno[i].nombre);
   }
}
