#include <iostream>
//incluindo cor.h
#include "cor.h"
using namespace std;

//Função operator de cor
istream& operator>>(istream& is, cor& c)
{
	int t;
	
	is >> t;
	//Cor c recebe valor dentro de t 
	c = (cor)t;

	
	return is;

}
