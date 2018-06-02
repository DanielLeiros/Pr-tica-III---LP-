#include <iostream>
#include "../include/circuito.hpp"
#include "../include/sapo.hpp"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*@file circuito.cpp
	@brief Arquivo contém as funções para funcionamento da corrida
	@author Daniel Leiros
	*/

/*@brief função para inserir sapo na corrida
	@details tanto serve para dados do arquivo quanto para inserção manual de sapo*/
void Circuito::inserirSapo(int pulosTotais, int distanciaTotal, int vitorias, int provas, string nome, string identificador){

	Sapo S(pulosTotais, distanciaTotal, vitorias, provas, nome, identificador);
	puladores.push_back(S);

}
/*@brief zerar o vector de Sapos*/
void Circuito::zerarCorrida(){
	puladores.clear();
}

/*@brief permite  seleção da pista para a corrida
	@details Ao realizar a leitura a partir do arquivo
	essa função permite que o usuário escoha a pista ou
	crie uma nova, que posteriormente também será inseri-
	da no arquivo pistas.txt*/
void Circuito::Pista(){
	int option;
	int passagemDeTamanho;
	int auxTamanhoPista;
	int auxIndice;
	string auxInfoPista;
	vector<string> infoPistas;
	vector<int> tamanhoPista;

	ifstream pistaFile("../include/pistas.txt");

	if(pistaFile.is_open()){
		while(!pistaFile.eof()){
			pistaFile >> auxInfoPista;
			pistaFile >> auxTamanhoPista;
			infoPistas.push_back(auxInfoPista);
			tamanhoPista.push_back(auxTamanhoPista);
		}
	}
	pistaFile.close();
	do{
		cout << endl;
		cout << "== Pistas: "<< endl;

		for(unsigned int i=0; i < infoPistas.size(); i++){
			auxIndice = i+1;
			cout << auxIndice << " - " << infoPistas[i] << ": " << tamanhoPista[i] << "Metros"<< endl;

		}

		cout << auxIndice+1 << " - " << "Para criar sua pista" << endl;
		cout << "Digite a opção desejada: ";
		cin >> option;
		if(option-1 == auxIndice){
				cout << "Digite as informações da nova pista separadas por " << "_" << "(underline): " << endl;
				cout<< "Descrição da pista: ";
				cin.ignore();
				getline(cin, auxInfoPista);
				cout << "Tamanho da pista: ";
				cin >> auxTamanhoPista;
				//Inserindo no vector que mais tarde será printado no txt
				infoPistas.push_back(auxInfoPista);
				tamanhoPista.push_back(auxTamanhoPista);
				passagemDeTamanho = auxTamanhoPista;

		}else if(option-1 > auxIndice){
			cout << "Não possui pista com esse indice, tente novamente" << endl;
			return;
		}else{
			cout << "Você escolheu: " << infoPistas[option-1] << endl;
			passagemDeTamanho = tamanhoPista[option-1];
			cout << endl;
		}

	}while(option > auxIndice+1 || option < 1);

	Sapo Pista(passagemDeTamanho);
	Pista.zerarTempo();
	ofstream printPistas("../include/pistas.txt");
	for(unsigned int i=0; i < infoPistas.size(); i++){
		if(i == infoPistas.size()-1){
			printPistas << infoPistas[i] << endl;
			printPistas << tamanhoPista[i];
		}else{
			printPistas << infoPistas[i] << endl;
			printPistas << tamanhoPista[i] << endl;
		}
	}
	printPistas.close();
}

/*@brief realiza a corrida
	@details essa função chama outras funções a partir do vetor de sapos,
	para que eles realizem a corrida e também faz chamada de comparações
	para definição do ranking, além de exibir tbm a classificação pós-cor_
	rida.*/
void Circuito::corrida(){
	//Antes das chamadas verifica se o sapo ainda está em prova ou se já passou a chegada;
	int contadorOrdem = 0;
	int *ordem = new int[puladores.size()];
	vector<Sapo> classificacao;
	do{
		for (unsigned int i = 0; i < puladores.size(); i++){
			if(puladores[i].getemProva()){
				puladores[i].pular();
			}
			if(puladores[i].chegada()){
				if(!puladores[i].getVerificado()){
					ordem[contadorOrdem] = i;
					contadorOrdem++;
					classificacao.push_back(puladores[i]);
					puladores[i].setVerificado();
				}
			}
		}
	}while(classificacao.size() < puladores.size());
	//permite salvar o sapo que ganhou, chamando a função vencedor e atribuido para o arquivo;
	puladores[ordem[0]].vencedor();
	classificacao[0].vencedor();

	cout << "E a tabela de classificação da corrida foi: " << endl;
	for (unsigned int i = 0; i < classificacao.size(); i++){
		cout << i+1 << " - ";
		classificacao[i].getEstatisticas();
	}
	classificacao.clear();
	salvarCorrida();
}

/*@brief salva os novos dados dos participantes no arquivo txt(mesmo que foi lido)*/
void Circuito::salvarCorrida(){
	ofstream file("../include/corridaSapos.txt");
	if(file.is_open()){
		for (unsigned int i = 0; i < puladores.size(); i++){
			if(i != puladores.size()-1){
				file << puladores[i].getNome() <<" " << puladores[i].getId() << " "<< puladores[i].getPulosTotais() <<" " << puladores[i].getDistanciaTotal() << " " << puladores[i].getVit() << " " << puladores[i].getProvas() << endl;
			}else{
				file << puladores[i].getNome() <<" " << puladores[i].getId() << " "<< puladores[i].getPulosTotais() <<" " << puladores[i].getDistanciaTotal() << " " << puladores[i].getVit() << " " << puladores[i].getProvas();
			}
		}
	}else{
		cerr << "A corrida não foi salva corretamente :(" << endl;
	}
	file.close();
}
/*@brief gera a tabela de estatisticas gerais dos sapos*/
void Circuito::Estatisticas(){
	for (unsigned int i = 0; i < puladores.size(); ++i){
		cout << i+1 << " - ";
		puladores[i].getEstatisticas();
	}
}
