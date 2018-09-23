#include <iostream>
#include <string> //required for std::string

int main()
{
        std::cout << "Please enter your first name: ";

        std::string name;
        std::cin >> name;

        std::cout << "Hello, " << name << std::endl;

        std::cin >> name;
        std::cout << " " << name << "!" << std::endl;

        return 0;
}
