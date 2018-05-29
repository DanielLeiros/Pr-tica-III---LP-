#ifndef _CIRC_
#define _CIRC_
#include <string>
#include <vector>
#include "sapo.hpp"

class Circuito{
protected:
	vector<*Sapo> puladores;
	int distancia;
	string pista;
public:
	Circuito(){};
	~Circuito(){};
	void inserirSapo();
	virtual void getEstatisticas();
	virtual void chegada();
}