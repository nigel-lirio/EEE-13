#include <iostream> //C++ has several options for Basic I/O
#include <cstdio>

int main()
{
        //Same as C comments
        /*
                Yes, definitely the same as
                C-style comments
        */
        //std::cout is of the data type std::ostream
        //std::cin is of the data type std::istream
        //<< is read from left to right
        //<< indicates output
        //Consequently >> indicates input
        //std::endl is a "more powerful" '\n'
        std::cout << "Hello, world!" << " I am a donut" << std::endl;
        printf("I like donuts\n");
        return 0;
}
