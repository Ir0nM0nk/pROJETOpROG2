/*
FICHEIRO   : auxfunc.h
DATA   : 2017/04/10
AUTOR : SS
FINALIDADE:
-Prot�tipos de fun��es definidas em auxfunc.cpp
*/

#ifndef AUXFUN_H
#define AUXFUN_H

#include <string>
#include <vector>

#include "structs.h"

/*
Display de uma introdu��o
*/
void showIntro();
/*
Display do menu principal
*/
void showMenu();
/*
Elimina espa�os extra na string
@param str - string a alterar
*/
void eraseExtraSpaces(std::string &str);
/*
Procura um id numa estrutura de dados
@param id - id a verificar
@param vec - vetor que cont�m dados a comparar
@valor de retorno: -1 caso n�o encotre o id, ou pos (indice da posi��o)
caso encontre
*/
int searchLineID(const uint &id, const std::vector <line> &vec);
int searchDriverID(const uint &id, const std::vector <driver> &vec);
/*
L� um valor inteiro introduzido pelo utilizador.
Este valor deve ser maior que 0.
@param num - numero a ler
@valor de retorno: true caso leitura seja v�lida
*/
bool readPositiveInt(int &num);
/*
L� op��o a executar
@param option - op��o a introduzir pelo utilizador
*/
void readOption(uint &option);
/*
L� o id introduzido pelo utilizador
@param id - id a ser introduzido
*/
void readID(int &id);

#endif