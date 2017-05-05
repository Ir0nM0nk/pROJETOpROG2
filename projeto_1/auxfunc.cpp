/*
FICHEIRO   : auxfunc.cpp
DATA   : 2017/04/10
AUTOR : SS
FINALIDADE:
-Defini��o de fun��es auxiliares � execu��o do programa, comuns aos v�rios ficheiros .cpp
*/

#include <iostream>
#include <string>
#include <sstream>

#include "structs.h"

using namespace std;

// Bloco relativo a displays

/*
Display de uma introdu��o
*/
void showIntro()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "~~~~~~~~~~~~~~~ SEMPRARROLAR ~~~~~~~~~~~~~~~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}

/*
Display do menu principal
*/
void showMenu()
{
	cout << endl;
	showIntro();

	cout << "Selecione uma opcao\n\n";
	cout << "1 - Gestao de linhas\n";
	cout << "2 - Gestao de condutores\n";
	cout << "3 - Visualizacao de informacao\n";
	cout << "0 - Terminar\n\n";
}

//--------------------

/*
Elimina espa�os extra na string
@param str - string a alterar
*/
void eraseExtraSpaces(string &str)
{
	istringstream sstr(str);
	string aux;					//string auxiliar

	str.clear();				//limpa string que � alterada por refer�ncia
	sstr >> str;

	while (sstr >> aux)
		str = str + " " + aux;
}

/*
Procura um id numa estrutura de dados
@param id - id a verificar
@param vec - vetor que cont�m dados a comparar
@valor de retorno: -1 caso n�o encotre o id, ou pos (indice da posi��o)
caso encontre
*/
int searchLineID(const uint &id, const vector <line> &vec)
{
	for (size_t pos = 0; pos < vec.size(); pos++)
	{
		if (id == vec.at(pos).id)
			return pos;
	}
	return -1;
}

int searchDriverID(const uint &id, const vector <driver> &vec)
{
	for (size_t pos = 0; pos < vec.size(); pos++)
	{
		if (id == vec.at(pos).id)
			return pos;
	}
	return -1;
}

/*
L� um valor inteiro introduzido pelo utilizador.
Este valor deve ser maior que 0.
@param num - numero a ler
@valor de retorno: true caso leitura seja v�lida
*/
bool readPositiveInt(int &num)
{
	cin >> num;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	else if (num <= 0)
	{
		cin.ignore(1000, '\n');
		return false;
	}
	else
	{
		cin.ignore(1000, '\n');
		return true;
	}
}

/*
L� op��o a executar
@param option - op��o a introduzir pelo utilizador
*/
void readOption(uint &option)
{
	cin >> option;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		option = -1;			// op��o n�o existente
	}
	else
		cin.ignore(1000, '\n');
}

/*
L� o id introduzido pelo utilizador
@param id - id a ser introduzido
*/
void readID(int &id)
{
	cout << "ID: ";

	while (!readPositiveInt(id))		// enquanto a entrada for invalida ou id <=0
	{
		cerr << "Entrada invalida\n";
		cout << "ID: ";
	}
}