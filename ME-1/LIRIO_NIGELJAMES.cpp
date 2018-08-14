#include <iostream>
#include <math.h>
using namespace std;
// Approach taken from https://en.wikipedia.org/wiki/Gray_code#Constructing_an_n-bit_Gray_code
int main()
{
    int n;    
    cin >> n;
    for(int i = 0; i < pow(2, n); i++)
    {
        cout << (i ^ (i/2)) << endl;
    }
    return 0;
}


