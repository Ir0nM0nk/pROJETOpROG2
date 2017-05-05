/*
FICHEIRO   : main.cpp
DATA   : 2017/04/10
AUTOR : SS
FINALIDADE:
-Implementar uma aplicação que faça a gestão de linhas e condutores de uma empresa de autocarros.
*/

#include <iostream>
#include <vector>

#include "structs.h"
#include "filemanip.h"
#include "auxfunc.h"
#include "linemanip.h"
#include "drivermanip.h"

using namespace std;

int main()
{
	showIntro();

	vector <line> linesVec;
	vector <driver> driversVec;

	loadFiles(linesVec, driversVec);

	uint option;

	do
	{
		showMenu();
		readOption(option);
		/*
		1 - Gestao de linhas
		2 - Gestao de condutores
		3 - Visualizacao de informacao
		0 - Terminar
		*/
		switch (option)
		{
		case 1:
			lineManagement(linesVec);
			break;
		case 2:
			driverManagement(driversVec);
			break;
		case 3:
			cout << "opcao 3\n";
			break;
		case 0:
			cout << "Programa terminado\n";
			break;
		default:
			cerr << "Opcao invalida\n";
		}
	} while (option);			//enquanto option não for 0

	return 0;
}