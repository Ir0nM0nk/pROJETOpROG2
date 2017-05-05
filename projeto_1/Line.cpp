
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "structs.h"
#include "auxfunc.h"			//eraseExtraSpaces() 
#include "Line.h"

using namespace std;

int line::getId() const
{
	return 0;
}

void line::setId(int)
{
}

int line::getbusFreq() const
{
	return 0;
}

void line::setbusFreq(int)
{
}

vector<string> line::gettravelTimes(int)
{
	return string();
}

void line::settravelTimes(string)
{
}

vector<string> line::getStops() const
{
	return string();
}

void line::setStops(string)
{
}

