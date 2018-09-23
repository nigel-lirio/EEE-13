
#include <iostream>														// standard library for input/output objects. Stands for "I/O stream"

#include <stdio.h>														// you can still include standard C libraries either using this format or
#include <cstdio>														// this format: (libraryname.h) ---> c(libraryname) to designate that it is a C library

//using namespace std;													// This is needed to be able to use the standard I/O streams (cin and cout, the stream equivalents of stdin and stdout)
																		// if this is not used, you have to preface cin and cout as "std::cin" and "std::cout"
																		// You can read up on namespaces in C++ but it's not needed in basic use, since the std namespace is well enough.

int main(void)															// Also follows the int main(int argc, char *argv[]) of C
{
	using namespace std;
	int input;
	cin >> input;														// since we are using cin, this takes an integer input from stdin/terminal

	cout << "Your input is: " << input;									// outputs the input to the terminal
	cout << endl;
	
	printf("Random output\n");														// endl almost similar to "\n", stands for 'end of the line'
																		// Check this as reference: http://www.cplusplus.com/forum/beginner/7350/

	return 0;															// Similar to C
}
