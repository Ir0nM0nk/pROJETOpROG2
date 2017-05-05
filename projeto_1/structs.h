/*
FICHEIRO	: structs.h
DATA		: 2017/04/05
AUTOR		: SS
FINALIDADE:
-defini��o de estruturas
*/

#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
#include <string>

typedef unsigned int uint;

//esta estrutura armazena a informa��o sobre cada linha
/*struct line
{
	uint id;
	uint busFreq;						// frequ�ncia de circula��o dos autocarros na linha (em minutos)
	std::vector <std::string> stops;	// lista de paragens
	std::vector <uint> travelTimes;		// tempos de viagem entre paragens (minutos)
};*/

//esta struct armazena a informa��o sobre cada condutor
struct driver
{
	uint id;
	std::string name;
	uint maxShift;		// n� de horas consecutivas que pode trabalhar por dia (um turno)
	uint weeklyHourMax;	// n� m�ximo de horas que pode trabalhar por semana
	uint minRestTime;	// n� m�nimo de horas de descanso obrigat�rio entre turnos
};

#endif