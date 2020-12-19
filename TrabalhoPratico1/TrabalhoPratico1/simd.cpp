#include "simd.h"
//Função armazena 
int Armazena(unsigned char num1, unsigned char num2, unsigned char num3, unsigned char  num4)
{
	unsigned int armNum = 0;//variavel da memoria usada para armazenar o valor 
	unsigned int resposta;
	

	armNum = armNum | ((unsigned int) num1 << 24);//Movimentando o segundo valor para o bloco 1  da memoria, e adicionando a variavel ao armazenamento, sem alterar o primerio valor, usando o operador |(ou logico) 
	armNum = armNum | ((unsigned int) num2 << 16);//Movimentando o segundo valor para o bloco 2  da memoria, e adicionando a variavel ao armazenamento, sem alterar o primerio valor, usando o operador |(ou logico) 
	armNum = armNum | ((unsigned int) num3 <<  8);//Movimentando o segundo valor para o bloco 3  da memoria, e adicionando a variavel ao armazenamento, sem alterar o primerio valor, usando o operador |(ou logico) 
	armNum = armNum | ((unsigned int) num4 <<  0);//Movimentando o segundo valor para o bloco 4  da memoria, e adicionando a variavel ao armazenamento, sem alterar o primerio valor, usando o operador |(ou logico) 


	resposta = armNum;
	return resposta;
}
//Função para extrair o numero do primeiro bloco de memoria
int Primeiro(unsigned int armazenamento)
{
	unsigned char valor = 0;
	
	valor = armazenamento >> 24;//movimentando o valor 24 bits para direita

	return valor;
}
//Função para extrair o numero do segundo bloco de memoria
int Segundo(unsigned int armazenamento)
{
	unsigned char valor = 0;

	valor = armazenamento >> 16;//Movimenta o valor 16 bits para direita, como a variavel que recebe está em char, ele só lê os primeiros 8 bits e ignora os outros 8 restantes

	return valor;
}
//Função para extrair o numero do terceiro bloco de memoria
int Terceiro(unsigned int armazenamento)
{
	unsigned char valor = 0;

	valor = armazenamento >> 8;//Movimentando o valor 8 bits para direita, como a variavel que recebe está em char,ele só lê os primeiros 8 bits e ignora os outros 16 restantes

	return valor;
}
//Função para extrair o numero do quarto bloco de memoria
int Quarto(unsigned int armazenamento)
{
	unsigned char valor = 0;

	valor = armazenamento >> 0;//Não movimenta o valor, porém como a variavel que recebe está em char, ela só lê os primeiros 8 bits, ignora os outros 24 

	return valor;
}
//Função de soma
int Soma(unsigned int opc1Soma, unsigned int opc2Soma)
{
	//Declaração de variavel de retorno
	unsigned int armazenaSoma;

	unsigned short soma1, soma2, soma3, soma4;//Variaveis de calculo
	
	
	soma1 = Primeiro(opc1Soma) + Primeiro(opc2Soma);//Calculo da soma do 1 valor 
	soma2 = Segundo (opc1Soma) + Segundo (opc2Soma);//Calculo da soma do 2 valor 
	soma3 = Terceiro(opc1Soma) + Terceiro(opc2Soma);//Calculo da soma do 3 valor 
	soma4 = Quarto  (opc1Soma) + Quarto  (opc2Soma);//calculo da soma do 4 valor 

	//Chamada da função armazena para salvar os resultados de todas as somas em uma unica veriavel de 32 bits
	armazenaSoma = Armazena(soma1, soma2, soma3, soma4);


	return armazenaSoma;
}
//Função de multiplicação
int Mult(unsigned int opc1Mult, unsigned int opc2Mult)
{
	//Declaração da variavel de retorno
	unsigned int armazenaMult;
	
	unsigned short mult1, mult2, mult3, mult4;//Variaveis de calculo

	mult1 = Primeiro(opc1Mult) * Primeiro(opc2Mult);//Calculo da multiplicação do 1 valor
	mult2 = Segundo (opc1Mult) * Segundo (opc2Mult);//Calculo da multiplicação do 2 valor
	mult3 = Terceiro(opc1Mult) * Terceiro(opc2Mult);//Calculo da multiplicação do 3 valor
	mult4 = Quarto  (opc1Mult) * Quarto  (opc2Mult);//Calculo da multiplicação do 4 valor

	//Chamada da função armazena para salvar os resultados de todas as multiplicações em uma unica variavel de 32 bits
	armazenaMult = Armazena(mult1, mult2, mult3, mult4);
	return armazenaMult;
}