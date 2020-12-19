#include <iostream>
//Importando particula
#include "particula.h"

using namespace std;

//Principal
int main() 
{
	//Mudando pagina de caracteres
	system("chcp 1252 > nul");
	
	//Criação do vetor de particula, e vetor resultado de colisão
	particula vetorParticula[10];
	resultadosColisao passoColResultado[100] = {0};
	
	//Contador de colisão
	int totalColid = 0;

	//Laço de cadastro de particula
	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> vetorParticula[i];
		cin.get();
	}

	//N simulações com colisão
	int pCol = 0;
	//N passo
	int passo;
	//Cores
	int nazul = 0 , nverde = 0 , npreto = 0 , nroxo = 0 , nbranco = 0;
	
	//Laço principal 
	for (passo = 1; pCol <100; passo++)
	{
		//Verifica colisão
		bool teveCol = 0;
		//Indice da partiula
		int posPart = 0;
		//Declarando vetor dinamico de ponteiros de particula
		int tam = numeroDePart();
		particula** vet = new particula * [tam];

		cout << "#" << passo << ": ";
		cout << tam << " (";
		
		//Laço de operações com particulas
		for (int i = 0; i < tam ; i++)
		{
			//Chama particula aleatoria
			int ale = AlePart();
			//Coloca a particula aleatoria no vetor dinamico de indice i
			vet[i] = &vetorParticula[ale];
			

			//Chama função deslocar particula
			vet[i]->posic = dlc(vet[i]->posic, vet[i]->padraoCoor,vet[i]->tipoCoor);
			

			//verifica se ocorre colisão
			if (vet[i]->posic.posX >= 800 || vet[i]->posic.posX <= 0 || vet[i]->posic.posY >= 600 || vet[i]->posic.posY <= 0)
			{
				//Caso sim, Chama função inverter
				vet[i]->padraoCoor = inver(vet[i]->posic, vet[i]->padraoCoor, vet[i]->tipoCoor);
				
				//Vetor resultado indice i recebe a particula colidida 
				passoColResultado[pCol].colisao[posPart] = vet[i];
				//Verificação de colisão
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

		//Verifica colisão no passo
		if (teveCol == 1) {
			cout << " (";

			//Laço para função de exibição de sobrenome
			for (int j = 0; j < passoColResultado[pCol].quantPart; j++)
			{
				cout << " ";
				//Função exibir sobrenome
				printSobrenome(passoColResultado[pCol].colisao[j]->nome);
			}
			cout << " )";
			//Atricui o numero do passo transcorrido ao resultado
			passoColResultado[pCol].quantPass = passo;
			pCol = pCol + 1;
		}
		//Verifica colisão no passo
		
		/*if (passoColResultado[pCol].quantPart > 0)
		{
			passoColResultado[pCol].quantPass = passo;
			pCol = pCol + 1;
			

		}*/
		cout << endl;

		delete[]vet;
		
		
	}

	//Declaração das variaveis do resultado
	float colidPass = 0, mediaPassColid = 0;

	//Calculo da media, (ultima posição - primeira)/ numero de posiçoes
	mediaPassColid = float(passoColResultado[99].quantPass-passoColResultado[0].quantPass)/99;

	//colisões por passo
	colidPass = float(totalColid) / float(passo);


	//Exibição final
	cout << endl;
	cout << "Resultados" << endl;
	cout << "----------" << endl;
	cout << "Colisões: " << totalColid << endl;
	cout << "Colisões por passo: " << colidPass << endl;
	cout << "Media de passos entre colisões: " << mediaPassColid << endl;
	cout << "Coliões por cor";
	cout << "Azul("<< nazul << ") ";
	cout << "Verde("<< nverde << ") ";
	cout << "Preto("<< npreto << ") ";
	cout << "Roxo("<< nroxo << ") ";
	cout << "Branco("<< nbranco << ")";
	


	return 0;

	
}