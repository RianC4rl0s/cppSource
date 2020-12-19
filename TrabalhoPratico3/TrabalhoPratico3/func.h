#include <iostream>

//Criando o tipo produto
struct produto {
	char nomeProduto[30];
	float preco;
	int quantidade;
};
//prototipos das funçoes 
void testArq();
void menu();
void texto();
int adicionar(int );
void listar();
void excluir();
void sair();
void pedir();