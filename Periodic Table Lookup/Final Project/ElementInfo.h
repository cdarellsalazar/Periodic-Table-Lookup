//################################################## 
// File: ElementInfo.h
// Author: Christian Salazar
// Description: This file contains the private member variables and function prototypes for the ElementInfo class
// Date: 12/8/2022
//##################################################

#ifndef ELEMENTINFO
#define ELEMENTINFO

#include <string>

using std::string;

class ElementInfo
{
private:
	int mAtomicNumber;
	string mSymbol;
	string mName;
	double mAtomicWeight;

public:
	ElementInfo();
	ElementInfo(int aNum);
	ElementInfo(string n);
	ElementInfo(int aNum, string sym, string n, double aWeight);

	int getAtomicNum() const;
	string getSymbol() const;
	string getName() const;
	double getAtomicWeight() const;

	bool operator<(const ElementInfo &e1) const;
	bool operator==(const ElementInfo& e1) const;
	bool operator==(const int n) const;
	bool operator==(const string s) const;
};

#endif