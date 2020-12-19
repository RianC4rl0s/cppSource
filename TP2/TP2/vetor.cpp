//Incluindo vetor.h
#include "vetor.h"

#include <iostream>

//definindo pi como constante
const float pi = 3.14159f;
using namespace std;

//Operadto de vetor cartesiano
istream& operator>>(istream& is, vetorCartesiano& t )
{
	// valor de is, atribuido a t
	is >> t.posX;
	is >> t.posY;

	return is;
}
//Operator de vetor polar
istream& operator>>(istream& is, vetorPolar& t)
{
	//Valor de is atribuido a t
	is >> t.angulo;
	is >> t.manetude;

	return is;
}
//Função de deslocamento cartesiano
posicao dlcCar(posicao p, vetorCartesiano v)
{

	posicao resultado;
	//posição recebe ela atribuida ao vetor de deslocamento, no caso de y, é decrescida
	p.posX = p.posX + v.posX;
	p.posY = p.posY - v.posY;


	resultado = p;
	return resultado;
}
//Função de deslocamento polar
posicao dlcPol(posicao p, vetorPolar v)
{
	posicao resultado;
	float x,y;
	//Transfomando a magnetude e o angulo em numeros reais com função sin e cos do cmath
	x = (v.manetude * cos((v.angulo)*pi/180));
	y = (v.manetude * sin((v.angulo)*pi/180));

	
	//Cria vetor cartesiando com as posiçoes e atribui 
	vetorCartesiano vtrDlc;
	vtrDlc.posX = x;
	vtrDlc.posY = y;
	// chama função deslocar cartesiano
	resultado = dlcCar(p, vtrDlc);

	return resultado;
	
}//Função deslocar
posicao dlc(posicao p, sistemaCoordenadas v, char tipo)
{

	posicao resultado;
	//Verifica se é do tipo C ou P
	if (tipo == 'C')
	{
		resultado = dlcCar(p, v.cartesiano);
		return resultado;
	}
	if (tipo == 'P')
	{
		resultado = dlcPol(p, v.polar);
	
		return resultado;
	}
	

}//Função inverter cartesiano
vetorCartesiano invertCart(vetorCartesiano v, posicao p)
{

	vetorCartesiano resultado;
	//Verifica se coide no x ou y
	if ((p.posX >= 800) || (p.posX <= 0))
	{
		//Inverte x
		v.posX= (v.posX) * -1;
	}

	if ((p.posY >= 600) || (p.posY <= 0))
	{
		//Inverte y
		v.posY= (v.posY) * -1;

	}
	resultado = v;
	return resultado;
}//Função Inverter Polar
vetorPolar invertPolar(vetorPolar v, posicao p)
{

	vetorPolar resultado;
	float x, y;
	//transforma em pontos cartesianos
	x = v.manetude * cos((v.angulo) * pi / 180);
	y = v.manetude * sin((v.angulo) * pi / 180);
	float novoA;
	//Verifica onde colide
	if ((p.posX >= 800.0) || (p.posX <= 0.0))
	{
		//caso colidir em x inverte x e retorna o angulo por meio do atan2
		novoA = atan2(y, -x)*180/pi;
		//Verifica se o angulo é negtivo, caso sim adiciona 360
		if (novoA < 0)
		{
			v.angulo = novoA + 360;
		}
		else
		{	
			v.angulo = novoA;
		}
	}
	//Mesmo caso do x
	if ((p.posY >= 600.0) || (p.posY <= 0.0))
	{
		novoA = atan2(-y, x) * 180 / pi;
		if (novoA < 0)
		{
			v.angulo = novoA + 360;
		}
		else
		{
			v.angulo = novoA;
		}

	}
	resultado = v;
	return resultado;
}//Função inverter 
sistemaCoordenadas inver(posicao p, sistemaCoordenadas v, char tipo)
{
	sistemaCoordenadas resultado;
	
	//verifica se é polar ou cartesiano
	if (tipo == 'C')
	{
		v.cartesiano = invertCart(v.cartesiano, p);
		resultado = v;
		return resultado;

	}
	if (tipo == 'P')
	{
		v.polar = invertPolar(v.polar, p);	
		resultado = v;
		return resultado;
	}
	
}