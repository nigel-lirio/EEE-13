#include <iostream>
#include <math.h>
using namespace std;
/* Approach taken from https://en.wikipedia.org/wiki/Gray_code#Constructing_an_n-bit_Gray_code
 nth grey code can be obtained by: XORing Nth term with the floor of itself divided by 2 OR shifted to the right by one */
int main()
{
    int n;    
    cin >> n;
    
    for(int bit = 0; bit < pow(2, n); bit++){
        cout << (bit ^ (bit >> 1)) << endl;
    }
    return 0;
}


