#ifndef _SAPO_
#define _SAPO_
#include "circuito.hpp"
#include <string>
using namespace std;

class Sapo : public Circuito{
protected:
	int pulos, pulosTotais distancia, distanciaTotal, vitorias, provas, provas vencidas; 
	string	nome, identificador;
public:
	Sapo(){};
	~Sapo(){};
	void getEstatisticas();
	void chegada();
	static int distanciaCorrida;
};