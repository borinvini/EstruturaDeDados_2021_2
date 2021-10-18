#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMLETRAS 101
#define NUMFRASES 8000
//#define NUMFRASES 1000

int main()
{
	char frase[NUMFRASES][NUMLETRAS] = {0};
	char *aux;
	char *pfrase[NUMFRASES];
	int i, n, j;
	srand(time(NULL));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < NUMFRASES; i++)
	{
		for (int j = 0; j < NUMLETRAS - 1; j++)
		{
			frase[i][j] = 'A' + (rand() % 26);
			//printf("%c", frase[i][j]);
		}
		//printf("\n");
	}

	clock_t t;
	t = clock();
	for (i = 0; i < NUMFRASES; i++)
		pfrase[i] = *(frase+i);

	//BUBBLE SORT
	for (n = 1; n <= NUMFRASES; n++) //Laço para o tamanho do vetor
	{
		for (i = 0; i < (NUMFRASES - 1); i++) //Laço da 1ª até a penultima posição
		{
			//strcpy(f1, *(pfrase[i]));
			if ((strcmp(pfrase[i], pfrase[i + 1])) > 0)
			{
				aux = pfrase[i];
				pfrase[i] = pfrase[i + 1];
				pfrase[i + 1] = aux;
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
			printf("%c", *(pfrase[i]+j));
		}
		printf("\n");
	}*/

	printf("\n");
	printf("Took %f seconds to execute \n", time_taken);

	system("pause");
	return 0;
}