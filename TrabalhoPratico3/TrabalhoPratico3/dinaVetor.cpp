#include <iostream>
#include <cctype>
#include <cmath>
#include "func.h"
#include "dinaVetor.h"
//extenadno o pronteiro principal
extern produto* vetorPrinc; 
extern int tam;
//Função para formatar palavras 
void formatar(char* c)
{
	
	int i = 0;
	//corre a palavra toda ate o \0
	while (c[i] != '\0') {
		//transforma ela em minusculo
		c[i++] = tolower(c[i]);
	}
	//primeira letra em maiusculo
	c[0] = toupper(c[0]);
	
}

//função para epandir o vetor principal
int vetExp(int num)
{
	//aloca um novo vetor do tamanho do antigo
	produto* volatil = new produto[tam];
	//copia tudo do antigo para esse vetor
	for (int i = 0; i < tam; i++)
	{
		volatil[i] = vetorPrinc[i];

	}
	//deleta o vetor principal
	delete[] vetorPrinc;


	//aumenta o valor de tamanho
	int tamN = int(tam + pow(2, num));
	//cria o vetor principal com o tamanho novo
	vetorPrinc = new produto[tamN];
	//copia tudo do vetor temporario para o novo vetor principal
	for (int i = 0; i < tam; i++)
	{

		vetorPrinc[i] = volatil[i];

	}
	//aloca tamanho
	tam = tamN;
	//deleta o vetor temporario
	delete[] volatil;
	//conta quantas vezes o vetor expandiu;
	num++;
	return num;

}