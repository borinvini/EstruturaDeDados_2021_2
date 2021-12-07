#include <stdio.h>
#include <stdlib.h>

#define TAMANHOFILA 10

int fila[TAMANHOFILA] = { 0 }; //array para conter a fila preenchido com -1 para a indicar posi��o vazia
int head = 0; //inteiro que conter� o inicio da fila
int tail = 0; //inteiro que conter� o final  da fila

//prot�tipos 
void queue(int);
int dequeue();
void listar();

int main() {

	int opcao = 1, num, c = 0;

	while (opcao == 1) {
		printf("MAIN MENU: \n");
		printf("1.Adicionar elemento.\n");
		printf("2.Remover elemento.\n");
		printf("Sua escolha: ");

		scanf_s("%d", &opcao);
		//sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {}

		switch (opcao) {
		case 1:
			printf("Digite o elemento... ");
			scanf_s("%d", &num);
			//sempre limpe o buffer do teclado.
			while ((c = getchar()) != '\n' && c != EOF) {}
			//colocando o elemento na fila
			queue(num);
			//vamos listar a fila s� para testes
			listar();
			break;
		case 2:
			printf("O valor no topo da fila: %d\n", dequeue());
			//vamos listar a fila s� para testes
			listar();
			break;
		default:
			printf("ESCOLHA INVALIDA...");
		}

		printf("Deseja fazer novas operacoes na fila (1 para sim, 2 para nao)?\n");
		scanf_s("%d", &opcao);
		//sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {}

		//vamos limpar a tela a cada opera��o
		system("cls");
	}

	system("Pause");
	return 0;
}

//fun��o queue, coloca um elemento na fila
void queue(int y) {

	if (tail > TAMANHOFILA) {
		printf("Fila Cheia");
		return;
	}
	else {
		fila[tail] = y;
		tail++;
	}

}
//fun��o dequeue, retira um elemento da fila
int dequeue() {
	int a;
	if (tail <= 0) {
		printf("FILA VAZIA");
		return 0;
	}
	else {
		a = fila[head]; 
		fila[head] = 0;
		head++;
		
		
	}
	return(a);
}

void listar() {
	printf("A fila atual:\n");
	for (int i = head; i < tail; i++) {
		printf("%d\t", fila[i]);
	}
	printf("\n");
}