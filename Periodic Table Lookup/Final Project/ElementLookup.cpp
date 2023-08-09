//################################################## 
// File: ElementLookup.cpp
// Author: Christian Salazar
// Description: This file contains the code for the functions in the ElementLookup class
// Date: 12/8/2022
//##################################################

#include "ElementLookup.h"
#include <fstream>
#include <iostream>
#include "ElementLookupException.h"

using std::ifstream;
using std::to_string;

//#################################################
// @par Name
// - ElementLookup
// @purpose
// - Default constructor
// @param [in] :
// - None
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
ElementLookup::ElementLookup()
{

}

//#################################################
// @par Name
// - readFile
// @purpose
// - Reads in the Periodic Table of Elements from the file given
// @param [in] : const string filename
// - Name of the file to be read in
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
void ElementLookup::readFile(const string filename)
{
	ifstream infile(filename);

	if (!infile)
	{
		return;
	}

	string name, symbol, atomicnum, atomicweight;
	double aweight;
	int anum;

	getline(infile, name); // ignores first line
	while (getline(infile, name, ','))
	{
		getline(infile, symbol, ',');
		symbol = symbol.substr(1, symbol.size() - 1); // deletes miscellaneous space at beginning of each element symbol

		getline(infile, atomicnum, ',');
		anum = stoi(atomicnum);

		getline(infile, atomicweight, '\n');
		aweight = stod(atomicweight);

		ElementInfo e(anum, symbol, name, aweight);
		this->mElementTree.insert(e);
		mNames.push_back(name);
	}
}

//#################################################
// @par Name
// - lookup(int anum)
// @purpose
// - Overloaded function that takes an Atomic Number and returns a formatted string 
// @param [in] : int anum
// - Atomic Number of the desired element
// @return
// - string
// @par References
// - None
// @par Notes
// - Delegates to the lookup(string eName) function
//#################################################
string ElementLookup::lookup(int anum) const
{
	if (anum > mNames.size() || anum <= 0)
	{
		throw ElementLookupException("ERROR: Atomic Number is out of range. Please ensure the input is a valid Atomic Number.");
	}
	return this->lookup(mNames[anum - 1]);
}

//#################################################
// @par Name
// - lookup(string eName)
// @purpose
// - Function that find the desired element with AVL Tree and returns a formatted string
// @param [in] : string eName
// - Name of the desired element
// @return
// - string
// @par References
// - None
// @par Notes
// - None
//#################################################
string ElementLookup::lookup(string eName) const // have one of these functiosn call each other
{
	ElementInfo tmp(eName);
	ElementInfo p = this->mElementTree.contains(tmp);
	string s;
	if (p == mNotFound)
	{
		s = "ERROR: Element is not in the tree.";
	}
	else
	{
		s = "Atomic Number: ";
		s += to_string(p.getAtomicNum());
		s += ", Name: ";
		s += p.getName();
		s += ", Symbol: ";
		s += p.getSymbol();
		s += ", Atomic Weight: ";
		s += to_string(p.getAtomicWeight());
	}
	return s;
}