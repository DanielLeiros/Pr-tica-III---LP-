#include <iostream>
#include "sapo.hpp"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int Sapo::distanciaCorrida;

void Sapo::zerarTempo(){
  srand(time(NULL));
}

bool Sapo::getemProva(){
  if(emProva == 1){
    return true;
  }else{
    return false;
  }
}

bool Sapo::getVerificado(){
  if(verificado == 1){
    return true;
  }else{
    return false;
  }
}

void Sapo::setVerificado(){
  verificado = 1;
}

void Sapo::setemProva(){
  emProva = 0;
}

void Sapo::pular(){
  if(getemProva()){
  	distancia += rand() % 6 +1;
  	pulos++;
  }
}

void Sapo::getEstatisticas(){
	cout << "Nome: " << nome << " Identificador: " << identificador;
	cout << " Pulos: " << pulos << " Pulos totais: " << pulosTotais <<" Distancia: " << distancia << " Distancia total: " <<  distanciaTotal << " Vitorias: " << vitorias << " Provas puladas: " << provas << endl;

}

bool Sapo::chegada(){
	if(distancia >= distanciaCorrida){
    if(!getVerificado()){
  		distanciaTotal += distancia;
      pulosTotais += pulos;
      provas++;
      setemProva(); 
    }
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

int Sapo::getProvas(){
    return provas;
}
