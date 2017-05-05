/*
FICHEIRO   : linemanip.cpp
DATA   : 2017/04/15
AUTOR : SS
FINALIDADE:
-Defini��o de fun��es para gest�o das linhas
*/

#include <iostream>
#include <vector>
#include <string>

#include "structs.h"
#include "auxfunc.h"

using namespace std;

/*
Display do sub-menu relativo � gest�o de linhas (op��o 1)
*/
void showSubMenu1()
{
	cout << endl;
	showIntro();

	cout << "Selecione uma opcao\n\n";
	cout << "1 - Adicionar linha\n";
	cout << "2 - Alterar linha\n";
	cout << "3 - Remover linha\n";
	cout << "9 - Voltar\n\n";
}

/*
L� a frequ�ncia de circula��o dos autocarros na linha em minutos
@param freq - frequ�ncia de circula��o
*/
void readFreq(int &freq)
{
	cout << "Freq. de circulacao (minutos): ";

	while (!readPositiveInt(freq))		// enquanto a entrada for invalida ou freq <=0
	{
		cerr << "Entrada invalida\n";
		cout << "Freq. de circulacao (minutos): ";
	}
}

/*
L� no m�nimo 2 paragens introduzidas pelo utilizador
Termina quando se verifica a condi��o e � teclado CTRL-Z
@param vec - vetor onde s�o armazenadas as paragens
@valor de retorno: n� de paragens introduzidas
*/
uint readStops(vector <string> &vec)
{
	string stop;
	bool anotherOperation;
	uint i = 0;				// n� da paragens introduzidas

	cout << "Insira no minimo duas paragens\n";

	do
	{
		anotherOperation = true;

		if (i >= 2)			// se j� foram introduzidas n� m�nimo de paragens
			cout << "Paragem-" << (i+1) << " (CTRL-Z para terminar): ";
		else
			cout << "Paragem-" << (i+1) << ": ";
		getline(cin, stop);

		if (cin.eof())
		{
			cin.clear();
			if (i >= 2)
				anotherOperation = false;					// quando for teclado CTRL-Z e j� tiver introduzido 2 paragens termina a execu��o
		}
		else
		{
			eraseExtraSpaces(stop);
			vec.push_back(stop);

			i++;
		}
	} while (anotherOperation);

	return i;
}

/*
L� os tempos de viagem entre as paragens introduzidas
@param vec - vetor onde s�o armazenadas os tempos
@param numStops - n� de paragens existentes
*/
void readTravelTimes(vector <uint> &vec, const uint &numStops)
{
	int time;
	uint i = 1;

	while (i < numStops)			//repete at� que sejam lidos os tempos entre todas as paragens
	{
		cout << "Tempo de viagem entre " << i << " e " << (i + 1) << " (minutos): ";
		if (!readPositiveInt(time))
		{
			cout << "Entrada invalida\n";
			continue;
		}
		vec.push_back(time);
		i++;
	}
}

/*
L� a informa��o completa de uma linha e armazena no vetor das linhas
@param linesVec - vetor das linhas
@valor de retorno: true caso a linha tenha sido adicionada com sucesso
*/
bool addLine(vector <line> &linesVec)
{
	line newLine;				// struct que guarda a nova linha
	int newID, busFreq;
	vector <string> stops;
	vector <uint> travelTimes;

	readID(newID);
	// verificar se o ID j� existe e terminar caso afirmativo
	if (searchLineID(newID, linesVec) != -1)			//esta fun��o retorna -1 caso n�o encontre o id na estrutura
		return false;

	cout << endl;
	readFreq(busFreq);
	cout << endl;
	uint numStops = readStops(stops);		//numStops representa o n�mero de paragens introduzidas
	cout << endl;
	readTravelTimes(travelTimes, numStops);

	newLine.id = newID;
	newLine.busFreq = busFreq;
	newLine.stops = stops;
	newLine.travelTimes = travelTimes;

	linesVec.push_back(newLine);

	return true;
}

/*
Fun��o respons�vel por alterar uma paragem selecionada pelo utilizador
@param vec - vetor com a lista de paragens a modificar
*/
void changeStop(vector <string> &vec)
{
	uint option;
	string newStop;

	cout << "\nSelecione a paragem a alterar\n\n";

	for (size_t i = 0; i < vec.size(); i++)			// display de paragens com os �ndices para
		cout << i << " - " << vec.at(i) << endl;	// o utilizador selecionar o que pretende alterar
	cout << endl;

	readOption(option);								// option - �ndice da paragem a alterar
	
	if (option < vec.size())
	{
		cout << "Nova paragem: ";

		if (getline(cin, newStop))
		{
			eraseExtraSpaces(newStop);
			vec.at(option) = newStop;
		}
		else
		{
			cin.clear();
			cerr << "Entrada invalida\n";
		}
	}
	else
		cerr << "Opcao inexistente\n";
}

/*
Func��o respons�vel por modificar o tempo de viagem entre duas paragens
de uma determinada linha.
@param timesVec - vetor com os tempos de viagem
@param stopsVec - vetor com a lista das paragens
*/
void changeTime(vector <uint> &timesVec, const vector <string> &stopsVec)
{
	uint option;
	int newTime;

	cout << "\nSelecione o tempo de viagem a alterar\n\n";

	for (size_t i = 0; i < timesVec.size(); i++)					// display de todos tempos de viagem com os �ndices para o utilizador selecionar
		cout << i << " - entre " << stopsVec.at(i) << " e " << stopsVec.at(i + 1) << endl;
	cout << endl;

	readOption(option);
	if (option < timesVec.size())				// se tempo selecionado � v�lido
	{
		cout << "Novo tempo de viagem: ";

		if (readPositiveInt(newTime))
			timesVec.at(option) = newTime;
		else
			cerr << "Entrada invalida\n";
	}
	else
		cerr << "Opcao inexistente\n";
}

/*
Mostrar as op��es de altera��o da linha
*/
void showLineOptions()
{
	cout << "\nSelecione a informacao a alterar\n\n"
		<< "1 - ID\n"
		<< "2 - Frequencia de circulacao\n"
		<< "3 - Paragens\n"
		<< "4 - Tempos de viagem\n"
		<< "9 - Voltar\n\n";
}

/*
Seleciona a op��o correspondente ao tipo de altera��o que o utilizador
pretende fazer na linha
@param lineStruct - struct com dados da linha que se pretende alterar
@param linesVec - vetor das linhas para verificar se existe repeti��o
do id introduzido pelo utilizador (aquando da modifica��o)
*/
void changeLine(line &lineStruct, vector <line> &linesVec)
{
	uint option;		// informa��o a alterar
	do
	{
		showLineOptions();
		readOption(option);
		/*
		1 - ID
		2 - Frequencia de circulacao
		3 - Paragens
		4 - Tempos de viagem
		9 - Voltar
		*/
		switch (option)
		{
		case 1:		//ler novo ID e guardar
			int newID;
			readID(newID);
			if (searchLineID(newID, linesVec) == -1)			//verificar se newID n�o existe no vetor de linhas
				lineStruct.id = newID;
			else
				cerr << "\nERRO - Novo id corresponde ao id de outra linha\n";
			break;
		case 2:												//ler nova frequ�ncia de circula��o e guardar
			int newFreq;
			readFreq(newFreq);
			lineStruct.busFreq = newFreq;
			break;
		case 3:
			changeStop(lineStruct.stops);
			break;
		case 4:
			changeTime(lineStruct.travelTimes, lineStruct.stops);
			break;
		case 9:
			break;
		default:
			cerr << "Opcao invalida\n";
		}
	} while (option != 9);
}

/*
Fun��o respons�vel por alterar os dados das linhas pretendidos pelo utilizador
@param linesVec - vetor das linhas
@valor de retorno - retorna false caso o ID da linha que se pretende alterar n�o exista
*/
bool changeLine(vector <line> &linesVec)
{
	int id;
	
	// Ler o id da linha a alterar
	cout << "ID da linha a alterar: ";
	while (!readPositiveInt(id))		// enquanto a entrada for invalida ou id <=0
	{
		cerr << "Entrada invalida\n";
		cout << "ID da linha a alterar: ";
	}
	
	int pos = searchLineID(id, linesVec);			// �ndice da linha com id introduzido
	// retornar false caso id n�o seja encontrado
	if (pos == -1)
		return false;
	
	// Realizar altera��es
	changeLine(linesVec.at(pos), linesVec);
	return true;
}

/*
Fun��o respons�vel por eliminar os dados de uma linha introduzida pelo utilizador
@param linesVec - vetor das linhas
@valor de retorno - retorna false caso o ID da linha que se pretende remover n�o exista
*/
bool removeLine(vector <line> &linesVec)
{
	int id;

	// Ler o id da linha a remover
	cout << "ID da linha a remover: ";
	while (!readPositiveInt(id))		// enquanto a entrada for invalida ou id <=0
	{
		cerr << "Entrada invalida\n";
		cout << "ID da linha a remover: ";
	}

	int pos = searchLineID(id, linesVec);			// �ndice da linha com id introduzido
	// retornar false caso id n�o seja encontrado
	if (pos == -1)
		return false;

	linesVec.erase(linesVec.begin()+pos);

	return true;
}

/*
Seleciona a op��o correspondente ao tipo de altera��o que o utilizador
pretende fazer nos dados das linhas
@param linesVec - vetor das linhas
*/
void lineManagement(vector <line> &linesVec)
{
	uint option;

	do
	{
		showSubMenu1();
		readOption(option);
		/*
		1 - Adicionar linha
		2 - Alterar linha
		3 - Remover linha
		9 - Voltar
		*/
		switch (option)
		{
		case 1:
			if (addLine(linesVec))
				cout << "\nLinha adicionada com sucesso\n";
			else
				cerr << "\nErro - Linha ja existente\n";
			break;
		case 2:
			if (changeLine(linesVec))
				cout << "\nAlteracao guardada com sucesso\n";
			else
				cerr << "\nErro - Linha nao encontrada\n";
			break;
		case 3:
			if (removeLine(linesVec))
				cout << "\nLinha removida com sucesso\n";
			else
				cerr << "\nErro - Linha nao encontrada\n";
			break;
		case 9:
			break;
		default:
			cerr << "Opcao invalida\n";
		}
	} while (option != 9);			//enquanto option n�o for 9
}