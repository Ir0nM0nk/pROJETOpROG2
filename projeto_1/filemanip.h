/*
FICHEIRO	: filemanip.h
DATA		: 2017/04/10
AUTOR		: SS
FINALIDADE:
-protótipos das funções definidas em filemanip.cpp
*/

#ifndef FILEMANIP_H
#define FILEMANIP_H

#include <vector>

#include "structs.h"

/*
Carrega a informação do ficheiro das linhas e do ficheiro dos condutores
para os vetores. Termina o programa com erro caso os ficheiros introduzidos
sejam inválidos.
@param linesVec - vetor para onde são guardadas as linhas
@param driversVec - vetor para onde são guardados os condutores
*/
void loadFiles(std::vector <line> &linesVec, std::vector <driver> &driversVec);

#endif