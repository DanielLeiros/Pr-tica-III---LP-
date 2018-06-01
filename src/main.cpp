#include<iostream>
#include<fstream>
#include<cstdlib>
#include "../include/circuito.hpp"
using namespace std;

/*@file main.cpp
  @brief coração da aplicação de corrida de Sapos.
  @detais contém a função main, simulação de menu e respectivas chamadas de funções para gerar a corrida,
  assim como a leitura dos arquivos para extração de informações.
  @author Daniel Leiros
*/
 int main(int argc, char const *argv[]){
  /*@brief esses argumentos servem para auxiliar o recebimento e passagem dos atributos para os objetos e funções*/
 	int pulosTotais;
 	int distanciaTotal;
 	int vitorias;
 	int provas;
  int corridaTerminada = 0;
 	string nome;
 	string identificador;
 	int option;
 	string pause;
 	Circuito C;
 	fstream file("../include/corridaSapos.txt", ios::in | ios::out);

 	if(file.is_open()){
		 	while(!file.eof()){
		 		file >> nome >> identificador >> pulosTotais >> distanciaTotal >> vitorias >> provas;
		 		C.inserirSapo(pulosTotais, distanciaTotal, vitorias, provas, nome, identificador);
		 	}
		}else{
		 	cout << "Nenhum competidor estava na ficha, insira manualmente!" << endl;
		}

 	do{

    if(corridaTerminada == 0){
      cout << "===== Corrida de Sapos =====" << endl;
  	 	cout << "1 - Iniciar corrida" << endl;
  	 	cout << "2 - Inserir sapo manualmente - Novo competidor" << endl;
  	 	cout << "3 - Estatisticas dos participantes" << endl;
  	 	cout << "4 - Para sair" << endl;
  	 	cin >> option;
    }else{
      cout << endl;
      cout << endl;
      cout << "A corrida já foi terminada, confira as estatisticas gerais dos participantes " ;
      cout << "ou execute novamente para iniciar uma nova prova!!" << endl;
      cout << "3 - Estatisticas dos participantes" << endl;
      cout << "4 - Para sair" << endl;
      cin >> option;
      if(option != 3)
        option = 4;
    }



		if(option == 1){

      C.Pista();
		 	C.corrida();
      corridaTerminada++;
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
  cout << "-------------------------------------------"<< endl;
	cout << "|Sapos deixando local de prova, até mais!!|"<< endl;
  cout << "-------------------------------------------" << endl;
	return 0;
}
