#include<iostream>
#include<fstream>
#include<cstdlib>
#include "circuito.hpp"
using namespace std;

 int main(int argc, char const *argv[]){
 
 	int pulosTotais;
 	int distanciaTotal;
 	int vitorias;
 	int provas;
 	string nome;
 	string identificador;
 	int option;
 	string pause;
 	Circuito C;
 	fstream file("corridaSapos.txt", ios::in | ios::out);
 	if(file.is_open()){ 
		 	while(!file.eof()){
		 		file >> nome >> identificador >> pulosTotais >> distanciaTotal >> vitorias >> provas;
		 		C.inserirSapo(pulosTotais, distanciaTotal, vitorias, provas, nome, identificador);
		 	}
		}else{
		 	cout << "Nenhum competidor estava na ficha, insira manualmente!" << endl;
		}

 	do{
	
	 	cout << "===== Corrida de Sapos =====" << endl;
	 	cout << "1 - Iniciar corrida" << endl;
	 	cout << "2 - Inserir sapo manualmente - Novo competidor" << endl;
	 	cout << "3 - Estatisticas dos participantes" << endl;
	 	cout << "4 - Para sair" << endl;
	 	cin >> option; 
	 	
	
	 	
		if(option == 1){
			C.Pista();
		 	C.corrida();
		}else if(option == 2){
			cout<< "Nome do sapo: " << endl;
			cin >> nome;
			cout << "Identificador: " << endl;
			cin >> identificador;
			C.inserirSapo(0,0,0,0,nome,identificador);
		}else if(option == 3){
			C.Estatisticas();
		}
	
	 	file.close();
	
	}while(option != 4);
	
	return 0;
}