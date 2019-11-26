#include<stdio.h>

int main(void){
  float tn, tm, da, dar, mu, ve, dm, dn, ry;
  int opcion;
  do{
    printf("\tEliga que opinion quiere?\n");
    printf("1. Rabi Yehuda\n");
    printf("2. Rabi Meir\n");
    printf("Opinion: ");
    scanf("%i", &opcion);
    if((opcion<=0)||(opcion>=3))
      printf("No existe ese tipo de opcion...\nFavor seleccione una valida.\n");
    }while((opcion<=0)||(opcion>=3));
  switch(opcion){
    case 2: printf("Cuanto vale el toro del mazik? ");
	    scanf("%f", &tm);
	    printf("Cuanto vale el toro del nizak originalmente? ");
	    scanf("%f", &tn);
	    printf("Cuanto vale la nebela (al momento de morir)? ");
	    scanf("%f", &mu);
	    printf("Cuanto vale la nebela al venderse? ");
	    scanf("%f", &ve);
	    da=tn-mu;
	    dar=da/2;
            dm=tm-dar;
            dn=ve+dar;
	    printf("Segun Rabi Meir:\n");
	    printf("El dano fue de: %.2f y el jatzi nezek fue de: %.2f\n", da, dar);
	    printf("El mazik tiene en la bolsa: %.2f de su toro - %.2f del jatzi nezek, en total: %.2f\n", tm, dar, dm);
	    printf("El nizak tiene en la bolsa: %.2f de la nebela + %.2f del jatzi nezek, en total: %.2f\n", ve, dar,  dn);
  	    break;
    case 1: printf("Cuanto vale el toro del mazik? ");
	    scanf("%f", &tm);
	    printf("Cuanto vale el toro del nizak originalmente? ");
	    scanf("%f", &tn);
	    printf("Cuanto vale la nebela (al momento de morir)? ");
	    scanf("%f", &mu);
	    printf("Cuanto vale la nebela al venderse? ");
	    scanf("%f", &ve);
	    da=tn-mu;
            dar=da/2;
	    ry=tm/2+ve/2;
	    ve=ve/2;
	    tm=tm/2;
	    printf("Segun Rabi Yehuda:\n");
	    printf("El dano fue de: %.2f y el jatzi nezek fue de: %.2f\n", da, dar);
	    printf("El mazik tiene en la bolsa: %.2f de la mitad del toro del mazik + %.2f de la mitad de la nebela, en total es: %.2f\n", tm, ve,  ry);
	    printf("El nizak tiene en la bolsa: %.2f de la mitad del toro del mazik + %.2f de la mitad de la nebela, en total es: %.2f\n", tm, ve,  ry);
  	    break;
  }
}
