/*
* Este é um código exemplo de trabalho com BST, demonstrando apenas inserção e busca.
* Você deve modificar este código de tal forma a incluir pelo menos dois outros
* campos (nome e cpf) e que o usuário possa digitar os dados (nome e cpf)
* e fazer busca por nome recebendo o cpf e por cpf recebendo o nome.
*/

#include<stdlib.h>
#include<stdio.h>

//definindo o elemento da árvore
struct node {
	int data;
	struct node * right, *left;
};
typedef struct node node;

//prototipos
void inserir(node **, int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void Apagar(node *);
node* buscar(node **, int);

int main() {
	node *root;
	node *tmp;
	//int i;

	root = NULL;
	/* Inserindo nós na árvore */
	inserir(&root, 9);
	inserir(&root, 4);
	inserir(&root, 15);
	inserir(&root, 6);
	inserir(&root, 12);
	inserir(&root, 17);
	inserir(&root, 2);

	/* Imprimindo os nós da árvor */
	printf("Pre Order\n");
	preorder(root);

	printf("In Order\n");
	inorder(root);

	printf("Post Order\n");
	postorder(root);

	/* Search node into tree */
	tmp = buscar(&root, 4);
	if (tmp) {
		printf("Buscar valor na árvore=%d\n", tmp->data);
	}
	else {
		printf("Nenhum dado encontrado.\n");
	}

	/* Apagando a árvore*/
	Apagar(root);
	system("Pause");
	return 0;
}

/*
* Esta função determina a posição do nó onde o valor será inserido.
* 1. verifica se a árvore está vazia. Se sim, insere o valor no nó raiz (root);
* 2. verifica se o valor a ser inserido é menor que o valor armazenado na raiz
* 2.a se sim, chama a função inserir de forma recursiva enquanto existe um valor não null
* 2.b quando a função encontra o valor mais a esquerda (um null) o nó é inserido nesta posição
*	3. verifica se o o valor do nó é maior que o valor armazenado na raiz e repete o mesmo procedimento
* desta vez indo para a direita.
*/
void inserir(node ** tree, int val) {
	node *temp = NULL;
	if (!(*tree)) {
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}
	if (val < (*tree)->data) {
		inserir(&(*tree)->left, val);
	}
	else if (val >(*tree)->data) {
		inserir(&(*tree)->right, val);
	}
}

/*
* Esta função percore a árvore em busca de um valor se o valor
* o nó encontrado será devolvido, caso contrário devolve NULL.
* 1. verifica se a árvore está vazia, se sim, devolve Null
* 2. verifica se o valor é igual ao valor armazenado na raiz, se sim devolve este nó.
* 3. verifica se o valor é menor que o valor da raíz se sim, chama buscar recursivamente a partir do nó a esquerda.
* 4. verifica se o valor é maior e repete o processo pela direita.
*/

node* buscar(node ** tree, int val) {
	if (!(*tree)) {
		return NULL;
	}

	if (val < (*tree)->data) {
		buscar(&((*tree)->left), val);
	}
	else if (val >(*tree)->data) {
		buscar(&((*tree)->right), val);
	}
	else if (val == (*tree)->data) {
		return *tree;
	}
}

/*
* apaga a árvore
*/
void Apagar(node * tree) {
	if (tree) {
		Apagar(tree->left);
		Apagar(tree->right);
		free(tree);
	}
}

/*
*	funções só para verificar o que está acontecendo
Preorder root, left e right.
inorder left, root e right.
Postorder left, right e root.
*/

void preorder(node * tree) {
	if (tree) {
		printf("%d\n", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}

}

void inorder(node * tree) {
	if (tree) {
		inorder(tree->left);
		printf("%d\n", tree->data);
		inorder(tree->right);
	}
}

void postorder(node * tree) {
	if (tree) {
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\n", tree->data);
	}
}