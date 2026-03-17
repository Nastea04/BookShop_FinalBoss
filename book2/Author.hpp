#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <iostream>
#include<string>
using namespace std;

class Author {
private:
	string name;
	int yearB;
	bool isDead;
	int yearD;
	string country;
public:
	//get
	string getName();
	int getYearB();
	bool getIsDead();
	int getYearD();
	string getCountry();
	//set
	void setName(string name);
	void setYearB(int yearB);
	void setIsDead(bool isDead);
	void setYearD(int yearD);
	void setCountry(string country);
	//член-функции
	void getInfo();
	void printInfo();

	void putInFile();
	int getFromFile(int cursor);
};

#endif // !AUTHOR_HPP