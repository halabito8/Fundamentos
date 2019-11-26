#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void){
  int array[2][3], i, j;
  for(i=0;i<2;i++){
    j=0;
    printf("Dame el numero para [%i][%i]: ", i, j);
    scanf("%i", &array[i][j]);
    j++;
    printf("Dame el numero para [%i][%i]: ", i, j);
    scanf("%i", &array[i][j]);
    j++;
    printf("Dame el numero para [%i][%i]: ", i, j);
    scanf("%i", &array[i][j]);

  }
  for(i=0;i<2;i++){
    j=0;
    printf("%i, ", array[i][j]);
    j++;
    printf("%i, ", array[i][j]);
    j++;
    printf("%i\n", array[i][j]);

  }
}
