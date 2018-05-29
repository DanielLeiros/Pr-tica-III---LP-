#include <iostream>
#include "sapo.hpp"
#include <ctime>
#include <cstdlib>
using namespace std;

void zerarTempo(){
  srand(time(NULL));
}

void Sapo::pular(){
	distancia += rand() % 6 +1;
	pulos++;
	pulosTotais++;
}

void Sapo::getEstatisticas(){
	cout << "Nome: " << nome << " Identificador: " << identificador;
	cout << " Pulos: " << pulos << "Pulos totais: " << pulosTotais <<" Distancia: " << distancia << " Distancia total: " <<  distanciaTotal << " Vitorias" << vitorias << " Provas puladas: " << provas << endl; 
}

bool Sapo::chegada(){
	if(distancia >= distanciaCorrida){
		distanciaTotal += distancia;	
		return true;
	}else{
		return false;
	}
}
void Sapo::vencedor(){
	vitorias++;
}
	
