/*
FICHEIRO   : auxfunc.h
DATA   : 2017/04/10
AUTOR : SS
FINALIDADE:
-Protótipos de funções definidas em auxfunc.cpp
*/

#ifndef AUXFUN_H
#define AUXFUN_H

#include <string>
#include <vector>

#include "structs.h"

/*
Display de uma introdução
*/
void showIntro();
/*
Display do menu principal
*/
void showMenu();
/*
Elimina espaços extra na string
@param str - string a alterar
*/
void eraseExtraSpaces(std::string &str);
/*
Procura um id numa estrutura de dados
@param id - id a verificar
@param vec - vetor que contém dados a comparar
@valor de retorno: -1 caso não encotre o id, ou pos (indice da posição)
caso encontre
*/
int searchLineID(const uint &id, const std::vector <line> &vec);
int searchDriverID(const uint &id, const std::vector <driver> &vec);
/*
Lê um valor inteiro introduzido pelo utilizador.
Este valor deve ser maior que 0.
@param num - numero a ler
@valor de retorno: true caso leitura seja válida
*/
bool readPositiveInt(int &num);
/*
Lê opção a executar
@param option - opção a introduzir pelo utilizador
*/
void readOption(uint &option);
/*
Lê o id introduzido pelo utilizador
@param id - id a ser introduzido
*/
void readID(int &id);

#endif