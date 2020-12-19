#include <iostream>
#include "func.h";
using namespace std;

//Principal
int main()
{
	//pagina de caracteres
	system("chcp 1252 > nul");
	cout << endl;
	
	
	//testa se o arquivo de estoque de produtos ja existe
	testArq();
	//chama o menu com todas as funçoes
	menu();


	return 0;
}