#include <iostream>
#include "circuito.hpp"
#include "sapo.hpp"
#include <fstream>
#include <vector>
using namespace std;

void Circuito::inserirSapo(int pulosTotais, int distanciaTotal, int vitorias, int provas, string nome, string identificador){

	Sapo S(pulosTotais, distanciaTotal, vitorias, provas, nome, identificador);
	puladores.push_back(S);

}

void Circuito::corrida(){
	//int auxChegada = 0;
	int auxRanking = 1;
	//string *classificacao = new string[puladores.size()];
	vector<Sapo> classificacao;
	do{
		for (std::vector<Sapo>::iterator it = puladores.begin() ; it != puladores.end(); ++it){
			*it.pular();
			if(*it.chegada() && *it.getemProva()){
				classificacao.push_back(*it);
			}
		}
	}while(classificacao.size() <= puladores.size());
	cout << "E a tabela de classificação da corrida foi: " << endl;
	for (std::vector<*Sapo>::iterator it = classificacao.begin() ; it != classificacao.end(); ++it){
		cout << auxRanking << " - " <<*it.getEstatisticas();
		auxRanking++;
	}

}

void Circuito::salvarCorrida(){
	ofstream file("corridaSapos.txt");
	if(file.is_open()){
		for (std::vector<Sapo>::iterator it = puladores.begin() ; it != puladores.end(); ++it){
			file << *it.getNome() <<" " << *it.getId() << " "<< *it.getPulostotais() <<" " << *it.getDistanciaTotal() << " " << *it.getVit() << " " << *it.getProvas() << endl;
		}
	}else{
		cerr << "A corrida não foi salva corretamente :(" << endl;
	}
	file.close();
}