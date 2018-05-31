#include <iostream>
#include "circuito.hpp"
#include "sapo.hpp"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Circuito::inserirSapo(int pulosTotais, int distanciaTotal, int vitorias, int provas, string nome, string identificador){

	Sapo S(pulosTotais, distanciaTotal, vitorias, provas, nome, identificador);
	puladores.push_back(S);

}

void Circuito::zerarCorrida(){
	puladores.clear();
}

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


void Circuito::corrida(){
	
	int contadorOrdem = 0;
	int *ordem = new int[puladores.size()];
	vector<Sapo> classificacao;
	do{
		for (int i = 0; i < puladores.size(); i++){
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
	
	puladores[ordem[0]].vencedor();
	classificacao[0].vencedor();
	
	cout << "E a tabela de classificação da corrida foi: " << endl;
	for (int i = 0; i < classificacao.size(); i++){
		cout << i+1 << " - ";
		classificacao[i].getEstatisticas();
	}
	classificacao.clear();
	salvarCorrida();
}

void Circuito::salvarCorrida(){
	ofstream file("corridaSapos.txt");
	if(file.is_open()){
		for (int i = 0; i < puladores.size(); i++){
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

void Circuito::Estatisticas(){
	for (int i = 0; i < puladores.size(); ++i){
		cout << i+1 << " - ";
		puladores[i].getEstatisticas();
	}
}