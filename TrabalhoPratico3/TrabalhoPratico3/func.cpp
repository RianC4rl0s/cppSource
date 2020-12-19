#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <fstream>
#include "dinaVetor.h"
#include "func.h"
using namespace std;


//ponteiro para registro de produtos global
produto* vetorPrinc;
//numero de itens alocados dentro do espaço apontado pelo ponteiro
int full = 0;
//espaço total alocado dentro do espaço alocado pelo ponteiro
int tam = 0;

//Teste de existencia de arquivo de estoqu
void testArq()
{
	//criando variavel ifstream
	ifstream fin;
	//tentando abrir aquivo, caso n exista n cria
	fin.open("estoque.bin", ios_base::in | ios_base::binary);
	//caso ele exista 
	if (fin.is_open())
	{

		//int i = 0;
		
		//le o tamanho dentro do arquivo
		fin.read((char*)&tam, sizeof(int));
		full = tam;
		vetorPrinc = new produto[tam];
		//pega todos os produtos dentro do arquivo e adiciona ao vetor
		for (int j = 0; j < tam; j++)
		{
			fin.read((char*)&vetorPrinc[j], sizeof(produto));
		}

	}
}

//Função menu
void menu()
{
	
	char opc = 0;
	//numero numero de vezes q o vetor expandiu nessa execução
	int numeros_exp = 0;
	while ( opc != ('s'))
	{
		//texto de alternativas do menu
		texto();

		cin >> opc;
		//coloca a entrada em minusculo
		opc = tolower(opc);
		//verifica qual função via ser executada
		switch (opc)
		{
		case ('p'):

			//funçao pedir
			//Não esta funcionando
			pedir();
			break;

		case ('a'):
			//funcão adicionar
			numeros_exp = adicionar(numeros_exp);
			break;
		case ('e'):
			//funçao excluir
			excluir();
			break;
		case ('l'):
			//função listar
			listar();
			break;
		case ('s'):
			//função sair
			sair();
			break;
		default:
			//caso a alternativa for invalida
			system("cls");
			cout << "\a" << endl;
			cout << "Opção invalida" << endl;
			break;
		}
		cout << endl;
	}

}
//função adicionar
int adicionar(int n)
{

	system("cls");
	cout << "Adicionar" << endl;
	cout << "=========" << endl;
	//produto novo
	produto produtoADD;
	cout << "Produto: ";

	cin >> produtoADD.nomeProduto;
	//formata a a palavra para o padrão
	formatar(produtoADD.nomeProduto);
	cout << "Preço: ";
	cin >> produtoADD.preco;
	cout << "Quantidade: ";
	cin >> produtoADD.quantidade;

	//verifica se o vetor ja está cheio
	if (tam == full)
	{
		//expande o vetor
		n = vetExp(n);
	}


	//verifica dentro do vetor se não existe nenhum produto com a mesma palavra
	bool a = 1;
	bool teste = 0;
	++full;
	for (int i = 0; i < full; i++)
	{
		//testa se o produto ja esta no vetor
		teste = strcmp(vetorPrinc[i].nomeProduto, produtoADD.nomeProduto);
		//se sim apenas altera o valor de sua quantidade e preço
		if (!teste)
		{

			vetorPrinc[i].preco = produtoADD.preco;
			vetorPrinc[i].quantidade = vetorPrinc[i].quantidade + produtoADD.quantidade;
			--full;
			a = 0;
		}
	}
	//se não ele cria um novo produto dentro do vetor
	if (a)
	{
		vetorPrinc[full - 1] = produtoADD;
	}
	//retorna o valor de expançoes
	return n;

}
//excluir
void excluir()
{
	system("cls");

	cout << "Excluir" << endl;
	cout << "=======" << endl;

	int i = 0;
	//lista o produtos
	while (i < full)
	{
		cout << i + 1 << ")" << vetorPrinc[i].nomeProduto << endl;
		i++;
	}
	cout << endl;
	//pergunta qual deseja excluir
	cout << "Digite o indice do produto a ser deletado: ";
	int codigo;
	cin >> codigo;
	codigo = codigo - 1;
	
	cout << "Deseja excluir \"" << vetorPrinc[codigo].nomeProduto << "\"(S/N)";
	char alte;
	cin >> alte;
	alte = toupper(alte);
	// se sim ele excui o item na posição e peg ao ultimo, adicionando no lugar do excluio
	if (alte == 'S')
	{
		strcpy(vetorPrinc[codigo].nomeProduto, vetorPrinc[i-1].nomeProduto);
		vetorPrinc[codigo].preco = vetorPrinc[i-1].preco;
		vetorPrinc[codigo].quantidade= vetorPrinc[i-1].quantidade;
		full = full - 1;
	}
}
//Listar
void listar()
{
	system("cls");
	cout << endl << " Listagem" << endl;
	cout << "--------" << endl << endl;

	//Percorre o vetor e lista ele
	for (int i = 0; i < full; i++)
	{
		cout << vetorPrinc[i].nomeProduto << " - " << " R$" << vetorPrinc[i].preco << " - " << vetorPrinc[i].quantidade << "KG" << endl;
	}


}
//Sair
void sair()
{

	ofstream fout;
	//abre o arquivo esqtoque
	fout.open("estoque.bin", ios_base::out | ios_base::binary);
	//escrevre por cima de tudo q tinha nele antes
	fout.write((char*)&full, sizeof(int));
	for (int i = 0; i < full; i++)
	{
		fout.write((char*)&vetorPrinc[i], sizeof(produto));

	}

	//fecha o arquivo e deletar  o vetor principal
	fout.close();
	delete[] vetorPrinc;
	
}
//Texto menu
void texto()
{

	cout << "Sistema de Controle" << endl;
	cout << "===================" << endl;
	cout << "(P)edir" << endl;
	cout << "(A)dicionar" << endl;
	cout << "(E)xcluir" << endl;
	cout << "(L)istar" << endl;
	cout << "(S)air" << endl;
	cout << "===================" << endl;
	cout << "Opção: [_]\b\b";
}
//Função pedir
//FUNÇÃO PEDIR NÃO ESTA FUNCIONANDO
void pedir()
{
	system("cls");
	cout << "Pedir" << endl;
	cout << "====" << endl;
	cout << "Arquivo: ";
	char arquivo[50];
	cin >> arquivo;
	//verifica se o arquivo existe
	ifstream fin;
	fin.open(arquivo,ios_base::in);
	//se não existir o arquivo desejado chamar o menu novamente
	if (!fin.is_open())
	{
		cout << "Não foi possivel abrir o arquivo desejado";
		menu();

	}
	//se sim
	else {
		//le o nome da empresa
		char nomeEmpresa[40];

		fin.getline(nomeEmpresa, 40);
		fin.ignore();
		char ch;
		fin.get(ch);
		//ignora os caracteeres especiais da linha
		while (ch != '\n')
		{
			fin.get(ch);
		}
		int numeroLinhas = 0;
		//ch =255;
		//conta do numero de linhas dentro do arquivo
		while (!fin.eof())
		{
			fin.get(ch);
			if(ch==' ')
			{ 
				numeroLinhas++;
			}
		}
		//fecha o arquivo
		fin.close();
		//abre novamente
		fin.open(arquivo);

		fin.getline(nomeEmpresa, 40);
		fin.ignore();
		//ignora os caraceres especiais
		while (ch != '\n')
		{
			fin.get(ch);
		}
		//cria um novo vetor dinamico do tamanho do numero de linhas
		produto* produtosPedidos = new produto[numeroLinhas];
		//Cria um vetor de booleanos para fazer as verificaçoes
		bool* saber = new bool[numeroLinhas];
		int cont = 0;
		//colocar todos os valores de saber em 1
		for (int i = 0; i < numeroLinhas; i++) {
			saber[i] = 1;
		}
		//le os itens do arquivo
		for (int i = 0; i < numeroLinhas; i++)
		{
			fin >> produtosPedidos[i].nomeProduto;
			formatar(produtosPedidos[i].nomeProduto);
			fin >> produtosPedidos[i].quantidade;
		}
		fin.close();
		//Pegar todos os itens e se saber que esta em um indice igual ao de pedido for verdadeiro percorre o vetor até achar um pedido com o mesmo nome
		for (int i = 0; i < numeroLinhas; i++)
		{
			if (saber[i]) {
				for (int j = i + 1; j < numeroLinhas; j++) {
					bool teste = !strcmp(produtosPedidos[i].nomeProduto, produtosPedidos[j].nomeProduto);
					if (teste) {
						produtosPedidos[i].quantidade += produtosPedidos[j].quantidade;
						produtosPedidos[i].preco = produtosPedidos[j].preco;
						saber[j] = false; 
						//conta o novo numero de produtos
						cont++;
					}
				}
			}
		}
		//cria um vetor com o tamanho do novo numero de produtos e deleta o antigo q era maior
		produto* pedidos = new produto[cont];
		int indice = 0;
		//copia os arquivos do vetor maior para o menor
		for (int i = 0; i < numeroLinhas; i++) {
			if (saber[i]) {
				pedidos[indice++] = produtosPedidos[i];
			}
		}
		//deleta o vetor antigo maior
		delete[] produtosPedidos;
		produtosPedidos = pedidos;

		produto* nota_fiscal = new produto[cont];
		int n = 0;

		bool testeFalha = 0;
		bool teste = 0;
		bool testeQuant;
		for (int x = 0; x < full; x++)
		{
			for (int y = 0; y < cont; y++) 
			{
				if (!strcmp(vetorPrinc[x].nomeProduto, produtosPedidos[y].nomeProduto) && vetorPrinc[x].quantidade >= produtosPedidos[y].quantidade) {
					strcpy_s(nota_fiscal[n].nomeProduto, vetorPrinc[x].nomeProduto);
					nota_fiscal[n].preco = vetorPrinc[x].preco;
					nota_fiscal[n].quantidade = produtosPedidos[y].quantidade;
				}
				else if (!strcmp(vetorPrinc[x].nomeProduto, produtosPedidos[y].nomeProduto) && vetorPrinc[x].quantidade < produtosPedidos[y].quantidade) {
					if (!testeFalha) {
						cout << "Pedido falhou! " << endl;
						testeFalha = 1;
					}
					cout << produtosPedidos[y].nomeProduto << ": solicitado = " << produtosPedidos[y].quantidade << " / em estoque = " << vetorPrinc[x].quantidade << endl;
				}
			}
		}

			
				//Se o pedido for possivel
				if(!testeFalha) {
					int v = strlen(arquivo);
					double valorTotal= 0;
					char temp[40];
					//copia o nome do arquivo e muda o tipo dele para .nfc
					strcpy(temp, arquivo);
					temp[v - 1] = 'c';
					temp[v - 2] = 'f';
					temp[v - 3] = 'n';

					//cria um arquivo de texto com sulfixo nfc
					ofstream fout;
					fout.open(temp);
					//escreve no arquivo .nfc de forma 
					fout << nomeEmpresa << endl;
					fout << "--------------------------------------" << endl;
					//percorre os vetores de pedidos e o vetor principal e lista o produto pedido a quantidade, preço e preço total 
					//percorre o vetor de pedidos
					for (int p = 0; p < cont; p++)
					{
						fout << nota_fiscal[p].nomeProduto << ": ";
						fout<< "R$" << nota_fiscal[p].preco << "= ";
						float precoPed = nota_fiscal[p].quantidade * nota_fiscal[p].preco;
						fout <<"R$" << precoPed <<endl;
						valorTotal += precoPed;
					}

					fout << "--------------------------------------" << endl;
					fout << "Compra = R$"<< valorTotal<< endl;
					//verifica se o total é maior q 1000 e se for da um desconto de 10%
					if (valorTotal > 1000)
					{
						double desconto = 0.1*valorTotal;
						fout << "Desconto = R$" << desconto << endl;
						fout << "Total = R$" << valorTotal - desconto << endl;
					}
					//fecha o arquivo
					fout.close();
					//abre o menu para novas operações
					menu();
				}
			}

		}