#include <iostream>
#include <string>

int main()
{
        using namespace std;
        cout << "Please enter your first name: ";
        string name;
        cin >> name;

        const string greeting = "Hello, " + name + "!";

        const string spaces(greeting.size(), ' ');
        const string second = "* " + spaces + " *";

        const string first(second.size(), '*');

        cout << endl;
        cout << first << endl;
        cout << second << endl;
        cout << "* " << greeting << " *" << endl;
        cout << second << endl;
        cout << first << endl;

        return 0;
}
