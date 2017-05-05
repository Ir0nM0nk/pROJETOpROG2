/*
FICHEIRO	: linemanip.h
DATA		: 2017/04/15
AUTOR		: SS
FINALIDADE:
-protótipos das funções definidas em linemanip.cpp
*/

#ifndef LINEMANIP_H
#define LINEMANIP_H

#include <vector>

#include "structs.h"

/*
Seleciona a opção correspondente ao tipo de alteração que o utilizador
pretende fazer nos dados das linhas
@param linesVec - vetor das linhas
*/
void lineManagement(std::vector <line> &linesVec);

#endif