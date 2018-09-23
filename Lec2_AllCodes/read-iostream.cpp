#include <iostream>
#include <string>

using namespace std;

int main(){
    int num1, num2;
    char c1, c2;
    string str1, str2;  // Needs <string> for the string class.
    double d1, d2;

    // Cin can scan things into primitive types (int, char, double) as well as string classes, but is slower than scanf.
    while(cin >> num1 >> num2 >> c1 >> c2 >> d1 >> d2 >> str1 >> str2){
        cout << "Read " << num1 << " " << num2 << " " << c1 << " " << c2 << " " << d1 << " " << d2 << " " << str1 << " " << str2 << endl;
    }
    return 0;
}