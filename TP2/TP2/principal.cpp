#include <iostream>
//Importando particula
#include "particula.h"

using namespace std;

//Principal
int main() 
{
	//Mudando pagina de caracteres
	system("chcp 1252 > nul");
	
	//Cria��o do vetor de particula, e vetor resultado de colis�o
	particula vetorParticula[10];
	resultadosColisao passoColResultado[100] = {0};
	
	//Contador de colis�o
	int totalColid = 0;

	//La�o de cadastro de particula
	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> vetorParticula[i];
		cin.get();
	}

	//N simula��es com colis�o
	int pCol = 0;
	//N passo
	int passo;
	//Cores
	int nazul = 0 , nverde = 0 , npreto = 0 , nroxo = 0 , nbranco = 0;
	
	//La�o principal 
	for (passo = 1; pCol <100; passo++)
	{
		//Verifica colis�o
		bool teveCol = 0;
		//Indice da partiula
		int posPart = 0;
		//Declarando vetor dinamico de ponteiros de particula
		int tam = numeroDePart();
		particula** vet = new particula * [tam];

		cout << "#" << passo << ": ";
		cout << tam << " (";
		
		//La�o de opera��es com particulas
		for (int i = 0; i < tam ; i++)
		{
			//Chama particula aleatoria
			int ale = AlePart();
			//Coloca a particula aleatoria no vetor dinamico de indice i
			vet[i] = &vetorParticula[ale];
			

			//Chama fun��o deslocar particula
			vet[i]->posic = dlc(vet[i]->posic, vet[i]->padraoCoor,vet[i]->tipoCoor);
			

			//verifica se ocorre colis�o
			if (vet[i]->posic.posX >= 800 || vet[i]->posic.posX <= 0 || vet[i]->posic.posY >= 600 || vet[i]->posic.posY <= 0)
			{
				//Caso sim, Chama fun��o inverter
				vet[i]->padraoCoor = inver(vet[i]->posic, vet[i]->padraoCoor, vet[i]->tipoCoor);
				
				//Vetor resultado indice i recebe a particula colidida 
				passoColResultado[pCol].colisao[posPart] = vet[i];
				//Verifica��o de colis�o
				teveCol = 1;
				//Muda indice da particula
				posPart = posPart + 1;
				//Resultado recebe o numero de particulas colididas naquele passo
				passoColResultado[pCol].quantPart = passoColResultado[pCol].quantPart + 1;
				
				// Contador de cores
				int corPar;
				corPar = vet[i]->cor;
				//Verificador do contador
				if (corPar == Azul)
				{
					nazul = nazul + 1;
				
				}
				if(corPar == Verde)
				{ 
					nverde = nverde + 1;
				}
				if(corPar == Preto)
				{
					npreto = npreto + 1;

				}
				if(corPar == Roxo)
				{
					nroxo = nroxo + 1;
				}
				if(corPar == Branco)
				{ 
					nbranco = nbranco + 1;
				}
			}	
		
			
			cout << " " << ale << " ";
			
		}
	
		//Conta numero de particulas colididas ao todo
		totalColid = totalColid + passoColResultado[pCol].quantPart;
		
		cout << ") = ";
		//Exibe o numero de particulas colididas no passo
		cout << passoColResultado[pCol].quantPart;

		//Verifica colis�o no passo
		if (teveCol == 1) {
			cout << " (";

			//La�o para fun��o de exibi��o de sobrenome
			for (int j = 0; j < passoColResultado[pCol].quantPart; j++)
			{
				cout << " ";
				//Fun��o exibir sobrenome
				printSobrenome(passoColResultado[pCol].colisao[j]->nome);
			}
			cout << " )";
			//Atricui o numero do passo transcorrido ao resultado
			passoColResultado[pCol].quantPass = passo;
			pCol = pCol + 1;
		}
		//Verifica colis�o no passo
		
		/*if (passoColResultado[pCol].quantPart > 0)
		{
			passoColResultado[pCol].quantPass = passo;
			pCol = pCol + 1;
			

		}*/
		cout << endl;

		delete[]vet;
		
		
	}

	//Declara��o das variaveis do resultado
	float colidPass = 0, mediaPassColid = 0;

	//Calculo da media, (ultima posi��o - primeira)/ numero de posi�oes
	mediaPassColid = float(passoColResultado[99].quantPass-passoColResultado[0].quantPass)/99;

	//colis�es por passo
	colidPass = float(totalColid) / float(passo);


	//Exibi��o final
	cout << endl;
	cout << "Resultados" << endl;
	cout << "----------" << endl;
	cout << "Colis�es: " << totalColid << endl;
	cout << "Colis�es por passo: " << colidPass << endl;
	cout << "Media de passos entre colis�es: " << mediaPassColid << endl;
	cout << "Coli�es por cor";
	cout << "Azul("<< nazul << ") ";
	cout << "Verde("<< nverde << ") ";
	cout << "Preto("<< npreto << ") ";
	cout << "Roxo("<< nroxo << ") ";
	cout << "Branco("<< nbranco << ")";
	


	return 0;

	
}