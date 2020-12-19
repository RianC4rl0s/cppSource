#include <iostream>
//definindo cor
#ifndef  colorDef_h
#define colorDef_h

using namespace std;
//Criado enum de cor
enum cor{Azul, Verde, Preto, Roxo, Branco};

//Prototipo operator de cor
istream& operator>>(istream& , cor&);

#endif //  colorDef_h