#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(char vet[]);

#define TAMANHOVETOR 5

int main()
{
	char vet[TAMANHOVETOR];
	srand(time(NULL));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = 'A' + (rand() % 26);

	printf("VETOR NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME NÃO ORDENADO
		printf("%c\n", vet[i]);

	BubbleSort(vet);

	//IMPRESSÃO DE RESULTADOS
	printf("VETOR ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME ORDENADO
		printf("%c\n", vet[i]);


	printf("\n");
	system("pause");
	return 0;
}

void BubbleSort(char vet[])
{
	int aux;
	for (int n = 1; n <= TAMANHOVETOR; n++) //Laço para o tamanho do vetor
	{
		for (int i = 0; i < (TAMANHOVETOR - 1); i++) //Laço da 1ª até a penultima posição
		{
			if (vet[i] > vet[i + 1])
			{
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}
		}
	}
}