#include <iostream>
#include "particula.h"
#include <random>
#include <string>
using namespace std;

//Funçao operator
istream& operator>>(istream& is, particula& part)
{

	//Recebe o char 
	is.getline(part.nome, 20, ':');
	
	//recebe posição
	is >> part.posic.posX;
	

	 is >> part.posic.posY;

	 //Recebe  o tipo da coordenada

	is >> part.tipoCoor;
	//Verifica qual tipo 
	if(part.tipoCoor == 'C')
	{
		//Caso cartesiano, ele recebe um vartesiano
		is >> part.padraoCoor.cartesiano;

	}
	if (part.tipoCoor == 'P')
	{

		//Caso polar, ele recebe polar
		is >> part.padraoCoor.polar;

	}




	//Recebe a cor
	is >> part.cor;

	return is;
}//RD entre 1 e 10 para o vetor dinamico
int numeroDePart()
{
	int result;

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 10);
	result = dist(mt);

	return result;

}
//RD index da particula
int AlePart()
{

	int result;
	
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 9);
	result = dist(mt);

	return result;

}
//Exibir somente o sobrenome
void printSobrenome(char  nome[20])
{
	//Laço para verificar
	for (int x = 0; x < 20; x++ )
	{
		//Se x for igual a espaço, exibira o valor do ponteiro de x + 1, que é um vetor de caracteres
		if (nome[x] == ' ') {
			cout << &nome[x + 1];
		}
	}
	
}
