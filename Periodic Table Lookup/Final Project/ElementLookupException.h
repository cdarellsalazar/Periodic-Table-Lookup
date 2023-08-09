//################################################## 
// File: ElementLookupException.h
// Author: Christian Salazar
// Description: This file contains the function prototypes for the ElementLookupException class
// Date: 12/8/2022
//##################################################

#ifndef ELEMENTLOOKUPEXCEPTION
#define ELEMENTLOOKUPEXCEPTION

#include <exception>
#include <string>
using std::string;
using std::exception;

class ElementLookupException : public exception
{
private:
	string mMessage;
public:
	ElementLookupException(string msg);
	virtual const char* what();
};

#endif