#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMLETRAS 101
#define NUMFRASES 8000
//#define NUMFRASES 1000

int main()
{
	char frase[NUMFRASES][NUMLETRAS] = { 0 };
	char aux[NUMLETRAS];
	int i, n, j;
	srand(time(NULL));
	printf("%d", sizeof(char));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < NUMFRASES; i++)
	{
		for (int j = 0; j < NUMLETRAS; j++)
		{
			frase[i][j] = 'A' + (rand() % 26);
			//printf("%c", frase[i][j]);
		}
		//printf("\n");
	}

	clock_t t;
	t = clock();

	//BUBBLE SORT
	for (n = 1; n <= NUMFRASES; n++) //Laço para o tamanho do vetor
	{
		for (i = 0; i < (NUMFRASES - 1); i++) //Laço da 1ª até a penultima posição
		{
			if ((strcmp(frase[i], frase[i + 1])) > 0)
			{
				//strcpy
				for (j = 0; j < NUMLETRAS; j++)
					aux[j] = frase[i][j];
				for (j = 0; j < NUMLETRAS; j++)
					frase[i][j] = frase[i + 1][j];
				for (j = 0; j < NUMLETRAS; j++)
					frase[i + 1][j] = aux[j];
			}
		}
	}

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 

													  //IMPRIME ORDENADO
	/*for (int i = 0; i < NUMFRASES; i++)
	{
		for (int j = 0; j < NUMLETRAS; j++)
		{
			printf("%c", frase[i][j]);
		}
		printf("\n");
	}*/

	printf("\n");
	printf("Took %f seconds to execute \n", time_taken);

	system("pause");
	return 0;
}