/*
FICHEIRO	: classes.h
DATA		: 2017/04/0
FINALIDADE: -definição de classes
*/

#ifndef LINE_H
#define LINE_H

#include <vector>
#include <string>
#include <iostream>

typedef unsigned int uint;

//esta estrutura armazena a informação sobre cada linha

class line{
private: uint id;
		 uint busFreq;
		 std::vector <std::string> stops;
		 std::vector <uint> travelTimes;

public: 
	int getId()const;
	void setId(int);
	
	int getbusFreq()const;
	void setbusFreq(int);
	
	vector<string> gettravelTimes(int);
	void settravelTimes(string);
	
	vector<string> getStops()const;
	void setStops(string);
	

};
#endif
