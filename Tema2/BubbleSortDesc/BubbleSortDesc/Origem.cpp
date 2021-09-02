#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vet[]);

#define TAMANHOVETOR 10

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL));

	//INSER��O DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 100;

	printf("VETOR NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME N�O ORDENADO
		printf("%d\n", vet[i]);

	BubbleSort(vet);

	//IMPRESS�O DE RESULTADOS
	printf("VETOR ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME ORDENADO
		printf("%d\n", vet[i]);


	printf("\n");
	system("pause");
	return 0;
}

void BubbleSort(int vet[])
{
	int aux;
	for (int n = 1; n <= TAMANHOVETOR; n++) //La�o para o tamanho do vetor
	{
		for (int i = 0; i < (TAMANHOVETOR - 1); i++) //La�o da 1� at� a penultima posi��o
		{
			if (vet[i] < vet[i + 1])
			{
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}

		}

	}

}