#include<random>
#include"cripto.h"
using namespace std;

//Função para gerar valores aleatórios
int Aleatorio()
{
	int ale;
	unsigned int valor = 0;
	
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> distribution(0, 31);

	ale = distribution(mt);


	return ale;
	
}
//Função ligar bit
unsigned int LigarBit(int bitEscolhido, unsigned int armazenamento)
{
	//bit a ser ligado
	int bit;
	bit = bitEscolhido;
	int mascara = 1 << bit;

	//Armazenamento do valor
	int estado = armazenamento;
	estado = estado | mascara;


	return estado;
}
//Desligar bit
unsigned int DesligarBit(int bitEscolhido, unsigned int armazenamento)
{
	//bit  a ser desligado
	int bit;
	bit = bitEscolhido;
	
	int mascara = ~(1 << bit);
	//Armazenamento  do valor
	int estado = armazenamento;
	estado = estado & mascara;


	return estado;

}

//Função testar bit
unsigned int TestarBit(int bitEscolhido, unsigned int armazenamento)
{
	//bit a ser testado
	int bit;
	bit = bitEscolhido;
	unsigned int mascara = 1 << bit;

	//armazenamento do valor
	unsigned int estado = armazenamento;
	
	//Caso o bit estaja ligado
	if (estado & mascara)
	{
		unsigned int resposta;
		//Chamando função deligar bit
		resposta = DesligarBit(bit, armazenamento);
		return resposta;
	}
	//Caso o bit esteja desligado
	else
	{

		unsigned int resposta;
		//Chamando função ligar bit
		resposta = LigarBit(bit, armazenamento);

		return resposta;
	}

}

//Função codificar
unsigned long long Codificar(unsigned int codificar)
 {
	 unsigned long long valCdf = 0;
	 
	 //Armazem recebe valor a ser codificado
	 unsigned int armazem = codificar;

	 //Digitos aleatórios para os bits
	 int v1, v2, v3, v4, v5, v6;

	 //Chamando função aleatória
	 v1 = Aleatorio();
	 v2 = Aleatorio();
	 v3 = Aleatorio();
	 v4 = Aleatorio();
	 v5 = Aleatorio();
	 v6 = Aleatorio();

	 //Encapsular numero ddos bits (chave de decodificação e codificação)
	 unsigned int encapsularValores = 0;
	
	 //Encapsulando valores
	 encapsularValores = encapsularValores | (v1 << 25);
	 encapsularValores = encapsularValores | (v2 << 20);
	 encapsularValores = encapsularValores | (v3 << 15);
	 encapsularValores = encapsularValores | (v4 << 10);
	 encapsularValores = encapsularValores | (v5 << 5);
	 encapsularValores = encapsularValores | (v6 << 0);
	
	 //Criptografando armazem
	 armazem = TestarBit(v1, armazem);
	 armazem = TestarBit(v2, armazem);
	 armazem = TestarBit(v3, armazem);
	 armazem = TestarBit(v4, armazem);
	 armazem = TestarBit(v5, armazem);
	 armazem = TestarBit(v6, armazem);

	 //valCdf recebe armazem 32 bits para esquerda
	 valCdf = valCdf | ((unsigned long long)armazem << 32);
	 //valCdf receve encapsular valores 2 bits para esquerda
	 valCdf = valCdf | ((unsigned long long)encapsularValores << 2);
	 

	 return valCdf;
 }


//Separar primeiro valor
unsigned int SepararPrimeiro(unsigned int valor)
 {


	unsigned int resultado = 0;
	unsigned char armazem = 0 ;

	armazem = valor >> 25;
	
	armazem = armazem << 3;
	armazem = armazem >> 3;

	resultado = armazem;

	return resultado;
 }
//Separar segundo valor
unsigned int SepararSegundo(unsigned int valor)
 {

	
	unsigned int resultado = 0;
	unsigned char armazem = 0;

	armazem = valor >> 20;

	armazem = armazem << 3;
	armazem = armazem >> 3;

	resultado = armazem;

	return resultado;
 }
//Separar terceiro valor
unsigned int SepararTerceiro(unsigned int valor)
 {

	unsigned int resultado = 0;
	unsigned char armazem = 0;

	armazem = valor >> 15;

	armazem = armazem << 3;
	armazem = armazem >> 3;

	resultado = armazem;
	return resultado;

}
//Separar o quarto valor
unsigned int SepararQuarto(unsigned int valor)
 {

	unsigned int resultado = 0;
	unsigned char armazem = 0;

	armazem = valor >> 10;

	armazem = armazem << 3;
	armazem = armazem >> 3;

	resultado = armazem;
	return resultado;
 }
//Separar o quinto valor
unsigned int SepararQuinto(unsigned int valor)
 {

	unsigned int resultado = 0;
	unsigned char armazem = 0;

	armazem = valor >> 5;

	armazem = armazem << 3;
	armazem = armazem >> 3;

	resultado = armazem;
	return resultado;

 }

//Separa o sexto valor
unsigned int SepararSexto(unsigned int valor)
 {


	unsigned int resultado = 0;
	unsigned char armazem = 0;

	armazem = valor >> 0;

	armazem = armazem << 3;
	armazem = armazem >> 3;

	resultado = armazem;
	return resultado;
 }

//Função decodificar
unsigned int Decodificardor(unsigned long long valorCodificado)
{
	 unsigned int valDcf, valorParaSeparar;
	 unsigned int  valor1, valor2, valor3, valor4, valor5, valor6;
	 unsigned long long valCdf = valorCodificado;
	 
	 
	 valCdf = valCdf >> 2;
	 //valCdfé passado para inteiro deixando somente os 32 ultimos bits
	 valorParaSeparar = valCdf;
	 
	 //Chamando fuções para descobrir os valores das chaves
	 valor1 = SepararPrimeiro(valorParaSeparar);
	 valor2 = SepararSegundo(valorParaSeparar);
	 valor3 = SepararTerceiro(valorParaSeparar);
	 valor4 = SepararQuarto(valorParaSeparar);
	 valor5 = SepararQuinto(valorParaSeparar);
	 valor6 = SepararSexto(valorParaSeparar);

	 //vlDcf recebe valor codificado >> 32
	 valDcf = valorCodificado >> 32;

	 //Chamndo funções que ligam e desligam os bits
	 valDcf = TestarBit( valor1, valDcf);
	 valDcf = TestarBit( valor2, valDcf);
	 valDcf = TestarBit( valor3, valDcf);
	 valDcf = TestarBit( valor4, valDcf);
	 valDcf = TestarBit( valor5, valDcf);
	 valDcf = TestarBit( valor6, valDcf);

	 return valDcf;

}