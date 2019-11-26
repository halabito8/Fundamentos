#include<stdio.h>

void calcular(int base,int num);

int main(void){
  int base,num;
  printf("Dame un numero en base 10: ");
  scanf("%i",&num);
  do{
    printf("A que base lo quieres pasar(entre 2 y 16)? ");
    scanf("%i",&base);
    if(base<2||base>16)
      printf("Favor de poner un valor dentro de los parametros.\n");
  }while(base<2||base>16);
  calcular(base,num);
}

void calcular(int base,int num){
  int cant;
  cant=num;
  switch(base){
  case 4:while(num!=0){
           cant=num%4;
           printf("%i",cant);
	   num=num/4;
    }
    printf("\n");
    break;
    case 3:while(num!=0){
           cant=num%3;
           printf("%i",cant);
	   num=num/3;
    }
    printf("\n");
    break;
    case 2:while(num!=0){
           cant=num%2;
           printf("%i",cant);
	   num=num/2;
    }
    printf("\n");
    break;
    case 5:while(num!=0){
           cant=num%5;
           printf("%i",cant);
	   num=num/5;
    }
    printf("\n");
    break;
    case 6:while(num!=0){
           cant=num%6;
           printf("%i",cant);
	   num=num/6;
    }
    printf("\n");
    break;
    case 7:while(num!=0){
           cant=num%7;
           printf("%i",cant);
	   num=num/7;
    }
    printf("\n");
    break;
    case 8:while(num!=0){
           cant=num%8;
           printf("%i",cant);
	   num=num/8;
    }
    printf("\n");
    break;
    case 9:while(num!=0){
           cant=num%9;
           printf("%i",cant);
	   num=num/9;
    }
    printf("\n");
    break;
    case 10:while(num!=0){
           cant=num%10;
           printf("%i",cant);
	   num=num/10;
    }
    printf("\n");
    break;
    case 11:while(num!=0){
           cant=num%11;
           if(cant<10)
             printf("%i",cant);
	   else if(cant==10)
	     printf("A");
	   num=num/11;
    }
    printf("\n");
    break;
    case 12:while(num!=0){
           cant=num%12;
           if(cant<10)
             printf("%i",cant);
	   else if(cant==10)
	     printf("A");
	   else if(cant==11)
	     printf("B");
	   num=num/12;
    }
    printf("\n");
    break;
    case 13:while(num!=0){
           cant=num%13;
           if(cant<10)
             printf("%i",cant);
	   else if(cant==10)
	     printf("A");
	   else if(cant==11)
	     printf("B");
	   else if(cant==12)
	     printf("C");
	   num=num/13;
    }
    printf("\n");
    break;
    case 14:while(num!=0){
           cant=num%14;
           if(cant<10)
             printf("%i",cant);
	   else if(cant==10)
	     printf("A");
	   else if(cant==11)
	     printf("B");
	   else if(cant==12)
	     printf("C");
	   else if(cant==13)
	     printf("D");
	   num=num/14;
    }
    printf("\n");
    break;
    case 15:while(num!=0){
           cant=num%15;
           if(cant<10)
             printf("%i",cant);
	   else if(cant==10)
	     printf("A");
	   else if(cant==11)
	     printf("B");
	   else if(cant==12)
	     printf("C");
	   else if(cant==13)
	     printf("D");
	   else if(cant==14)
	     printf("E");
	   num=num/15;
    }
    printf("\n");
    break;
    case 16:while(num!=0){
           cant=num%16;
	   if(cant<10)
             printf("%i",cant);
	   else if(cant==10)
	     printf("A");
	   else if(cant==11)
	     printf("B");
	   else if(cant==12)
	     printf("C");
	   else if(cant==13)
	     printf("D");
	   else if(cant==14)
	     printf("E");
	   else if(cant==15)
	     printf("F");
	   num=num/16;
    }
    printf("\n");
    break;
    
  }
}
