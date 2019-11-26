#include<stdio.h>
#include<stdlib.h>

void encontrarcamino(char laberinto[8][8],int x,int y,int *caminos,int pasos,int array[1000],int *i);
void imprimir(char laberinto[8][8]);
void imppas(int array[1000]);

int main(void){
  char laberinto[8][8]={
{'x','x','x','x','x','x','x','x'},
{'x',' ','x','x','x','x','x','x'},
{'x',' ',' ',' ',' ',' ','x','x'},
{'x','x','x',' ','x',' ','x','x'},
{'x','x','x',' ','x',' ','x','x'},
{'x','x','x',' ',' ',' ','x','x'},
{'x','x','s',' ','x','x','x','x'},
{'x','x','x','x','x','x','x','x'}
};
  int i=0,x=1,y=1,caminos=0,pasos=0,array[1000]={0};
  imprimir(laberinto);
  encontrarcamino(laberinto,x,y,&caminos,pasos,array,&i);
  imprimir(laberinto);
  printf("Hay %i caminos.\n",caminos);
  imppas(array);
}

void encontrarcamino(char laberinto[8][8],int x,int y,int *caminos,int pasos,int array[1000],int *i){
  laberinto[x][y]='.';
  if(laberinto[x+1][y]==' '){
    encontrarcamino(laberinto,x+1,y,caminos,pasos+1,array,i);
    }  
  if(laberinto[x-1][y]==' '){
    encontrarcamino(laberinto,x-1,y,caminos,pasos+1,array,i);
    }
  if(laberinto[x][y+1]==' '){
    encontrarcamino(laberinto,x,y+1,caminos,pasos+1,array,i);
    }
  if(laberinto[x][y-1]==' '){
    encontrarcamino(laberinto,x,y-1,caminos,pasos+1,array,i);
    }
  if(laberinto[x+1][y]=='s'||laberinto[x-1][y]=='s'||laberinto[x][y+1]=='s'||laberinto[x][y-1]=='s'){
    (*caminos)++;
    array[*i]=pasos;
    (*i)++;
  }
  laberinto[x][y]=' ';
}

void imprimir(char laberinto[8][8]){
  int i,j;
  system("clear");
  for(i=0;i<=7;i++){
    for(j=0;j<=7;j++)
      putchar(laberinto[i][j]);
    putchar('\n');
  }
}

void imppas(int array[1000]){
  int i;
  for(i=0;i<1000;i++)
    if(array[i]!=0)
      printf("Los pasos son: %i.\n",array[i]);
}
