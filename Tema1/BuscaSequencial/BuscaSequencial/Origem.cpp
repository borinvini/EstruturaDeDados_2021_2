#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BuscaSequencial(int vet[], int buscado);

#define TAMANHOVETOR 10

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	int buscado, achou, i;
	srand(time(NULL));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 1000;

	printf("VETOR GERADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%d\n", vet[i]);

	printf("Selecione um valor para buscar: \n");
	scanf_s("%d", &buscado);

	achou = BuscaSequencial(vet, buscado);

	if (achou == -1)
		printf("Valor nao encontrado. \n");
	else
		printf("Valor encontrado na posicao %d. \n", achou);

	system("pause");
	return 0;

}

int BuscaSequencial(int vet[], int buscado)
{
	int achou, i;
	achou = 0;
	i = 0;
	while ((i <= TAMANHOVETOR) && (achou == 0))
	{
		if (vet[i] == buscado)
			achou = 1;
		else
			i++;
	}

	if (achou == 0)
		return -1;
	else
		return i + 1;

}