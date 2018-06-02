#include <iostream>
#include "../include/sapo.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
/*@file sapo.cpp
	@brief Contém as funções responsáveis pelos sapos
	@author Daniel Leiros
	*/

int Sapo::distanciaCorrida;

/*@brief Zerar a  semente responsável pela geração "aleatórios"*/
void Sapo::zerarTempo(){
  srand(time(NULL));
}

/*@brief verificar se o sapo ainda está em prova ou já chegou*/
bool Sapo::getemProva(){
  if(emProva == 1){
    return true;
  }else{
    return false;
  }
}

/*@brief verificar se o sapo já foi avaliado para ser inserido na classificação*/
bool Sapo::getVerificado(){
  if(verificado == 1){
    return true;
  }else{
    return false;
  }
}

/*@brief auxilia na identificação daqueles que já foram verificados ao final da
  prova*/
void Sapo::setVerificado(){
  verificado = 1;
}

void Sapo::setemProva(){
  emProva = 0;
}
/*@brief responsável por realizar movimentação dos sapos*/
void Sapo::pular(){
  if(getemProva()){
  	distancia += rand() % 6 +1;
  	pulos++;
  }
}
/*@brief gerar tabela geral sobre os competidores, não sobre corridas específicas*/
void Sapo::getEstatisticas(){
	cout << "Nome: " << nome << " Identificador: " << identificador;
	cout << " Pulos: " << pulos << " Pulos totais: " << pulosTotais <<" Distancia: " << distancia << " Distancia total: " <<  distanciaTotal << " Vitorias: " << vitorias << " Provas puladas: " << provas << endl;

}

/*@brief verificar se ele concluir os pulos para alterar os atributos de confirmação*/
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
/*@brief salvar a vitória para o sapo que ganha a prova*/
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
