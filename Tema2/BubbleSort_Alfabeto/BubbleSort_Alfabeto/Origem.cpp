/*
Fa�a um programa que cadastre o nome e o sal�rio de N funcion�rios,
onde N � uma quantidade escolhida pelo usu�rio.
Liste todos os funcion�rios e seus respectivos sal�rios ordenados
de acordo com o que � pedido nos itens abaixo.
IMPLEMENTA��O COM BUBBLE SORT.

Ordene por ordem ALFAB�TICA;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHOVETOR 5
#define TAMANHONOME  30

int main()
{
	struct CadastroFuncionario
	{
		char Nome[TAMANHONOME];
		int Salario;
	};

	int vet[TAMANHOVETOR] = { 0 };
	int i, n, auxS;
	char c;
	char auxN[TAMANHONOME];
	CadastroFuncionario Funcionario[TAMANHOVETOR];

	//INSER��O DE DADOS
	for (i = 0; i < TAMANHOVETOR; i++)
	{
		printf("Digite o nome do funcionario %d: ", i + 1);
		gets_s(Funcionario[i].Nome);
		printf("\n");

		printf("Digite o salario do funcionario %d: ", i + 1);
		scanf_s("%d", &Funcionario[i].Salario);
		printf("\n");
		while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer teclado
	}

	//BUBBLE SORT
	for (n = 1; n <= TAMANHOVETOR; n++) //La�o para o tamanho do vetor
	{
		for (i = 0; i < (TAMANHOVETOR - 1); i++) //La�o da 1� at� a penultima posi��o
		{
			if (strcmp(Funcionario[i].Nome, Funcionario[i+1].Nome) > 0)
			{// Trocar esta condi��o e testar as strings usando STRCMP
				auxS = Funcionario[i].Salario;
				Funcionario[i].Salario = Funcionario[i + 1].Salario;
				Funcionario[i + 1].Salario = auxS;

				strcpy_s(auxN, Funcionario[i].Nome);
				strcpy_s(Funcionario[i].Nome, Funcionario[i + 1].Nome);
				strcpy_s(Funcionario[i + 1].Nome, auxN);

			}

		}

	}

	//IMPRESS�O DE RESULTADOS
	for (i = 0; i < TAMANHOVETOR; i++)
		printf("Funcionario %d, com nome %s e salario %d. \n", i + 1, Funcionario[i].Nome, Funcionario[i].Salario);

	printf("\n");
	system("pause");
	return 0;
}