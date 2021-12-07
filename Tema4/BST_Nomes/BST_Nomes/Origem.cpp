#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
int main()
{
	int m; //declara e inicializa a variável de controle da dimensão da matriz quadrada
	float mat[10][10]; //matriz de números reais, dimensões máximas 10 x 10
	float somalin[10]; //vetor de reais, armazena a soma dos elementos das linhas da matriz, dimensão máxima 10
	float somacol[10]; //vetor de reais, armazena a soma dos elementos das linhas da matriz, dimensão máxima 10
	float somadiag1 = 0; //vetor de reais, armazena a soma dos elementos da diagonal principal da matriz, dimensão máxima 10
	float somadiag2 = 0; //vetor de reais, armazena a soma dos elementos da diagonal secundária da matriz, dimensão máxima 10
	float aux = 0; //variável auxiliar real para acumular a soma dos elementos dos vetores
	setlocale(LC_ALL, "Portuguese");
	printf("Programa QUADPERF REAL 1.0 desenvolvido por Rone Antônio de Azevedo, em 13/04/2020.");
	printf("\nVerifica se as matrizes quadradas com até dez linhas e elementos números reais são perfeitas.\n");
	do//procedimento para entrada das dimensões m x m da matriz quadrada
	{
		printf("\nDigite o número total de linhas da matriz quadrada : ");
		scanf_s("%i", &m); //permite definir as dimensões da matriz quadrada de ordem m
		if ((m >= 1) && (m <= 10)) //testa se a dimensão da matriz está no intervalo 1 a 10
		{
			printf("\n ");
			printf("\nDigite os elementos (i,j) da matriz, linha a linha:\n");
		}
		else //obriga o usuário a digitar o valor correto da dimensão
			printf("\nDimensão inválida, digite o valor no intervalo 1 a 10!\n");
	} while ((m >= 1) || (m <= 10));
	for (int i = 1; i <= m; i++) //laço para digitação dos elementos da matriz quadrada
	{
		for (int j = 1; j <= m; j++) //orienta melhor o usuário na digitação dos elementos
		{
			printf("\nLinha %d , Coluna %d : elemento (%d,%d) = ", i, j, i, j);
			scanf_s("%f", &mat[i][j]);
		}
	}
	//geração do vetor somalin[n] contendo a soma dos elementos das linhas da matriz m x m
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= m; i++)
		{
			aux = aux + mat[i][j];
		}
		somalin[j] = aux;
		aux = 0;
	}
	//geração do vetor somacol[n] contendo a soma dos elementos das colunas da matriz m x m
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			aux = aux + mat[i][j];
		}
		somacol[i] = aux;
		aux = 0;
	}
	//geração da variável somadig1 contendo a soma dos elementos da diagonal principal da matriz m x m
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j)
				somadiag1 = somadiag1 + mat[i][j];
		}
	}
	//geração da variável somadig2 contendo a soma dos elementos da diagonal secundária da matriz m x m
	for (int i = m; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == m + 1 - j)
				somadiag2 = somadiag2 + mat[i][j];
		}
	}
	printf("\nRELATÓRIO DE RESULTADOS DA MATRIZ %d x %d : ", m, m); //impressão dos resultados
	printf("\n");
	for (int i = 1; i <= m; i++) //imprime os elementos da matriz m x m
	{
		printf("[ ");
		for (int j = 1; j <= m; j++)
		{
			printf("%6.6f ", mat[i][j]);
		}
		printf("]\n");
	}
	//imprime os elementos do vetor soma das linhas da matriz m x m
	for (int i = 1; i <= m; i++)
	{
		printf("\nSoma dos elementos da linha %d : %6.6f", i, somalin[i]);
		printf("\n ");
	}
	//imprime os elementos do vetor soma das linhas da matriz m x m
	for (int i = 1; i <= m; i++)
	{
		printf("\nSoma dos elementos da linha %d : %6.6f", i, somalin[i]);
		printf("\n ");
	}
	//imprime os elementos do vetor soma das colunas da matriz m x m
	for (int j = 1; j <= m; j++)
	{
		printf("\nSoma dos elementos da coluna %d : %6.6f", j, somacol[j]);
		printf("\n ");
	}
	//imprime os resultados da soma das duas diagonais da matriz m x m
	printf("\nSoma dos elementos da diagonal principal: %6.6f", somadiag1);
	printf("\n ");
	printf("\nSoma dos elementos da diagonal secundária: %6.6f", somadiag2);
	printf("\n ");
	//teste para verificação de igualdade entre os resultados das somas das linhas e colunas
	//tratando de números reais, requer a comparação por precisão absoluta, adotada 1 milionésimo
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (abs(somalin[i] - somacol[j]) > 0.000001)
			{
				printf("\nAs linhas e colunas da matriz têm soma diferente!");
				printf("\n\nCONCLUSÃO: Matriz não é quadrado perfeito!");
				return 0;
				system("pause");
			}
		}
	}
	printf("\n\nTodas as linhas e colunas da matriz analisada possuem a mesma soma!");//resultado do laço, segue para próximo teste
	//teste para verificação de igualdade entre os resultados das somas das diagonais, precisão de 1 milionésimo
	if (abs(somadiag1 - somadiag2) > 0.000001)
	{
		printf("\nAs diagonais não possuem a mesma soma!");
		printf("\n\nCONCLUSÃO: Matriz não é quadrado perfeito!");
		return 0;
		system("pause");
	}
	printf("\n\nAs duas diagonais da matriz analisada possuem a mesma soma!");//resultado do laço, segue para último teste
	//teste para verificação de igualdade entre os resultados das somas das linhas, colunas e diagonais, precisão de 1 milionésimo
	if (abs(somalin[1] - somadiag1) > 0.000001)
	{
		printf("\nAs linhas, colunas e diagonais não possuem a mesma soma!");
		printf("\n\nCONCLUSÃO: Matriz não é quadrado perfeito!");
		return 0;
		system("pause");
	}
	printf("\n\nAs linhas, colunas e diagonais possuem a mesma soma!");//resultado do laço, segue para a conclusão
	printf("\n\nCONCLUSÃO: Matriz é quadrado perfeito!");
	system("pause");
}
