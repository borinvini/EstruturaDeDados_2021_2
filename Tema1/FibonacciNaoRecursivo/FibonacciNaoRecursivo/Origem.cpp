#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main() {
	int n;
	int result;
	
	printf("Digite um valor inteiro para calcular a sequencia de Fibonacci.\n");
	scanf_s("%d", &n);

	result = fib(n);
	printf("O ultimo valor eh: %d\n",result);

	system("pause");
	return 0;
}

int fib(int n)
{
	int i, fib1 = 0, fib2 = 1, soma;

	for (i = 3; i <= n; i = i + 1)
	{
		soma = fib1 + fib2;
		fib1 = fib2;
		fib2 = soma;
	}
	return fib2;
}
