#include "Author.hpp"

void Author::getInfo()
{
	cout << "---> Author\n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Birth year: ";
	cin >> yearB;
	cout << "Is the author still alive?(y/n)\n";
	char ans;
	cin >> ans;
	if (ans == 'y') {
		isDead = false;
	}
	else {
		isDead = true;
		cout << "Death year: ";
		cin >> yearD;
	}
	cout << "Country: ";
	cin >> country;
}

void Author::printInfo()
{
	cout << "Author's name: " << name << endl;
	cout << "Author's life: " << yearB << '-';
	if (isDead) cout << yearD << endl;
	else cout << "present\n";
	cout << "Author's country: " << country << endl;
}
#include<fstream>
void Author::putInFile()
{
	ofstream fout("info.txt", ios::app);
	fout << name << endl;
	fout << yearB << " " << isDead << " " << yearD << " " << country << endl;
	fout.close();
}

int Author::getFromFile(int cursor)
{
	ifstream fin("info.txt");
	fin.seekg(cursor);
	fin.ignore();
	getline(fin, name);
	fin >> yearB >> isDead >> yearD >> country;
	cursor = fin.tellg();
	fin.close();
	return cursor;
}

string Author::getName()
{
	return name;
}

int Author::getYearB()
{
	return yearB;
}

bool Author::getIsDead()
{
	return isDead;
}

int Author::getYearD()
{
	return yearD;
}

string Author::getCountry()
{
	return country;
}

void Author::setName(string name)
{
	this->name = name;
}

void Author::setYearB(int yearB)
{
	this->yearB = yearB;
}

void Author::setIsDead(bool isDead)
{
	this->isDead = isDead;
}

void Author::setYearD(int yearD)
{
	this->yearD = yearD;
}

void Author::setCountry(string country)
{
	this->country = country;
}
