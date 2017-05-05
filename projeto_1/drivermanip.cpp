/*
FICHEIRO   : drivermanip.cpp
DATA   : 2017/04/16
AUTOR : SS
FINALIDADE:
-Defini��o de fun��es para gest�o dos condutores
*/

#include <iostream>
#include <vector>
#include <string>

#include "structs.h"
#include "auxfunc.h"

using namespace std;

/*
Display do sub-menu relativo � gest�o de condutores (op��o 2)
*/
void showSubMenu2()
{
	cout << endl;
	showIntro();

	cout << "Selecione uma opcao\n\n";
	cout << "1 - Adicionar condutor\n";
	cout << "2 - Alterar condutor\n";
	cout << "3 - Remover condutor\n";
	cout << "9 - Voltar\n\n";
}

/*
L� o novo nome do condutor
@param name - nome do condutor
*/
void readName(string &name)
{
	cout << "Insira o nome: ";
	
	while (!getline(cin, name))
	{
		if (cin.eof())
			cin.clear();
	}

	eraseExtraSpaces(name);
}

/*
L� o n�mero de horas consecutivas que pode conduzir por dia (um turno)
@param maxShift - n�mero de horas consecutivas que pode conduzir por dia (um turno)
*/
void readMaxShift(int &maxShift)
{
	cout << "Num. max. de horas consecutivas que pode conduzir por dia: ";

	while (!readPositiveInt(maxShift))		// enquanto a entrada for invalida ou freq <=0
	{
		cerr << "Entrada invalida\n";
		cout << "Num. max. de horas consecutivas que pode conduzir por dia: ";
	}
}

/*
L� o n�mero m�ximo de horas que pode conduzir por semana
@param weeklyHourMax - n�mero m�ximo de horas que pode conduzir por semana
*/
void readWeeklyHourMax(int &weeklyHourMax)
{
	cout << "Num. max. de horas que pode conduzir por semana: ";

	while (!readPositiveInt(weeklyHourMax))		// enquanto a entrada for invalida ou freq <=0
	{
		cerr << "Entrada invalida\n";
		cout << "Num. max. de horas que pode conduzir por semana: ";
	}
}

/*
L� o n�mero m�nimo de horas de descanso obrigat�rio
@param minRestTime - n�mero m�nimo de horas de descanso obrigat�rio
*/
void readMinRestTime(int &minRestTime)
{
	cout << "Num. min. de horas de descanso obrigatorio: ";

	while (!readPositiveInt(minRestTime))		// enquanto a entrada for invalida ou freq <=0
	{
		cerr << "Entrada invalida\n";
		cout << "Num. min. de horas de descanso obrigatorio: ";
	}
}

/*
L� a informa��o completa de um condutor e armazena no vetor dos condutores
@param driversVec - vetor dos condutores
@valor de retorno: true caso o condutor tenha sido adicionado com sucesso
*/
bool addDriver(vector <driver> &driversVec)
{
	driver newDriver;				// struct que guarda o novo condutor
	int newID, maxShift, weeklyHourMax, minRestTime;
	string name;

	readID(newID);
	// verificar se o ID j� existe e terminar caso afirmativo
	if (searchDriverID(newID, driversVec) != -1)			//esta fun��o retorna -1 caso n�o encontre o id na estrutura
		return false;

	cout << endl;
	readName(name);
	cout << endl;
	readMaxShift(maxShift);
	cout << endl;
	readWeeklyHourMax(weeklyHourMax);
	cout << endl;
	readMinRestTime(minRestTime);

	newDriver.id = newID;
	newDriver.name = name;
	newDriver.maxShift = maxShift;
	newDriver.weeklyHourMax = weeklyHourMax;
	newDriver.minRestTime = minRestTime;

	driversVec.push_back(newDriver);

	return true;
}

/*
Mostrar as op��es de altera��o do condutor
*/
void showDriverOptions()
{
	cout << "\nSelecione a informacao a alterar\n\n"
		<< "1 - ID\n"
		<< "2 - Nome\n"
		<< "3 - N�mero de horas consecutivas que pode conduzir por dia\n"
		<< "4 - N�mero m�ximo de horas que pode conduzir por semana\n"
		<< "5 - N�mero m�nimo de horas de descanso obrigat�rio\n"
		<< "9 - Voltar\n\n";
}

/*
Seleciona a op��o correspondente ao tipo de altera��o que o utilizador
pretende fazer no condutor
@param driverStruct - struct com dados do condutor que se pretende alterar
@param driversVec - vetor dos condutores para verificar se existe repeti��o
do id introduzido pelo utilizador (aquando da modifica��o)
*/
void changeDriver(driver &driverStruct, vector <driver> &driversVec)
{
	uint option;		// informa��o a alterar

	do
	{
		showDriverOptions();
		readOption(option);
		/*
		1 - ID
		2 - Nome
		3 - N�mero de horas consecutivas que pode conduzir por dia (um turno)
		4 - N�mero m�ximo de horas que pode conduzir por semana
		5 - N�mero m�nimo de horas de descanso obrigat�rio
		9 - Voltar
		*/
		switch (option)
		{
		case 1:		//ler novo ID e guardar
			int newID;
			readID(newID);
			if (searchDriverID(newID, driversVec) == -1)			//verificar se newID n�o existe no vetor de condutores
				driverStruct.id = newID;
			else
				cerr << "\nERRO - Novo id corresponde ao id de outro condutor\n";
			break;
		case 2:
		{
			string newName;
			readName(newName);
			driverStruct.name = newName;
			break;
		}
		case 3:
			int newMaxShift;
			readMaxShift(newMaxShift);
			driverStruct.maxShift = newMaxShift;
			break;
		case 4:
			int newWeeklyHourMax;
			readWeeklyHourMax(newWeeklyHourMax);
			driverStruct.weeklyHourMax = newWeeklyHourMax;
			break;
		case 5:
			int newMinRestTime;
			readMinRestTime(newMinRestTime);
			driverStruct.minRestTime = newMinRestTime;
			break;
		case 9:
			break;
		default:
			cerr << "Opcao invalida\n";
		}
	} while (option != 9);
}

/*
Fun��o respons�vel por alterar os dados dos condutores pretendidos pelo utilizador
@param driversVec - vetor dos condutores
@valor de retorno - retorna false caso o ID do condutor que se pretende alterar n�o exista
*/
bool changeDriver(vector <driver> &driversVec)
{
	int id;

	// Ler o id do condutor a alterar
	cout << "ID do condutor a alterar: ";
	while (!readPositiveInt(id))		// enquanto a entrada for invalida ou id <=0
	{
		cerr << "Entrada invalida\n";
		cout << "ID do condutor a alterar: ";
	}

	int pos = searchDriverID(id, driversVec);			// �ndice da linha com id introduzido
	// retornar false caso id n�o seja encontrado
	if (pos == -1)
		return false;

	// Realizar altera��es
	changeDriver(driversVec.at(pos), driversVec);
	return true;
}

/*
Fun��o respons�vel por eliminar os dados de um condutor selecionado pelo utilizador
@param driversVec - vetor dos condutores
@valor de retorno - retorna false caso o ID do condutor que se pretende remover n�o exista
*/
bool removeDriver(vector <driver> &driversVec)
{
	int id;

	// Ler o id do condutor a remover
	cout << "ID do condutor a remover: ";
	while (!readPositiveInt(id))		// enquanto a entrada for invalida ou id <=0
	{
		cerr << "Entrada invalida\n";
		cout << "ID do condutor a remover: ";
	}

	int pos = searchDriverID(id, driversVec);			// �ndice do condutor com id introduzido
	// retornar false caso id n�o seja encontrado
	if (pos == -1)
		return false;

	driversVec.erase(driversVec.begin() + pos);

	return true;
}

/*
Seleciona a op��o correspondente ao tipo de altera��o que o utilizador
pretende fazer nos dados dos condutores
@param driversVec - vetor dos condutores
*/
void driverManagement(vector <driver> &driversVec)
{
	uint option;

	do
	{
		showSubMenu2();
		readOption(option);
		/*
		1 - Adicionar condutor
		2 - Alterar condutor
		3 - Remover condutor
		9 - Voltar
		*/
		switch (option)
		{
		case 1:
			if (addDriver(driversVec))
				cout << "\nCondutor adicionado com sucesso\n";
			else
				cerr << "\nErro - Condutor ja existente\n";
			break;
		case 2:
			if (changeDriver(driversVec))
				cout << "\nAlteracao guardada com sucesso\n";
			else
				cerr << "\nErro - Condutor nao encontrado\n";
			break;
		case 3:
			if (removeDriver(driversVec))
				cout << "\nCondutor removido com sucesso\n";
			else
				cerr << "\nErro - Condutor nao encontrado\n";
			break;
		case 9:
			break;
		default:
			cerr << "Opcao invalida\n";
		}
	} while (option != 9);			//enquanto option n�o for 9
}