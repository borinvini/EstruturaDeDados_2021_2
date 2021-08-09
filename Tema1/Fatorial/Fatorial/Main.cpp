#include <stdio.h>
#include <stdlib.h>

int fatorial(int valor);

int main() {
	int valor = 0;
	int resultado = 1;

	printf("Digite um valor inteiro para calcular o fatorial.\n");
	scanf_s("%d", &valor);

	resultado = fatorial(valor);
	//5!
	//5 * 4!
	//5 * 4 * 3!
	//5 * 4 * 3 * 2!
	//5 * 4 * 3 * 2 * 1!
	//5 * 4 * 3 * 2 * 1 * 0!

	printf("O fatorial de %d eh: %d\n", valor, resultado);

	system("pause");
	return 0;
}

int fatorial(int n)
{
	int fat = 1;

	if (n == 0)
	{
		return fat;
	}
	else
	{
		fat = n * fatorial(n - 1);
	}
}