#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
int main()
{
	int m; //declara e inicializa a vari�vel de controle da dimens�o da matriz quadrada
	float mat[10][10]; //matriz de n�meros reais, dimens�es m�ximas 10 x 10
	float somalin[10]; //vetor de reais, armazena a soma dos elementos das linhas da matriz, dimens�o m�xima 10
	float somacol[10]; //vetor de reais, armazena a soma dos elementos das linhas da matriz, dimens�o m�xima 10
	float somadiag1 = 0; //vetor de reais, armazena a soma dos elementos da diagonal principal da matriz, dimens�o m�xima 10
	float somadiag2 = 0; //vetor de reais, armazena a soma dos elementos da diagonal secund�ria da matriz, dimens�o m�xima 10
	float aux = 0; //vari�vel auxiliar real para acumular a soma dos elementos dos vetores
	setlocale(LC_ALL, "Portuguese");
	printf("Programa QUADPERF REAL 1.0 desenvolvido por Rone Ant�nio de Azevedo, em 13/04/2020.");
	printf("\nVerifica se as matrizes quadradas com at� dez linhas e elementos n�meros reais s�o perfeitas.\n");
	do//procedimento para entrada das dimens�es m x m da matriz quadrada
	{
		printf("\nDigite o n�mero total de linhas da matriz quadrada : ");
		scanf_s("%i", &m); //permite definir as dimens�es da matriz quadrada de ordem m
		if ((m >= 1) && (m <= 10)) //testa se a dimens�o da matriz est� no intervalo 1 a 10
		{
			printf("\n ");
			printf("\nDigite os elementos (i,j) da matriz, linha a linha:\n");
		}
		else //obriga o usu�rio a digitar o valor correto da dimens�o
			printf("\nDimens�o inv�lida, digite o valor no intervalo 1 a 10!\n");
	} while ((m >= 1) || (m <= 10));
	for (int i = 1; i <= m; i++) //la�o para digita��o dos elementos da matriz quadrada
	{
		for (int j = 1; j <= m; j++) //orienta melhor o usu�rio na digita��o dos elementos
		{
			printf("\nLinha %d , Coluna %d : elemento (%d,%d) = ", i, j, i, j);
			scanf_s("%f", &mat[i][j]);
		}
	}
	//gera��o do vetor somalin[n] contendo a soma dos elementos das linhas da matriz m x m
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= m; i++)
		{
			aux = aux + mat[i][j];
		}
		somalin[j] = aux;
		aux = 0;
	}
	//gera��o do vetor somacol[n] contendo a soma dos elementos das colunas da matriz m x m
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			aux = aux + mat[i][j];
		}
		somacol[i] = aux;
		aux = 0;
	}
	//gera��o da vari�vel somadig1 contendo a soma dos elementos da diagonal principal da matriz m x m
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j)
				somadiag1 = somadiag1 + mat[i][j];
		}
	}
	//gera��o da vari�vel somadig2 contendo a soma dos elementos da diagonal secund�ria da matriz m x m
	for (int i = m; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == m + 1 - j)
				somadiag2 = somadiag2 + mat[i][j];
		}
	}
	printf("\nRELAT�RIO DE RESULTADOS DA MATRIZ %d x %d : ", m, m); //impress�o dos resultados
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
	printf("\nSoma dos elementos da diagonal secund�ria: %6.6f", somadiag2);
	printf("\n ");
	//teste para verifica��o de igualdade entre os resultados das somas das linhas e colunas
	//tratando de n�meros reais, requer a compara��o por precis�o absoluta, adotada 1 milion�simo
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (abs(somalin[i] - somacol[j]) > 0.000001)
			{
				printf("\nAs linhas e colunas da matriz t�m soma diferente!");
				printf("\n\nCONCLUS�O: Matriz n�o � quadrado perfeito!");
				return 0;
				system("pause");
			}
		}
	}
	printf("\n\nTodas as linhas e colunas da matriz analisada possuem a mesma soma!");//resultado do la�o, segue para pr�ximo teste
	//teste para verifica��o de igualdade entre os resultados das somas das diagonais, precis�o de 1 milion�simo
	if (abs(somadiag1 - somadiag2) > 0.000001)
	{
		printf("\nAs diagonais n�o possuem a mesma soma!");
		printf("\n\nCONCLUS�O: Matriz n�o � quadrado perfeito!");
		return 0;
		system("pause");
	}
	printf("\n\nAs duas diagonais da matriz analisada possuem a mesma soma!");//resultado do la�o, segue para �ltimo teste
	//teste para verifica��o de igualdade entre os resultados das somas das linhas, colunas e diagonais, precis�o de 1 milion�simo
	if (abs(somalin[1] - somadiag1) > 0.000001)
	{
		printf("\nAs linhas, colunas e diagonais n�o possuem a mesma soma!");
		printf("\n\nCONCLUS�O: Matriz n�o � quadrado perfeito!");
		return 0;
		system("pause");
	}
	printf("\n\nAs linhas, colunas e diagonais possuem a mesma soma!");//resultado do la�o, segue para a conclus�o
	printf("\n\nCONCLUS�O: Matriz � quadrado perfeito!");
	system("pause");
}
