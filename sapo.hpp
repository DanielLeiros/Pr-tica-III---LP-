#ifndef _SAPO_
#define _SAPO_
#include "circuito.hpp"
#include <string>
using namespace std;

class Sapo{
protected:
	int pulos, pulosTotais, distancia, distanciaTotal, vitorias, provas; 
	string	nome, identificador;
public:
	Sapo(){};
	Sapo(int pulos, int pulosTotais, int distancia, int distanciaTotal, int vitorias, int provas, string nome, string identificador){
		this->pulos=pulos;
		this->pulosTotais=pulosTotais;
		this->distancia=distancia;
		this->distanciaTotal=distanciaTotal;
		this->vitorias=vitorias;
		this->provas=provas;
		this->nome=nome;
		this->identificador=identificador;
	};
	~Sapo(){};
	void pular();
	void getEstatisticas();
	bool chegada();
	void vencedor();
	static int distanciaCorrida;
};
