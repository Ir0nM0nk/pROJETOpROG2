/*
FICHEIRO: drivermanip.h
DATA : 2017/04/15
AUTOR : SS
FINALIDADE :
-protótipos das funções definidas em drivermanip.cpp
*/

#ifndef DRIVERMANIP_H
#define DRIVERMANIP_H

#include <vector>

#include "structs.h"

/*
Seleciona a opção correspondente ao tipo de alteração que o utilizador
pretende fazer nos dados dos condutores
@param driversVec - vetor dos condutores
*/
void driverManagement(std::vector <driver> &driversVec);

#endif


