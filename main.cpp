#include<iostream>
#include<fstream>
#include<ccstdlib>
#include "circuito.hpp"
using namespace std;

 int main(int argc, char const *argv[]){
 
 	int pulosTotais, int distanciaTotal, int vitorias, int provas;
 	string nome, string identificador;
 	int option;
 	Circuito C;
 	do{
 	cout << "===== Corrida de Sapos =====" << endl;
 	cout << "1 - Iniciar corrida" << endl;
 	cout << "2 - Inserir sapo manualmente" << endl;
 	cout << "3 - Selecionar pista" << endl;
 	cout << "4 - Estatisticas dos participantes" << endl;
 	cout << "5 - Para sair" << endl;
 	cin >> option; 
 	fstream file("corridaSapos.txt", ios::in | ios::out);
 	if(file.is_open()){ 
	 	while(!file.eof()){
	 		file >> nome >> identificador >> pulosTotais >> distanciaTotal >> vitorias >> provas;
	 		C.inserirSapo(pulosTotais, distanciaTotal, vitorias, provas, nome, identificador);
	 	}
	 }else{
	 	cout << "Nenhum competidor estava na ficha, insira manualmente!" << endl;
	 }


 	C.corrida();
 	file.close();
 	system("clear");
	}while(option != 5);
	return 0;
}