#include <iostream>
#include "circuito.hpp"
#include <vector>
using namespace std;

void Circuito::inserirSapo(int pulos, int pulosTotais, int distancia, int distanciaTotal, int vitorias, int provas, string nome, string identificador){

	S = new Sapo(pulos, pulosTotais, distancia, distanciaTotal, vitorias, provas, nome, identificador);
	puladores.push_back(S);
	
}

void Circuito::corrida(){
	int auxChegada = 0;
	string *classificacao = new string[puladores.size()]; 	
	for (std::vector<Sapo>::iterator it = puladores.begin() ; it != puladores.end(); ++it){
		*it.pular();
		if(*it.chegada && classifica
	}
		
}




	
