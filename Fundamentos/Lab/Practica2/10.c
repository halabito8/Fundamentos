#include<stdio.h>
#include<string.h>

void validar(long unsigned d1,long unsigned m1,long unsigned a1,long unsigned d2,long unsigned m2,long unsigned a2);
void convertir(long unsigned d1,long unsigned m1,long unsigned a1,long unsigned d2,long unsigned m2,long unsigned a2,long unsigned *f1,long unsigned *f2);
void validaris(long unsigned f1,long unsigned f2,long unsigned *x);

int main(void){
  long unsigned d1,m1,a1,d2,m2,a2,f1,f2,x;
  do{
    printf("Introduzca la primer fecha en dd/mm/aaaa: ");
    scanf("%lu/%lu/%lu", &d1,&m1,&a1);
    printf("Introduzca la segunda fecha en dd/mm/aaaa: ");
    scanf("%lu/%lu/%lu", &d2,&m2,&a2);
    validar(d1,m1,a1,d2,m2,a2);/*
    convertir(d1,m1,a1,d2,m2,a2,&f1,&f2);
    validars(f1,f2,&x);*/
  }while();
}

void convertir(long unsigned d1,long unsigned m1,long unsigned a1,long unsigned d2,long unsigned m2,long unsigned a2,long unsigned *f1,long unsigned *f2){
  long unsigned bisi,bisi2;
  bisi=m1;
  if(m1==1)
    m1=0;
  if(m1==2)
    m1=31;
  if(m1==3 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28;
  if(m1==4 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31;
  if(m1==5 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30;
  if(m1==6 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31;
  if(m1==7 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31+30;
  if(m1==8 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31+30+31;
  if(m1==9 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31+30+31+31;
  if(m1==10 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31+30+31+31+30;;
  if(m1==11 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31+30+31+31+30+31;
  if(m1==12 && (((a1%4!=0)&&(a1%100==0))||(a1%400!=0)))
    m1=31+28+31+30+31+30+31+31+30+31+30;
  if(bisi>=3 (((a1%4==0)&&(a1%100!=0))||(a1%400==0)))
    m1++;
  bisi=a1/4;
  a1=a1*365;
  a1=a1+bisi;
  *f1=d1+m1+a1;
  *f2=d2+m2+a2;
}

void validars(long unsigned f1,long unsigned f2,long unsigned *x){

}
void validar(long unsigned d1,long unsigned m1,long unsigned a1,long unsigned d2,long unsigned m2,long unsigned a2){
  
}
