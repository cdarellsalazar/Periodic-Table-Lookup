//################################################## 
// File: ElementLookupException.cpp
// Author: Christian Salazar
// Description: This file contains the code for the function in the ElementLookupException class
// Date: 12/8/2022
//##################################################

#include "ElementLookupException.h"

using namespace std;

//#################################################
// @par Name
// - ElementLookupException(string msg)
// @purpose
// - Constructor that sets mMessage to msg
// @param [in] :
// - string msg
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
ElementLookupException::ElementLookupException(string msg)
{
	mMessage = msg;
}

//#################################################
// @par Name
// - what
// @purpose
// - Provides a cstring that contains information about the exception
// @param [in] :
// - None
// @return
// - char
// @par References
// - Unit 0 Exceptions Lecture
// @par Notes
// - None
//#################################################
const char* ElementLookupException::what()
{
	return mMessage.c_str();
}