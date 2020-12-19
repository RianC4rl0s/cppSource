#include<iostream>

//Incluindp biblioteca para auxiliar na exibição dos resultados
#include<iomanip>

//Incluindo simd  (Biblioteca criada para simular o processador SIMD)
#include"simd.h"

#include"cripto.h" 
using namespace std;

int main()
{

	//Declaração de variaveis de entrada
	unsigned short valor1Memoria1, valor2Memoria1, valor3Memoria1, valor4Memoria1;
	unsigned short valor1Memoria2, valor2Memoria2, valor3Memoria2, valor4Memoria2;
	
	//Declaração de variavel de retorno da memoria
	unsigned int armazenamento1, armazenamento2;
	//Declaração de variavel de retorno das funçoes aritmética
	unsigned int soma,mult;
    
	//Bloco de entrada de dados 1
	cin.ignore();
	cin >> valor1Memoria1;
	cin.ignore();
	cin >> valor2Memoria1;
	cin.ignore();
	cin >> valor3Memoria1;
	cin.ignore();
	cin >> valor4Memoria1;
	cin.ignore();
	
	cin.ignore();
	
	//Bloco de entrada de dados 2
	cin.ignore();
	cin >> valor1Memoria2;
	cin.ignore();
	cin >> valor2Memoria2;
	cin.ignore();
	cin >> valor3Memoria2;
	cin.ignore();
	cin >> valor4Memoria2;
	cin.ignore();

	cout << endl;




	//Chamando função armazena bloco 1
	armazenamento1 = Armazena(valor1Memoria1, valor2Memoria1, valor3Memoria1, valor4Memoria1);
	//Chamando função armazena bloco 2
	armazenamento2 = Armazena(valor1Memoria2, valor2Memoria2, valor3Memoria2, valor4Memoria2);


	//Exibir valor do armazenamento do bloco 1 em bits
	cout << "Operandos em 32 bits = " << armazenamento1 << endl;
	//Exibir valor do armazenamento do bloco 2 em bits
	cout << "Operandos em 32 bits = " << armazenamento2 << endl;

	cout << endl;

	//Chamando função soma dos armazenamentos
	soma = Soma(armazenamento1, armazenamento2);
	//Chamando função de multiplicação dos armazenamentos
	mult = Mult(armazenamento1, armazenamento2);


	//Exibindo  valor da soma em bits
	cout << "Soma em 32 bits      = " << soma << endl;
	//Exibindo valor da multplicação em bits
	cout << "Mult em 32 bits      = " << mult << endl;

	cout << endl;

	//Exibindo valor da soma formatado para o padrão pedido, usando biblioteca iomanip, set fill para incrementar o 0, e setw para contar a quantidade
	cout << "[" << setfill('0') << setw(3) << Primeiro(soma) << "," << setfill('0') << setw(3) << Segundo(soma) << ","; 
	cout << setfill('0') << setw(3) << Terceiro(soma) << "," << setfill('0') << setw(3) << Quarto(soma) << "]";
	cout << "    = Somas"<< endl;


	//Exibindo valor da multiplicação para o padrão pedido, usando biblioteca iomanip, set fill para incrementar o 0, e setw para contar a quantidade
	cout << "[" << setfill('0') << setw(3) << Primeiro(mult) << "," << setfill('0') << setw(3) << Segundo(mult) << ","; 
	cout << setfill('0') << setw(3) << Terceiro(mult) << "," << setfill('0') << setw(3) << Quarto(mult) << "]";
	cout << "    = Multiplicações"<< endl;
	cout << endl;

	//Chamando funções de codificar
	unsigned long long somaEncriptada = Codificar(soma);
	unsigned long long multEncriptada = Codificar(mult);

	//Exibindo valores codificados em 64 bits
	cout << "Soma cripto 64 bits  = " << somaEncriptada << endl;
	cout << "Mult cripto 64 bits  = " << multEncriptada << endl;
	cout << endl;
	


	//Calores que iram receber o 32 primeiros bits do valor criptografado em 64 bits
	unsigned int valorCodificadoSoma = somaEncriptada >> 32;
	unsigned int valorCodificadoMult = multEncriptada >> 32;
	
	//Separando os 32 bits em que os numeros da chave estão localizados
	unsigned int chaveCodSoma = somaEncriptada;
	unsigned int chaveCodMult = multEncriptada;
	chaveCodSoma = chaveCodSoma >> 2;
	chaveCodMult = chaveCodMult >> 2;
	//Chamando função decodificar
	unsigned int somaDecriptada = Decodificardor(somaEncriptada);
	unsigned int multDecriptada = Decodificardor(multEncriptada);

	//Exibindo soma codificada 32 bits
	cout << "Valor Codificado     = " << valorCodificadoSoma;
	cout << "(" << SepararPrimeiro(chaveCodSoma) << " " << SepararSegundo(chaveCodSoma) << " " << SepararTerceiro(chaveCodSoma) << " ";
	cout << SepararQuarto(chaveCodSoma) << " " << SepararQuinto(chaveCodSoma) << " " << SepararSexto(chaveCodSoma) << ")" << endl;
	
	//Exibindo soma decodificada
	cout << "Soma decodificada    = " << somaDecriptada << endl;

	cout << endl;
	
	//Exibindo mult codificada 32 bits
	cout << "Valor Codifivado     = " << valorCodificadoMult;
	cout << "(" << SepararPrimeiro(chaveCodMult) << " " << SepararSegundo(chaveCodMult) << " " << SepararTerceiro(chaveCodMult) << " ";
	cout << SepararQuarto(chaveCodMult) << " " << SepararQuinto(chaveCodMult) << " " << SepararSexto(chaveCodMult) << ")" << endl;
	
	//Exibindo mult decodificada
	cout << "Mult decodificada    = " << multDecriptada << endl;
	
	system("pause");

	return 0;
}
