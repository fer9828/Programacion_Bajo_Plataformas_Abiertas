/*	* @file Capicua.c
 	*  @brief Numero capicua
 	*  @author Fernando Jimenez Ureña
 	*  @details Este es un programa que permite determinar si un numero ingresado 
 	   es un capicua o no
*/

#include <stdio.h>
#include <stdlib.h>

int alreves(int n, int digitos)
{
	int resto, cociente;

	if (n<10)
	return n;
	else
	{
	resto = n % 10;
	cociente = n / 10;
	return resto*digitos + alreves(cociente, digitos / 10);
	}
}

int main()
{
	int num, rev;
	int digitos = 1;
	int tmp;
	printf("Digite un numero: \n");
	scanf("%d", &num);
  	// Hacemos un número 10^(numero de cifras-1) con esto alreves determinará el
	// número de cifras que tiene el número dado.
  	tmp =num;
  	while (tmp>=10)
    	{
      		tmp=tmp/10;
      		digitos=digitos*10;
    	}
  	rev = alreves(num, digitos);

  	// Determina si es un capicua o no.
  	if (rev==num)
    		printf("\nEs capicua. \n");
  	else
    		printf("\nNo es capicua. \n");

  	return 0;
}
