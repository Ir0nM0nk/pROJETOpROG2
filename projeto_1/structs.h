/*
FICHEIRO	: structs.h
DATA		: 2017/04/05
AUTOR		: SS
FINALIDADE:
-definição de estruturas
*/

#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
#include <string>

typedef unsigned int uint;

//esta estrutura armazena a informação sobre cada linha
/*struct line
{
	uint id;
	uint busFreq;						// frequência de circulação dos autocarros na linha (em minutos)
	std::vector <std::string> stops;	// lista de paragens
	std::vector <uint> travelTimes;		// tempos de viagem entre paragens (minutos)
};*/

//esta struct armazena a informação sobre cada condutor
struct driver
{
	uint id;
	std::string name;
	uint maxShift;		// nº de horas consecutivas que pode trabalhar por dia (um turno)
	uint weeklyHourMax;	// nº máximo de horas que pode trabalhar por semana
	uint minRestTime;	// nº mínimo de horas de descanso obrigatório entre turnos
};

#endif