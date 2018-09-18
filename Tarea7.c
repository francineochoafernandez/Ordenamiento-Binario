# Ordenamiento-Binario
#include <stdio.h>
#include <stdlib.h>
 
int Location(int Arreglo[], int low, int high, int x)
{
  int mid;
  if (high >= low)
  {
    mid = low + (high - low)/2;
 
    //Si el elemento esta justo en la mitad
    if (Arreglo[mid] == x)
    {
      return mid;
    }
 
    //Si el elemento es menor que mid, entonces estara en el lado izquierdo del arreglo
    if (Arreglo[mid] > x)
    {
      return Location(Arreglo, low, mid-1, x);
    }
 
    //El elemento es mayor que mid, entonces estara en el lado derecho del arreglo
    return Location(Arreglo, mid+1, high, x);
  }
 
  //Si el elemento no esta en el arreglo
  return 40;
 
}
 
int main(void)
{
  int i,j,a,n,*Arreglo,x,resultado;
 
  printf("\nHola este programa recibe una cadena de numeros de la longitud deseada. \n");
 
  printf("\nDame la longitud del arreglo que vas a ingresar: \n");
  scanf("%i",&n);
 
  //Creando arreglo
  Arreglo =(int*)malloc(n*sizeof(int));
 
  //Pidiendo numeros para el Arregloprintf("\nEscribe los numeros separados por enter: \n");
  printf("\nDame los valores del que deseas ingresar al arreglo separados por enter:\n");
  for(i=0;i<n;i++)
  {
    scanf("%i",&Arreglo[i]);
  }
 
  //Imprimiendo valores del arreglo original
  printf("\nTu arreglo ORIGINAL es: \n");
  for(i=0;i<n;i++)
  {
    printf("%i ", Arreglo[i]);
  }
  printf("\n");
 
  //Ordenando
  for(i= 0;i<n;++i)
  {
    for(j=i+1;j<n;++j)
   {
     if (Arreglo[i] > Arreglo[j])
     {
       a = Arreglo[i];
       Arreglo[i] = Arreglo[j];
       Arreglo[j] = a;
     }
   }
  }
 
  //Imprimiendo valores del arreglo nuevo
  printf("\nTu arreglo ORDENADO en orden ascendente es: \n");
  for(i=0;i<n;i++)
  {
    printf("%i ",Arreglo[i]);
  }
  printf("\n");
 
  //Pidiendo valor a buscar
  printf("\nDame el valor que quieres buscar en el arreglo: \n");
  scanf("%i",&x);
 
  resultado= Location(Arreglo,0,n-1,x);
 
  if(resultado== 40)
  {
    printf("\nEl elemento no esta presente en el arreglo. \n \n");
  }
  else
  {
    printf("\nEl elemento %i  esta presente en la posicion %i del arreglo. \n \n",x,resultado);
  }
 
  free (Arreglo);
  return 0;
}
