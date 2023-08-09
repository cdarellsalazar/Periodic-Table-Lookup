//################################################## 
// File: main.cpp
// Author: Christian Salazar
// Description: This is where the Element Lookup class is tested
// Date: 12/8/2022
//##################################################

#include <iostream>
#include "ElementInfo.h"
#include "ElementLookup.h"
#include "ElementLookupException.h"

using namespace std;

char displayMenu();

int main()
{
	ElementLookup el;

	el.readFile("periodicTable.csv");

	char answer;
	char selection;
	cout << "Welcome to the Periodic Table Lookup!" << endl;
	answer = displayMenu();

	while (answer != '3')
	{
		switch (answer)
		{
		case '1':
		{
			int num;
			cout << endl;
			cout << "Please enter the Atomic Number of the desired element: " << endl;
			cin >> num;
			try
			{
				cout << el.lookup(num) << endl;
			}
			catch (ElementLookupException ce)
			{
				cout << ce.what() << endl;
			}
			catch (...)
			{
				cout << "ERROR: Unknown Error." << endl;
			}
			
			cout << "Would you like to look up another element by Atomic Number? Y/N" << endl;
 			cin >> selection;

			if (toupper(selection) == 'Y')
			{
				break;
			}
			else if (toupper(selection) == 'N')
			{
				answer = displayMenu();
				break;
			}
			else
			{
				cout << "ERROR: Value entered was not Y or N. Returning to main menu." << endl;
				answer = displayMenu();
				break;
			}

		}
		case '2':
		{
			string name;
			cout << endl;
			cout << "Please enter the name of the desired element: " << endl;
			cin >> name;
			cout << el.lookup(name) << endl;
			
			cout << "Would you like to look up another element by name? Y/N" << endl;
			cin >> selection;

			if (toupper(selection) == 'Y')
			{
				break;
			}
			else if (toupper(selection) == 'N')
			{
				answer = displayMenu();
				break;
			}
			else
			{
				cout << "ERROR: Value entered was not Y or N. Returning to main menu." << endl;
				answer = displayMenu();
				break;
			}
		}
		case '3':
		{
			break;
		}
		default:
		{
			cout << "ERROR: Please enter a number from 1 to 3." << endl;
			answer = displayMenu();
		}
		}
	}

	cout << "Have a great day!" << endl;

	return 0;
}

//#################################################
// @par Name
// - displayMenu
// @purpose
// - Displays the menu options to the console and gets user's input
// @param [in] :
// - None
// @return
// - char
// @par References
// - None
// @par Notes
// - None
//#################################################
char displayMenu()
{
	char answer;
	cout << "Lookup Element By: " << endl;
	cout << "1. Atomic Number" << endl;
	cout << "2. Name" << endl;
	cout << "3. Quit" << endl;
	cout << "Please make a selection..." << endl;
	cin >> answer;
	return answer;
}
