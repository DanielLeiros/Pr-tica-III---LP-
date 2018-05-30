#include <iostream>
#include "sapo.hpp"
#include <ctime>
#include <cstdlib>
using namespace std;

void zerarTempo(){
  srand(time(NULL));
}

string Sapo::getNome(){
  return nome;
}

bool Sapo::getemProva(){
  if(emProva == 0){
    return true;
  }else{
    return false;
  }
}

void Sapo::setemProva(){
  emProva = 1;
}

void Sapo::pular(){
  if(getemProva()){
  	distancia += rand() % 6 +1;
  	pulos++;
  }
}

void Sapo::getEstatisticas(){
	cout << "Nome: " << nome << " Identificador: " << identificador;
	cout << " Pulos: " << pulos << "Pulos totais: " << pulosTotais <<" Distancia: " << distancia << " Distancia total: " <<  distanciaTotal << " Vitorias" << vitorias << " Provas puladas: " << provas << endl;

}

bool Sapo::chegada(){
	if(distancia >= distanciaCorrida){
		distanciaTotal += distancia;
    pulosTotais += pulos;
		return true;
	}else{
		return false;
	}
}

void Sapo::vencedor(){
	vitorias++;
}

string Sapo::getNome(){
  return nome;
}
  string Sapo::getId(){
    return identificador;
}

int Sapo::getPulosTotais(){
  return pulosTotais;
}

int Sapo::getDistanciaTotal(){
    return distanciaTotal;
}

int Sapo::getVit(){
  return vitorias;
}

int getProvas(){
    return provas;
}
