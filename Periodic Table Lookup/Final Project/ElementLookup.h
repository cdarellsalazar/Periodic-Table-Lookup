//################################################## 
// File: ElementLookup.h
// Author: Christian Salazar
// Description: This file contains the private member variables and function prototypes for the ElementLookup class
// Date: 12/8/2022
//##################################################

#ifndef ELEMENTLOOKUP
#define ELEMENTLOOKUP

#include "AVLTree.h"
#include "ElementInfo.h"
#include <vector>

using std::vector;

class ElementLookup
{
private:
	const ElementInfo mNotFound;
	AVLTree<ElementInfo> mElementTree{mNotFound};
	vector<string> mNames;

public:
	ElementLookup();

	void readFile(const string filename);
	string lookup(const string eName) const;
	string lookup(const int aNum) const;

};



#endif
