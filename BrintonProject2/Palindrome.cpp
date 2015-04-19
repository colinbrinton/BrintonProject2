
/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: **Solution/Project Name**  (Ex: Project1)
 *             File Name: **ThisFileName**.cpp       (Ex: payrate.cpp)
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: **Your Name**
 *
 * Assigned Project Number: **See Syllabus, for example: 2A**
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     MM/DD/YYYY  Initial Release
 *   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard  ** Describe any inputs from the User; otherwise, None **
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   ** Describe any Console display; otherwise, None **
 *
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * main          Program entry point method
 * **** Add name and description of any other methods defined in this file ****
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <string>    // Needed to use strings

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** For method main(), describe the application program from the client's
* ** perspective, which includes any User inputs required and expected
* ** Console output, and any other pertinent information about the program.
* ** For other methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*
* Pre-Conditions
* --------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  --------------------------------------------------------------
*
*******************************************************************************
*/

class Pstring : public string
{
private:
	string palindrome;
public:
	Pstring()
	{
		palindrome = "";
	}
	Pstring(string palindrome) : string(palindrome) { }

	bool isPalindrome()
	{
		const int ONE = 1;
		const int TWO = 2;

		string testPalindrome = "";
		string compare1 = "";
		string compare2 = "";

		getline(cin, palindrome); //Remove
		int length = palindrome.length();
		//testPalindrome.resize(length);
		for (int count = NULL; count < length; count++)
		{
			if (isalpha(this->palindrome[count]))
			{
				char temp;
				temp = this->palindrome[count];
				testPalindrome.push_back(temp);
			}
		}

		length = testPalindrome.length();
		for (int count = NULL; count < length; count++)
			testPalindrome[count] = tolower(testPalindrome[count]);

		if (length % TWO != NULL)
		{
			int half = (length - ONE) / TWO;

			compare1.resize(half);
			compare2.resize(half);

			for (int count = NULL; count < half; count++)
				compare1[count] = testPalindrome[count];
			/*for (int count = half; count < half; count++)
				compare2[count] = testPalindrome[count];*/

			int index = 0;
			for (int count = (length - ONE); count > half; count--)
			{
				compare2[index] = testPalindrome[count];
				++index;
			}
		}
		else
		{
			int half = (length / TWO);

			compare1.resize(half);
			compare2.resize(half);

			for (int count = NULL; count < half; count++)
				compare1[count] = testPalindrome[count];
			/*for (int count = half; count < half; count++)
			compare2[count] = testPalindrome[count];*/

			int index = 0;
			for (int count = (length - ONE); count >= half; count--)
			{
				compare2[index] = testPalindrome[count];
				++index;
			}

		}

		cout << testPalindrome; //Remove
		cout << endl << compare1;
		cout << endl << compare2;

		if (compare2 == compare1)
			return true;
		else
			return false;
	}
};

 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;

	 

	// !! Insert your code here (remove this comment line) !!

	 Pstring test;

	 if (test.isPalindrome())
		 cout << endl << "YES!";
	 else
		 cout << endl << "nope...";

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

