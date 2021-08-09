#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BuscaBinaria(int vet[], int inicio, int fim, int chave);
void BubbleSort(int vet[]);

#define TAMANHOVETOR 10

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	int buscado, achou, i;
	srand(time(NULL));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 1000;

	printf("VETOR GERADO NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%d\n", vet[i]);

	BubbleSort(vet);
	printf("VETOR GERADO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%d\n", vet[i]);

	printf("Selecione um valor para buscar: \n");
	scanf_s("%d", &buscado);

	achou = BuscaBinaria(vet, 0, TAMANHOVETOR - 1, buscado);

	if (achou == -1)
		printf("Valor nao encontrado. \n");
	else
		printf("Valor encontrado na posicao %d. \n", achou);

	system("pause");
	return 0;

}

int BuscaBinaria(int vet[], int inicio, int fim, int chave)
{
	while (inicio <= fim)
	{
		int meio = (inicio + fim) / 2;
		if (chave > vet[meio])
			inicio = meio + 1;
		else if (chave < vet[meio])
			fim = meio - 1;
		else
			return meio;
	}
	return -1;

}

void BubbleSort(int vet[])
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