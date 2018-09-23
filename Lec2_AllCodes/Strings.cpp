/*
	Complete set of string functions @
	http://www.cplusplus.com/reference/string/string/
*/

#include <iostream>											// Needed for I/O
#include <string>											// Needed for C++ string manipulation
															// Note: C++ strings are *different* from C strings.
															// Main difference is that C strings are basically just null-terminated character arrays
															// Think of C++ Strings as a whole struct containing not only that null terminated character arrays, but with builtin member functions

using namespace std;										// Again, setting the default namespace to the standard one so we can use 'cin, cout, string' instead of 'std::cin, std::cout, std::string'
															// Check the list of Standard C++ Libraries (including C Standard Libraries) at http://www.cplusplus.com/reference/

int main()
{
	string x;												// C++ Strings are dynamic
	string str1 = "ASDASDA";								// You can define a string using constant character pointers;
	string str2("ASDASDA");									// You can do it like this too
	string str3(cstring);									// Or like this
															// The full list of declaring options are at http://www.cplusplus.com/reference/string/string/string/

	cin >> x;												// Same way of inputting a normal integer

	getline(cin, x);										// Inputs everything until the '\n' and stores it into x

	x = x + " APPEND";										// You can append strings to strings using the '+' operator

	char* cstring = x.c_str();								// You can get the C string equivalent of the C++ using the member function c_str();

	if(x == x)												// You can check for equality using the "==" operator
		cout << "Same!" << endl;


	/*
		Useful member functions to note:
		substr()
		compare()
		append()
		length()
	*/

	return 0;

}