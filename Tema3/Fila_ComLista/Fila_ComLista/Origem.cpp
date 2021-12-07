#include <stdio.h>
#include <stdlib.h>

struct alunos

{

	char nome[15], email[15];

	int ru[15];
	alunos *prox, *p;

};

alunos *aux, *head;

void inserirDados()

{

	int x;

	alunos *insercao = (struct alunos *)malloc(sizeof(struct alunos));

	printf("\nDigite o nome do aluno ");

	fgets(insercao->nome, 39, stdin);

	printf("Digite o RU do aluno. ");

	scanf_s("%d", insercao->ru);

	printf("Digite o email do aluno ");

	fgets(insercao->email, 39, stdin);

	while ((x = getchar()) != '\n' && x != EOF) {};	// Limpar buffer do teclado

	insercao->prox = NULL;

	if (head == NULL)	//A Fila esta vazia e iremos inserir o primeiro elemento

	{
		head = insercao;

	}

	else

	{
		insercao->prox = head;
		head = insercao;

	}

}

void listarplaylist()

{

	aux = head;

	if (head == NULL)

	{

		printf("\nA playlist esta vazia!");

	}

	else

	{

		while (aux != NULL)

		{

			printf("Nome: %s", aux->nome);

			printf("RU: %d", aux->ru);

			printf("email: %s\n\n", aux->email);

			aux = aux->prox;

		}

	}

	printf("\n\n");

}

void buscar(int buscado)
{
	int achou = 0;
	alunos *insercao;
	insercao = (struct alunos *)malloc(sizeof(struct alunos));
	insercao = head;
	while ((insercao != NULL) && (*(insercao->ru) != buscado)) {    // o erro está nessa linha nos sinais de !=
		insercao = insercao->prox;
		if (*(insercao->ru) == buscado) {    //e nessa no sinal de ==
			printf("Nome: %s", insercao->nome);
			printf("RU: %d", insercao->ru);
			printf("Email: %s", insercao->email);
			achou = 1;
		}
	}
	if (achou == 0) {
		printf("Valor nao encontrado");
	}

}


int main()

{
	int opcao, x;

	do

	{
		printf("1-Inserir dados\n");

		printf("2-Buscar aluno\n");

		printf("Digite sua escolha: ");

		scanf_s("%d", &opcao);

		while ((x = getchar()) != '\n' && x != EOF) {}	// Limpar buffer

		switch (opcao)

		{

		case 1:
			inserirDados();

			printf("\nDados inseridos com sucesso.\n\n");

			system("pause");

			break;

		case 2:
			int buscado;
			buscado = 0;
			printf("Digite o RU do aluno a ser buscado");
			scanf_s("%d", buscado);

			buscar(buscado);
			return 0;

		}

		system("cls");

	}

	while (opcao != 3);

	return 0;

}