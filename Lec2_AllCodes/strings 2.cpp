// strings.cpp
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "cat";
    cout << str << endl;

    string other = "dog";

    cout << str << " some text " << other << endl;

    string str3 = str + " and " + other;  // "cat and dog"
    cout << str3 << endl;

    string sample = "My sampl";
    // Use push_back for characters
    sample.push_back('e');  // "My sample"
    cout << sample << endl;

    sample.append(" text.");  // "My sample text."
    cout << sample << endl;

    // We can just use operators!
    sample = sample + " And ";  // "My sample text. And "
    sample += "more.";  // "My sample text. And more."
    cout << sample << endl;

    string sub = sample.substr(14, 9);  // ". And mor"; Staring at index 14, get 9 characters
    cout << sub << endl;

    cout << str + sample.substr(14) << endl;  // "cat. And more."; If we only include the index, substr will include till the end of the string

    for(int i = 0; str[i]; i++){  // Just like in C
        cout << str[i];
    }
    cout << endl;

    for(int i = 0; i<str.size(); i++){  // Similar to strlen in C
        cout << str[i];
    }
    cout << endl;

    return 0;
}