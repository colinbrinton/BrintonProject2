
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
*								 and lowercase letters, numbers, spaces and symbols. Returns 
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
	Pstring(const string palindrome) : string(palindrome)    //Use string base constructor
	{
		this->palindrome = palindrome;
	}

	// 2. Class Destructor
	~Pstring() = default;

	// 3. Observer Methods
	bool isPalindrome() const
	{
		// Initialize strings for processing and comparison
		string testPalindrome = "";
		string compare1 = "";
		string compare2 = "";

		// Input validation (input also validated in main()
		//    this should never be seen in this program)
		if (palindrome.empty())
		{
			cout << "Error: No input received.";
			return false;
		}

		// Find the length of the string entered
		int length = palindrome.length();

		// Scan through the full string
		for (int count = NULL; count < length; count++)
		{
			// Check to see if current element is alphanumerical
			//		with goal of distiling text down to only letters
			//      with no spaces (numbers ok)
			if (isalnum(this->palindrome[count]))
			{
				// If element is alphanumerical store in testPalindrome
				char temp;
				temp = this->palindrome[count];
				testPalindrome.push_back(temp);
			}
		}

		//Find the length of the processed text
		length = testPalindrome.length();

		//Make all charecters lowercase
		for (int count = NULL; count < length; count++)
			testPalindrome[count] = tolower(testPalindrome[count]);

		//If the string is an odd number, the middle element may be ignored
		if (length % TWO != NULL)
		{
			//Half of the total length excluding middle element
			int half = (length - ONE) / TWO;

			//Set the size for the two comparison strings
			compare1.resize(half);
			compare2.resize(half);

			//Store the first half of the charecters in compare1
			for (int count = NULL; count < half; count++)
				compare1[count] = testPalindrome[count];

			//Store the second half of the charecters in reverse order in compare2
			int index = NULL;
			for (int count = (length - ONE); count > half; count--)
			{
				compare2[index] = testPalindrome[count];
				++index;
			}
		}

		//String is an even number, length may be evenly divided
		else
		{
			//Find length for half the elements
			int half = (length / TWO);

			//Set the size of the comparision strings
			compare1.resize(half);
			compare2.resize(half);

			//Store first half of charecters in compare1
			for (int count = NULL; count < half; count++)
				compare1[count] = testPalindrome[count];

			//Store the second half of the charecters in reverse order in compare2
			int index = NULL;
			for (int count = (length - ONE); count >= half; count--)
			{
				compare2[index] = testPalindrome[count];
				++index;
			}

		}

		//Display the content of the strings used in the algorithm.
		//For demonstration purposes only, comment out if class is used for
		//another application.
		cout << endl << "Processed text               :  " << testPalindrome;
		cout << endl << "First half of text           :  " << compare1;
		cout << endl << "Second half of text reversed :  " << compare2 << endl;

		//Compare the first half of the charecters to the revered second half
		if (compare2 == compare1)
			return true;   //If they match return true, the inputted text is a palindrome
		else
			return false;  //If they do not match, the inputted text is not a palindrome
	} // End of method
}; //End of class

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* Program opens with a description of its functionality. Prompt is displayed to
* enter a word or phrase to be tested. Input is validated to ensure something was
* entered. If nothing is entered, reprompt. Program creates a Pstring object and 
* tests object with isPalindrome() member function. Displays results of test.
* User is prompted to repeat the program. Display exit text if no repeat is triggered.
*
* Pre-Conditions
* --------------
* None
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
*     Name                               Description
* ------------    --------------------------------------------------------------
* isPalindrome()   Member function of Pstring class.
*				   Determins if string is palindrome, will process uppercase
*				   and lowercase letters, numbers, spaces and symbols. Returns 
*				   true or false. Displays intermediate steps used in algorithm
*				   (console output may be commented out for use in other applications)
*
*******************************************************************************
*/

 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;

	 // Declare char variable to be used for repeat program prompt
	 char repeat;

	 // Program description
	 cout << "This program determines if a word or phrase is a palindrome." << endl;

	 //Outer do-while loop so that the user may test additional palindromes
	 do{
		 //Prompt to enter text
		 cout << "Please enter a word or phrase that you would like to have tested:" << endl;

		 //Store text in string
		 string palindrome;
		 getline(cin, palindrome);

		 //Input validation and reprompt
		 while (palindrome.empty())
		 {
			 cout << "Nothing was entered..." << endl;
			 cout << "Please enter a word or phrase that you would like to have tested:" << endl;
			 getline(cin, palindrome);
		 }

		 //Create Pstring object initialized with input string
		 Pstring test(palindrome);

		 //Using isPalindrome() return value, display one of two results
		 if (test.isPalindrome())
			 cout << endl << "Result: Your word or phrase is a palindrome!" << endl << endl;
		 else
			 cout << endl << "Result: No palindrome detected." << endl << endl;

		 //Prompt to restart process
		 cout << "Would you like to test another word or phrase? (Y/N) " << endl;
		 cin >> repeat;
		 cin.ignore(); //Needed to avoid automatically entering '/0' in next iteration

		 //Formatting
		 if ((repeat == 'Y') || (repeat == 'y'))
			 cout << endl;

	 } while ((repeat == 'Y' )|| (repeat == 'y')); //Test user response

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

