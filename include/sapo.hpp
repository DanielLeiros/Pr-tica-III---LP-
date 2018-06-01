#ifndef _SAPO_
#define _SAPO_
using namespace std;

/*@file sapo.hpp
	@brief cabeçalho para objeto Sapo
	@author Daniel Leiros
	*/

class Sapo{

protected:
	int emProva, verificado;
	int pulos, pulosTotais, distancia, distanciaTotal, vitorias, provas;
	string	nome, identificador;
public:
	Sapo(){};
	Sapo(int distanciaCorrida){
		this->distanciaCorrida = distanciaCorrida;
	};
	Sapo(int pulosTotais, int distanciaTotal, int vitorias, int provas, string nome, string identificador){
		cout<< "sapo criado"<< endl;
		this->pulos=0;
		this->pulosTotais=pulosTotais;
		this->distancia=0;
		this->distanciaTotal=distanciaTotal;
		this->vitorias=vitorias;
		this->provas=provas;
		this->nome=nome;
		this->identificador=identificador;
		this->emProva = 1;
		this->verificado = 0;
	};
	~Sapo(){};

	void pular();
	void getEstatisticas();
	bool chegada();
	void vencedor();
	string getNome();
	bool getemProva();
	void setemProva();
	string getId();
	int getPulosTotais();
	int getDistanciaTotal();
	int getVit();
	int getProvas();
	bool getVerificado();
	void setVerificado();
	void zerarTempo();
	static int distanciaCorrida;
};

#endif
