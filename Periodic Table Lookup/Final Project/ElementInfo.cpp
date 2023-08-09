//################################################## 
// File: ElementInfo.cpp
// Author: Christian Salazar
// Description: This file contains the code for the functions in the ElementInfo class
// Date: 12/8/2022
//##################################################

#include "ElementInfo.h"
#include <iostream>

//#################################################
// @par Name
// - ElementInfo()
// @purpose
// - Default constructor that sets info to zero + not found
// @param [in] :
// - None
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
ElementInfo::ElementInfo()
	:mAtomicNumber(0), mSymbol("NF"), mName("ELEMENT NOT FOUND"), mAtomicWeight(0.0)
{

}

//#################################################
// @par Name
// - ElementInfo(int aNum)
// @purpose
// - Overloaded constructor that only sets the Atomic Number
// @param [in] : int aNum
// - Atomic Number that mAtomicNumber will be set to
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
ElementInfo::ElementInfo(int aNum)
    :mAtomicNumber(aNum), mSymbol("N/A"), mName("ONLY ATOMIC NUMBER"), mAtomicWeight(0.0)
{

}

//#################################################
// @par Name
// - ElementInfo(string n)
// @purpose
// - Overloaded constructor that only sets the Element Name
// @param [in] : string n
// - String that mName will be set to
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
ElementInfo::ElementInfo(string n)
    :mAtomicNumber(0), mSymbol("N/A"), mName(n), mAtomicWeight(0.0)
{

}

//#################################################
// @par Name
// - ElementInfo(int aNum, string sym, string n, double aWeight)
// @purpose
// - Overloaded constructor that sets variables to argument passed
// @param [in] : int aNum
// - Value that mAtomicNumber is set to
// @param [in] : string sym
// - Value that mSymbol is set to
// @param [in] : string n
// - Value that mName is set to
// @param [in] : double aWeight
// - Value that mAtomicWeight is set to
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
ElementInfo::ElementInfo(int aNum, string sym, string n, double aWeight)
	:mAtomicNumber(aNum), mSymbol(sym), mName(n), mAtomicWeight(aWeight)
{
	
}

//#################################################
// @par Name
// - getAtomicNum
// @purpose
// - Returns the Atomic Number of the Element
// @param [in] :
// - None
// @return
// - int
// @par References
// - None
// @par Notes
// - None
//#################################################
int ElementInfo::getAtomicNum() const
{
    return this->mAtomicNumber;
}

//#################################################
// @par Name
// - getSymbol
// @purpose
// - Returns the Symbol of the element
// @param [in] :
// - None
// @return
// - string
// @par References
// - None
// @par Notes
// - None
//#################################################
string ElementInfo::getSymbol() const
{
    return this->mSymbol;
}

//#################################################
// @par Name
// - getName
// @purpose
// - Returns the name of the element
// @param [in] :
// - None
// @return
// - string
// @par References
// - None
// @par Notes
// - None
//#################################################
string ElementInfo::getName() const
{
    return this->mName;
}

//#################################################
// @par Name
// - getAtomicWeight
// @purpose
// - Returns the Atomic Weight of the element
// @param [in] :
// - None
// @return
// - double
// @par References
// - None
// @par Notes
// - None
//#################################################
double ElementInfo::getAtomicWeight() const
{
    return this->mAtomicWeight;
}

//#################################################
// @par Name
// - operator<
// @purpose
// - Overloaded operator that is used in the AVL Tree to compare ElementInfo objects
// @param [in] : const ElementInfo &e1
// - ElementInfo object that is on the right hand side of the operator
// @return
// - bool
// @par References
// - None
// @par Notes
// - In doing this, my AVLTree will be sorted by name, rather than Atomic Number.
//#################################################
bool ElementInfo::operator<(const ElementInfo& e1) const
{
    if (this->getName() < e1.getName())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//#################################################
// @par Name
// - operator==
// @purpose
// - Overloaded operator used to compare two ElementInfo objects
// @param [in] : const ElementInfo &e1
// - ElementInfo object on the right hand side of the operator
// @return
// - bool
// @par References
// - None
// @par Notes
// - None
//#################################################
bool ElementInfo::operator==(const ElementInfo& e1) const
{
    if ((this->mAtomicNumber == e1.mAtomicNumber) && (this->mAtomicWeight == e1.mAtomicWeight) && (this->mSymbol == e1.mSymbol) && (this->mName == e1.mName))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//#################################################
// @par Name
// - operator==(const int n)
// @purpose
// - Overloaded operator that compares only the Atomic Number to the argument
// @param [in] : const int n
// - Number the operator is compared to
// @return
// - bool
// @par References
// - None
// @par Notes
// - None
//#################################################
bool ElementInfo::operator==(const int n) const
{
    if (this->mAtomicNumber == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//#################################################
// @par Name
// - operator==(const string s)
// @purpose
// - Overloaded operator that only compares the Element Name to the argument
// @param [in] : const string s
// - String that mName will be compared to
// @return
// - bool
// @par References
// - None
// @par Notes
// - None
//#################################################
bool ElementInfo::operator==(const string s) const
{
    if (this->mName == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}