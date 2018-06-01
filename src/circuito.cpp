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

/*@brief permite  seleção da pista para a corrida*/
void Circuito::Pista(){
	int option;
	int tamanhoDapista;
	cout << "== Pistas: "<< endl;
	cout << "1 - Pista de fogo -> 66 metros de distância e muito quente" << endl;
	cout << "2 - Pista na floresta -> 54 metros de um ambiente amigável" << endl;
	cout << "3 - Pista de gelo -> 49 metros de uma pista congelantemente traiçoeira" << endl;
	cout << "Nenhuma alternativa -> Pista sombria 200 metros de pura sombra" << endl;
	cin >> option;
	if(option == 1){
		tamanhoDapista = 66;
	}else if(option == 2){
		tamanhoDapista = 54;
	}else if(option == 3){
		tamanhoDapista = 40;
	}else{
		tamanhoDapista = 200;
	}
	Sapo Pista(tamanhoDapista);
	Pista.zerarTempo();
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
	ofstream file("corridaSapos.txt");
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
