#include <stdio.h>
#include <stdlib.h>

#define NUMERO_VERTICES 6

struct ListaDeVizinhos
{
	int vertice;
	ListaDeVizinhos* prox;
};

struct Grafo
{
	int TotalVertices;
	struct ListaDeVizinhos** ListaAdj; //Será um vetor do tamanho do numero de vértices
};

struct QUEUE //Fila dos vértices a serem visitados
{
	int vertice;
	struct ListaDeVizinhos** ListaAdj;
	QUEUE* prox;
}*top = NULL;
int tam = 0;

struct Grafo* CriarGrafo(int vertices);
void AdicionarAresta(struct Grafo* Grafo, int origem, int destino);
void MostrarGrafo(struct Grafo* Grafo);
void BuscaLargura(Grafo* Vizinhos, int v, int marcado[], int dist[]);
void queue(int y);
void dequeue();

int main()
{
	int marcado[NUMERO_VERTICES] = { 0 };
	int* dist = (int*)malloc(sizeof(int));;
	int origem;

	Grafo* GrafoTeste = CriarGrafo(NUMERO_VERTICES);
	AdicionarAresta(GrafoTeste, 0, 1);
	AdicionarAresta(GrafoTeste, 0, 2);
	AdicionarAresta(GrafoTeste, 1, 3);
	AdicionarAresta(GrafoTeste, 2, 3);
	AdicionarAresta(GrafoTeste, 3, 4);
	AdicionarAresta(GrafoTeste, 3, 5);

	printf("Escolha um vertice para iniciar a busca:\n");
	scanf_s("%d", &origem);

	MostrarGrafo(GrafoTeste);

	printf("\nVertices visitados do grafo, iniciando em V%d:\n", origem);
	BuscaLargura(GrafoTeste, origem, marcado, dist);

	printf("\n");
	system("pause");
	return 0;
}

struct Grafo* CriarGrafo(int TotalVertices)
{
	Grafo* Grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
	Grafo->TotalVertices = TotalVertices;
	Grafo->ListaAdj = (struct ListaDeVizinhos**)malloc(TotalVertices * sizeof(struct ListaDeVizinhos*));

	for (int i = 0; i < TotalVertices; i++)
		Grafo->ListaAdj[i] = NULL;

	return Grafo;
}

void AdicionarAresta(struct Grafo* Grafo, int origem, int destino)
{ //INSERÇÃO NO INICIO DA LISTA 
  // Adiciona uma aresta da origem para o  destino
	struct ListaDeVizinhos* NovoElemento = (struct ListaDeVizinhos*)malloc(sizeof(struct ListaDeVizinhos));
	NovoElemento->vertice = destino;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[origem];
	Grafo->ListaAdj[origem] = NovoElemento;

	// Adiciona uma aresta do destino para a origem
	NovoElemento = (struct ListaDeVizinhos*)malloc(sizeof(struct ListaDeVizinhos));
	NovoElemento->vertice = origem;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[destino];
	Grafo->ListaAdj[destino] = NovoElemento;
}

void MostrarGrafo(struct Grafo* Grafo)
{
	int v;
	for (v = 0; v < Grafo->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = Grafo->ListaAdj[v];
		printf("\n Lista de adjacencias do vertice %d:\n ", v);
		while (ElementoVarredura != NULL)
		{
			printf("%d -> ", ElementoVarredura->vertice);
			ElementoVarredura = ElementoVarredura->prox;
		}
		printf("\n");
	}
}

void BuscaLargura(Grafo* Vizinhos, int v, int marcado[], int dist[])
{
	ListaDeVizinhos* ElementoVarredura;
	ElementoVarredura = (struct ListaDeVizinhos*)malloc(sizeof(struct ListaDeVizinhos));
	int w;
	int vertice;

	marcado[v] = 1;
	dist[v] = 0;
	printf("V%d\t", v);
	queue(v); //fila

	while (top != NULL) {
		vertice = top->vertice;

		//for (int i = 1; i <= tam; i++)
		//{
			ElementoVarredura = Vizinhos->ListaAdj[vertice];
			while (ElementoVarredura != NULL)
			{
				w = ElementoVarredura->vertice;
				if (marcado[w] != 1)
				{
					printf("V%d\t", w);
					marcado[w] = 1;
					dist[w] = dist[vertice] + 1;
					queue(w);
				}
				ElementoVarredura = ElementoVarredura->prox;
			}
			dequeue(); //remover fila
		//}

	}
}

void queue(int y)
{ //função push, coloca um elemento na fila

	QUEUE* NovoElemento;
	NovoElemento = (struct QUEUE*)malloc(sizeof(struct QUEUE));
	NovoElemento->vertice = y;
	QUEUE* ElementoVarredura;
	ElementoVarredura = (struct QUEUE*)malloc(sizeof(struct QUEUE));
	ElementoVarredura = top;
	if (top == NULL)
	{
		top = NovoElemento;
		top->prox = NULL;
		tam++;
	}
	else
	{
		while (ElementoVarredura->prox != NULL)
		{
			ElementoVarredura = ElementoVarredura->prox;
		}
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
		tam++;
	}
}

void dequeue()
{ //função pop, remove um elemento na fila

	QUEUE* NovoElemento;
	NovoElemento = (struct QUEUE*)malloc(sizeof(struct QUEUE));

	if (top == NULL)
	{
		return;
	}
	else
	{
		NovoElemento = top;
		top = top->prox;
		free(NovoElemento);
		tam--;
		return;
	}
}