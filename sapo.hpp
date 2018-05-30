#ifndef _SAPO_
#define _SAPO_
#include "circuito.hpp"
#include <string>
using namespace std;

class Sapo{
protected:
	int emProva;
	int pulos, pulosTotais, distancia, distanciaTotal, vitorias, provas;
	string	nome, identificador;
public:
	Sapo(){};
	Sapo(int pulosTotais, int distanciaTotal, int vitorias, int provas, string nome, string identificador){
		this->pulos=0;
		this->pulosTotais=pulosTotais;
		this->distancia=0;
		this->distanciaTotal=distanciaTotal;
		this->vitorias=vitorias;
		this->provas=provas;
		this->nome=nome;
		this->identificador=identificador;
		this->emProva = 0;	
	};
	~Sapo(){};
	void pular();
	void getEstatisticas();
	bool chegada();
	void vencedor();
	string getNome();
	bool getemProva();
	string getNome();
	string getId();
	int getPulosTotais();
	int getDistanciaTotal();
	int getVit();
	int getProvas();
	static const int distanciaCorrida = 50;
};

#endif
