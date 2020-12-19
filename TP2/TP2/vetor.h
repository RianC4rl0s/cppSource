#include <iostream>
//Incluindo biblioteca matematica
#include <cmath>  
//Definindo vetor
#ifndef vetorDef_h
#define vetorDef_h

using namespace std;
//Crinando reg poscao
struct posicao
{
	float posX;
	float posY;


};
//Criando reg polar
struct vetorPolar
{
	float angulo;
	float manetude;
};
//Criando reg Cartesiano
struct vetorCartesiano
{
	float posX;
	float posY;

};
//Criando uni�o de registros polares de cartesianos
union sistemaCoordenadas
{
	vetorCartesiano cartesiano;
	vetorPolar polar;


};
//Pr�totipos de fun��es operator vetor.cpp 
istream& operator>>(istream&, vetorCartesiano&);

istream& operator>>(istream&, vetorPolar&);

//Prototipos de fu�oes de deslocamento
posicao dlcCar(posicao, vetorCartesiano);

posicao dlcPol(posicao, vetorPolar);

posicao dlc(posicao, sistemaCoordenadas, char);

//Prototipos de fun�oesd de invers�o
vetorCartesiano invertCart(vetorCartesiano, posicao);

vetorPolar invertPolar(vetorPolar, posicao);

sistemaCoordenadas inver(posicao , sistemaCoordenadas , char );

#endif // !vetorDef_h