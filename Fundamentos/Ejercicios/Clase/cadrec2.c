#include<stdio.h> 
#include<string.h> 
 
void invertir(char cadena[200],char frase2[200]); 
void pegar(char cadena[200],char frase2[200]);
 
int main (void){ 
  char frase[200], frase2[200];
  printf("Dame un frase: "); 
  gets(frase); 
  printf("Tu frase invertida es: "); 
  invertir(frase,frase2); 
  puts(frase2); 
} 
 
void invertir(char cadena[200],char frase2 [200]){
  int lon=strlen(cadena);
  frase2[strlen(cadena)]='\0';
  if(*cadena!='\0'){
    invertir(cadena+1,frase2); 
    *(frase2+lon-1)=*cadena;}
}
