#ifndef _CIRC_
#define _CIRC_
#include <string>
#include <vector>
#include "../include/sapo.hpp"

/*@file circuito.hpp
	@brief cabeçalho para objeto Circuito
	@author Daniel Leiros
	*/

class Circuito{
protected:
	vector<Sapo> puladores;
	int distancia;
	string pista;
public:
	Circuito(){};
	~Circuito(){};
	void inserirSapo( int pulosTotais, int distanciaTotal, int vitorias, int provas, string nome, string identificador);
	void corrida();
	void salvarCorrida();
	void zerarCorrida();
	void Estatisticas();
	void Pista();
};

#endif
