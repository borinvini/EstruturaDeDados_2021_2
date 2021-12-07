#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct STACK
{
	int dado;
	STACK *prox;
}*top = NULL;

void push(int value);
void pop();
void display();

int main()
{
	int op, value, c;

	while (1) {
		system("cls");
		printf("\n****** MENU ******\n");
		printf("1. Empilhar/Push\n2. Desempilhar/Pop\n3. Listar\n4. Sair\n");

		printf("Escolha sua opcao: ");
		scanf_s("%d", &op);
		while ((c = getchar()) != '\n' && c != EOF) {}

		switch (op) {
		case 1:
			printf("Digite um valor para ser inserido: ");
			scanf_s("%d", &value);
			while ((c = getchar()) != '\n' && c != EOF) {}
			push(value); //empilha
			break;
		case 2:
			pop(); //desempilha
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("\nDigite outra opcao.\n");
		}
	}

	system("pause");
	return 0;

}
void push(int value)
{
	STACK *NovoElemento;
	NovoElemento = (struct STACK*)malloc(sizeof(struct STACK));
	NovoElemento->dado = value;

	if (top == NULL)
		NovoElemento->prox = NULL;
	else
		NovoElemento->prox = top;
	top = NovoElemento;
	printf("\nInserido com sucesso.\n");
}
void pop()
{
	if (top == NULL)
		printf("\nPilha vazia.\n");
	else {
		STACK *temp = top;
		printf("\nElemento Eletado: %d", temp->dado);
		top = temp->prox;
		free(temp);
	}
	printf("\n");
	system("pause");
}
void display()
{
	STACK *ElementoVarredura = top;

	if (top == NULL)
		printf("\nPilha vazia!!!\n");
	else {
		
		while (ElementoVarredura->prox != NULL) 
		{
			printf("%d\n", ElementoVarredura->dado);
			ElementoVarredura = ElementoVarredura->prox;
		}
		printf("%d\n", ElementoVarredura->dado);
	}
	system("pause");
	
}