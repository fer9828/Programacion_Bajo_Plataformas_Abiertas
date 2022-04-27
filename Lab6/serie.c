#include <stdio.h>
#include <math.h>


int CalcularFactorial(int numero) 
{
  int fact = 0;

  for (int j = 1; j <= numero; j++) {
    fact = fact * j;
  }

  return fact;
}

double CalcularValorSerie(double x, int n) {
  double valor = 0.0;
  double xpow = 1;

  for (int k = 0; k <= n; k++) {
    valor += xpow / CalcularFactorial(k);
    xpow = xpow * x;
  }

  return valor;
}

int main() 
{
  printf("Este programa calcula el valor de la serie:\n");
  printf"(x^0)/0! + (x^1)/1! + (x^2)/2! + (x^3)/3! + (x^4)/4! + ........ + (x^n)/n! \n");
  printf("Ingrese el valor de x : \n");
  
  double x;
  scanf("%f",&x);

  int n;
  printf("\nIntroduzca un valor entero para n : \n");
  scanf("%d",&n;
  
  double valorserie = CalcularValorSerie(x, n);
  printf("El resultado de la serie para los valores ingresados es %f\n",valorserie) 

  return 0;
}
