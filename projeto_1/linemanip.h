/*
FICHEIRO	: linemanip.h
DATA		: 2017/04/15
AUTOR		: SS
FINALIDADE:
-prot�tipos das fun��es definidas em linemanip.cpp
*/

#ifndef LINEMANIP_H
#define LINEMANIP_H

#include <vector>

#include "structs.h"

/*
Seleciona a op��o correspondente ao tipo de altera��o que o utilizador
pretende fazer nos dados das linhas
@param linesVec - vetor das linhas
*/
void lineManagement(std::vector <line> &linesVec);

#endif