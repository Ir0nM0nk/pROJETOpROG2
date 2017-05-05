/*
FICHEIRO	: filemanip.h
DATA		: 2017/04/10
AUTOR		: SS
FINALIDADE:
-prot�tipos das fun��es definidas em filemanip.cpp
*/

#ifndef FILEMANIP_H
#define FILEMANIP_H

#include <vector>

#include "structs.h"

/*
Carrega a informa��o do ficheiro das linhas e do ficheiro dos condutores
para os vetores. Termina o programa com erro caso os ficheiros introduzidos
sejam inv�lidos.
@param linesVec - vetor para onde s�o guardadas as linhas
@param driversVec - vetor para onde s�o guardados os condutores
*/
void loadFiles(std::vector <line> &linesVec, std::vector <driver> &driversVec);

#endif