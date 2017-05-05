#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	int height;
public:
	string getName() const;
	void setName(string);
	int getHeight() const;
	void setHeight(int);
};

string Person::getName() const
{
	return name;
}

void Person::setName(string s)
{
	if (s.length() == 0)
		name = "No name assigned";
	else
		name = s;
}

int Person::getHeight() const
{
	return height;
}

void Person::setHeight(int h)
{
	if (h < 0)
		height = 0;
	else
		height = h;
}

void setValues(Person&);
void getValues(const Person&);

int main()
{
	Person p1;
	setValues(p1);
	cout << "Outputting person data\n";
	cout << "======================\n";
	getValues(p1);
	return 0;
}

void setValues(Person& pers)
{
	string str;
	int h;
	cout << "Enter person's name: ";
	getline(cin, str);
	pers.setName(str);
	cout << "Enter height in milimeters: ";
	cin >> h;
	cin.ignore();
	pers.setHeight(h);
}

void getValues(const Person& pers)
{
	cout << "Person's name: " << pers.getName() << endl;
	cout << "Person's height in milimeters is: " << pers.getHeight() << endl;
}