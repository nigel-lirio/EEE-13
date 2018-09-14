#include <iostream>
#include <climits>
extern int getNBits(int x, int n);
extern int flip_n(int x, int n);
extern int flip_range(int x, int a, int b);
extern int getMSOB(int x);
extern int getMSOB2(int x);
extern int getLSOB(int x);


using namespace std;
int main()
{
	//implement your own test here
	cout << getNBits(13, 3) << endl;
	cout << flip_n(13, 3) << endl;
	cout << flip_range(13,2,5) << endl;
	cout << getMSOB(74) << endl;
	cout << getMSOB2(74) << endl;
	cout << getLSOB(74) << endl;
}