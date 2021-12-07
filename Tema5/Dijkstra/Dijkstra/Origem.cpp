#include <stdio.h>
#include<stdlib.h>

#define INFINITY 9999
#define MAX 10 //usado para definir o tamanho do vetor de distâncias do Djikstra

struct ListaDeVizinhos
{
	int vertice;
	int peso;
	ListaDeVizinhos* prox;
};

struct Grafo
{
	int TotalVertices;
	struct ListaDeVizinhos** ListaAdj; //Será um vetor do tamanho do numero de vértices
};

struct Grafo* CriarGrafo(int vertices);
void AdicionarAresta(struct Grafo* Grafo, int origem, int destino, int Peso);
void MostrarGrafo(struct Grafo* Grafo);
void dijkstra(struct Grafo* Grafo, int VerticeOrigem);

int main()
{
	Grafo* GrafoTeste = CriarGrafo(6);
	AdicionarAresta(GrafoTeste, 0, 1, 5);
	AdicionarAresta(GrafoTeste, 0, 2, 7);
	AdicionarAresta(GrafoTeste, 1, 3, 1);
	AdicionarAresta(GrafoTeste, 2, 3, 3);
	AdicionarAresta(GrafoTeste, 3, 4, 1);
	AdicionarAresta(GrafoTeste, 3, 5, 2);

	MostrarGrafo(GrafoTeste);

	printf("\n\n");
	dijkstra(GrafoTeste, 4);

	printf("\n\n");

	system("pause");
	return 0;
}

struct Grafo* CriarGrafo(int TotalVertices)
{
	Grafo* Grafo = (struct Grafo *)malloc(sizeof(struct Grafo));
	Grafo->TotalVertices = TotalVertices;
	Grafo->ListaAdj = (struct ListaDeVizinhos **)malloc(TotalVertices * sizeof(struct ListaDeVizinhos*));

	for (int i = 0; i < TotalVertices; i++)
		Grafo->ListaAdj[i] = NULL;

	return Grafo;
}

void AdicionarAresta(struct Grafo* Grafo, int origem, int destino, int Peso)
{ //INSERÇÃO NO INICIO DA LISTA 
  // Adiciona uma aresta da origem para o  destino
	struct ListaDeVizinhos* NovoElemento = (struct ListaDeVizinhos *)malloc(sizeof(struct ListaDeVizinhos));
	NovoElemento->vertice = destino;
	NovoElemento->peso = Peso;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[origem];
	Grafo->ListaAdj[origem] = NovoElemento;

	// Adiciona uma aresta do destino para a origem
	NovoElemento = (struct ListaDeVizinhos *)malloc(sizeof(struct ListaDeVizinhos));
	NovoElemento->vertice = origem;
	NovoElemento->peso = Peso;
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



void dijkstra(struct Grafo* Grafo, int VerticeOrigem)
{
	int Distancia[MAX], Predecessor[MAX], Visitados[MAX];
	int TotalVisitados, minDistancia, ProxVertice, i, j;

	for (i = 0; i < Grafo->TotalVertices; i++)
	{
		Distancia[i] = INFINITY;
		Predecessor[i] = VerticeOrigem; 
		Visitados[i] = 0;
	}
	Distancia[VerticeOrigem] = 0;
	TotalVisitados = 0;

	struct ListaDeVizinhos* ElementoVarredura = Grafo->ListaAdj[VerticeOrigem];
	while (TotalVisitados < (Grafo->TotalVertices - 1))
	{
		minDistancia = INFINITY;
		// ProxVertice é o nó com a menor distância
		for (i = 0; i < Grafo->TotalVertices; i++)
		{
			if ((Distancia[i] < minDistancia) && (Visitados[i] == 0))
			{
				minDistancia = Distancia[i];
				ProxVertice = i;
			}
		}
		//Verifica se existe um melhor caminho pelo ProxVertice
		Visitados[ProxVertice] = 1;
		ElementoVarredura = Grafo->ListaAdj[ProxVertice];
		while (ElementoVarredura != NULL)
		{
			if (Visitados[ElementoVarredura->vertice] == 0)
			{
				if (minDistancia + ElementoVarredura->peso < Distancia[ElementoVarredura->vertice])
				{
					Distancia[ElementoVarredura->vertice] = minDistancia + ElementoVarredura->peso;
					Predecessor[ElementoVarredura->vertice] = ProxVertice;
				}
			}
			ElementoVarredura = ElementoVarredura->prox;
		}
		TotalVisitados++;
	}

	//print do caminho e  Distancia de cada nó
	for (i = 0; i < Grafo->TotalVertices; i++)
	{
		if (i != VerticeOrigem)
		{
			printf("\n Distancia para V%d = %d ", i, Distancia[i]);
			printf("\tCaminho = %d ", i);
			j = i;
			do
			{
				j = Predecessor[j];
				printf("<- %d ", j);
			} while (j != VerticeOrigem);
		}
	}

}



