#include <iostream>
//Incluindo vetor.h e cor.h
#include "vetor.h"
#include "cor.h"
//Definindo partiucla
#ifndef particulaDef_h
#define particulaDef_h

using namespace std;

//Criando reg Particula
struct particula
{
	char nome[20];
	//RegPosica
	posicao posic;
	short cor;
	char tipoCoor;
	//RegUni�o 
	sistemaCoordenadas padraoCoor;
};
//Criando reg resultados de colis�o
struct resultadosColisao
{
	//quantidade de particulas colididas no passo
	int quantPart;
	//NUmero do passo
	int quantPass;
	//RegParticula
	particula* colisao[10];
	

};
//Prototipo do Operator
istream& operator>>(istream& , particula& );

//Prototipos das fun�oes de ramdom
int numeroDePart();

int AlePart();

//Prototico da fun��o de deslocamento
particula dlc(particula);
//Prototipo dafun�ao de exibir sobrenome
void printSobrenome(char [20]);
#endif // !particulaDef_h
