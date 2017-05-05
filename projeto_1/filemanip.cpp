/*
FICHEIRO   : filemanip.cpp
DATA   : 2017/04/10
AUTOR : SS
FINALIDADE:
-Definição de funções para leitura dos ficheiros
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Line.h"
#include "structs.h"
#include "auxfunc.h"			//eraseExtraSpaces()

using namespace std;

// Bloco relativo à leitura dos dados das linhas

/*
Armazena todas as paragens no respetivo vetor da struct "line".
@param stops - string com todas as paragens (a separar)
@param lineStruct - struct para onde vai armazenar as paragens (separadamente)
*/




void readStops(const string &stops, line &lineStruct)
{
	istringstream stopsStr(stops);
	string stop;

	while (getline(stopsStr, stop, ','))	//repete até EOF
	{
		eraseExtraSpaces(stop);
		lineStruct.stops.push_back(stop);	//coloca paragem no vetor "stops" da struct
	} 
}

/*
Armazena os tempos de viagem no respetivo vetor da struct "line"
@param times - string com todas os tempos (a separar)
@param lineStruct - struct para onde vai armazenar os tempos (separadamente)
*/
void readTimes(const string &times, line &lineStruct)
{
	istringstream timesStr(times);
	string time;

	while (getline(timesStr, time, ','))
		lineStruct.travelTimes.push_back(stoi(time));	//coloca cada tempo no vetor "travelTimes" da struct
}

/*
Separa os vários tipos de dados relativos a uma linha e armazena numa struct
-ID
-Freq. de circulação dos autocarros na linha
-Sequência de paragens
-Tempos de viagem entre paragens
@param inputLine - string com toda a informação a separar
sobre a linha
@valor de retorno: struct "line" com os dados da linha estruturados
*/
line decomposeLine(const string &inputLine)
{
	line NewLine;

	istringstream lineStr(inputLine);
	string input;

	getline(lineStr, input, ';');		
	line::setId(lineStr);				//guarda id
										//stoi tranforma string num número inteiro
	getline(lineStr, input, ';');
	lineStruct.busFreq = stoi(input);	//guarda frequência

	getline(lineStr, input, ';');
	readStops(input, lineStruct);		//guarda paragens

	getline(lineStr, input);
	readTimes(input, lineStruct);		//guarda tempos de viagem
	
	return lineStruct;
}

/*
Lê os dados relativos a cada linha contidas no ficheiro
e guarda tudo num vetor de structs.
@param in - stream de entrada de onde lê a informação
@valor de retorno: vetor de structs "line", com informação de cada linha
*/
vector <line> readLines(ifstream &in)
{
	vector <line> linesVec;
	string inLine;										//string que contém cada linha completa

	while (getline(in, inLine))							//repete enquanto não chegar ao fim do ficheiro (EOF)
		linesVec.push_back(decomposeLine(inLine));		//coloca retorno (struct "line") no vetor

	return linesVec;
}

// Bloco relativo à leitura dos dados dos condutores

/*
Armazena os dados relativos a um condutor na struct "driver"
-ID
-Nome
-Horas consecutivas que pode conduzir por dia (um turno)
-Máximo de horas que pode conduzir por semana
-Mínimo de horas de descanso obrigatório entre turnos
@param inputLine - string com toda a informação de um condutor (a separar)
@valor de retorno: struct com todos os dados relativos ao condutor
*/
driver decomposeDriver(const string &inputLine)
{
	line Newline;
	driver driverStruct;


	istringstream driverStr(inputLine);
	string input;

	getline(driverStr, input, ';');				// lê id

	driverStruct.id = stoi(input);				// guarda o id na struct

	getline(driverStr, input, ';');				// lê nome
	eraseExtraSpaces(input);					
	driverStruct.name = input;					// guarda o nome

	getline(driverStr, input, ';');				// lê horas consecutivas que pode conduzir por dia (turno)
	driverStruct.maxShift= stoi(input);			

	getline(driverStr, input, ';');				// lê máximo de horas que pode conduzir por semana
	driverStruct.weeklyHourMax = stoi(input);

	getline(driverStr, input);					// lê mínimo de horas de descanso obrigatório entre turnos
	driverStruct.minRestTime = stoi(input);

	return driverStruct;
}

/*
Lê os dados relativos a cada condutor e guarda tudo num
vetor de structs "driver"
@param in - stream de input de onde vai ler a informação
@valor de retorno: vetor de structs "driver", com informação de cada condutor
*/
vector <driver> readDrivers(ifstream &in)
{
	vector <driver> driversVec;
	string inDriver;					//string que contém linha completa do ficheiro

	while (getline(in, inDriver))
		driversVec.push_back(decomposeDriver(inDriver));	//guarda no vetor a struct com os dados estruturados

	return driversVec;
}

//---------------------------------

/*
Carrega a informação do ficheiro das linhas e do ficheiro dos condutores
para os vetores. Termina o programa com erro caso os ficheiros introduzidos
sejam inválidos.
@param linesVec - vetor para onde são guardadas as linhas
@param driversVec - vetor para onde são guardados os condutores
*/
void loadFiles(vector <line> &linesVec, vector <driver> &driversVec)
{
	string fileName;
	ifstream linesInput, driversInput;

	cout << "Introduza os seguintes ficheiros\n\n";

	//Bloco responsável por ligar stream linesInput ao ficheiro das linhas

	cout << "Ficheiro das linhas (nome.txt ou diretorio\\nome.txt)\n";
	getline(cin, fileName);
	cout << endl;

	linesInput.open(fileName);
	if (linesInput.fail())
	{
		cerr << "Ficheiro invalido... Programa terminado\n";
		exit(1);
	}

	//Bloco responsável por ligar stream driversInput ao ficheiro dos condutores

	cout << "Ficheiro dos condutores (nome.txt ou diretorio\\nome.txt)\n";
	getline(cin, fileName);
	cout << endl;

	driversInput.open(fileName);
	if (driversInput.fail())
	{
		cerr << "Ficheiro invalido... Programa terminado\n";
		exit(1);
	}

	//---------------------------

	linesVec = readLines(linesInput);			//vetor que armazena todas as linhas
	driversVec = readDrivers(driversInput);		//vetor que armazena todos os condutores

	linesInput.close();
	driversInput.close();			//fechar ambos os ficheiros porque já não são precisos
	cout << "Ficheiros carregados com sucesso\n";
}