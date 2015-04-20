
/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: Project2
 *             File Name: Palindrome.cpp 
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Colin Brinton
 *
 * Assigned Project Number: 2
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     04/19/2015  Initial Release
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard  User enters a word or phrase to be tested
 *		     User enters Y/N to repeat the program or end
 *			 User presses enter to exit program
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   Program description
 *			 Prompt to enter text to be tested
 *			 Processed text, and comparison texts displayed
 *			 Result of test displayed
 *			 Prompt to repeat program
 *           Prompt to exit program
 *			 
 *
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * main          Program entry point method
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
*       Class: Pstring   
*  Base Class: string  
*
* Programmer: Colin Brinton
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/19/2015  Initial Release

* Class Description
* -----------------
* This class accepts a user inputed string of any combination of letters, numbers, spaces
* and symbols or punctuation. The primary use for this class is calling the method isPalindrome()
* which tests the string to determine if it is a palindrome.
*
*
* ----------------------------- Public Interface ------------------------------
*      Method							         Description
* ----------------		 -----------------------------------------------------------
*  Pstring()					 Default Constructor
* ~Pstring()					 Class Destructor
* Pstring(string const)			 Constructor accepting input string, utilizes string's
*									base constructor
* bool isPalindrome() const		 Determins if string is palindrome, will process uppercase
*								 and lowercase letters, numbers, spaces and symbols returns 
*								 true or false. Displays intermediate steps used in algorithm
*								 (console output may be commented out for use in other applications)
*
*
*
* ------------------------------ Private Methods ------------------------------
*       Name                               Description
* ----------------  -----------------------------------------------------------
*                           *** No private methods ***
*
*
* --------------------------- Private Data Members ----------------------------
*               Data
*    Type       Type       Name                    Description
* ---------- --------- ------------ -------------------------------------------
* non-static  string    palindrome	string to hold user inputed string
*
*
* ------------------  Public "static const" Data Members ----------------------
*   Data
*   Type         Name                         Description
* --------  --------------  ---------------------------------------------------
*                       *** No public data members ***
*
*******************************************************************************
*/

class Pstring : public string
{
private:

	// 1. Non-static (instance) Variable Declarations
	string palindrome;

	// 2. Static Constant Value Declarations
	const int ONE = 1;
	const int TWO = 2;

public:
	// 1. Constructors
	//    A. Default Constructor
	Pstring()
	{
		palindrome = "";
	}

	//    B. Initializing Constructors
	Pstring(const string palindrome) : string(palindrome)
	{
		this->palindrome = palindrome;
	}

	// 2. Class Destructor
	~Pstring() = default;

	// 3. Observer Methods
	bool isPalindrome() const
	{
		string testPalindrome = "";
		string compare1 = "";
		string compare2 = "";

		if (palindrome.empty())
		{
			cout << "Error: No input received.";
			return false;
		}
		int length = palindrome.length();
		for (int count = NULL; count < length; count++)
		{
			if (isalnum(this->palindrome[count]))
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

			int index = NULL;
			for (int count = (length - ONE); count >= half; count--)
			{
				compare2[index] = testPalindrome[count];
				++index;
			}

		}

		cout << endl << "Processed text               :  " << testPalindrome;
		cout << endl << "First half of text           :  " << compare1;
		cout << endl << "Second half of text reversed :  " << compare2 << endl;

		if (compare2 == compare1)
			return true;
		else
			return false;
	}
};

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

 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;

	 char repeat;
	 cout << "This program determines if a word or phrase is a palindrome." << endl;
	 do{
		 cout << "Please enter a word or phrase that you would like to have tested:" << endl;
		 string palindrome;
		 getline(cin, palindrome);
		 while (palindrome.empty())
		 {
			 cout << "Nothing was entered..." << endl;
			 cout << "Please enter a word or phrase that you would like to have tested:" << endl;
			 getline(cin, palindrome);
		 }
		 Pstring test(palindrome);

		 if (test.isPalindrome())
			 cout << endl << "Result: Your word or phrase is a palindrome!" << endl << endl;
		 else
			 cout << endl << "Result: No palindrome detected." << endl << endl;

		 cout << "Would you like to test another word or phrase? (Y/N) " << endl;
		 cin >> repeat;
		 cin.ignore();
		 if ((repeat == 'Y') || (repeat == 'y'))
			 cout << endl;

	 } while ((repeat == 'Y' )|| (repeat == 'y'));

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

