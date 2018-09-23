// Taken From http://www.cplusplus.com/reference/list/list/

#include <iostream>
#include <list>

using namespace std;

bool Compare(int a, int b)                        // Similar to the comparison function needed in qsort() only that it uses the Boolean class
{                                                 // In comparison to C, the Boolean class has a strict 'true' and 'false'. However, the "zero is true" and "non-zero is false" values can still be used.
  return a < b;
}

int main ()
{
  list<int> first;                                // empty list of ints
  list<int> second (4,100);                       // four ints with value 100
  list<int> third (second);                       // a copy of second
  list<string> fifth(4, "hahaha");                // a list of four strings, each containing "hahaha"

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  list<int> fourth (myints, myints + sizeof(myints) / sizeof(int));

  cout << "The contents of fourth are " << fourth.size() << ":\n";                // You can access the size of the list using the size() member function

  cout << "The front is " << fourth.front() << endl;                              // You can access both ends of the list using these functions.

  cout << "The back is " << fourth.back()++ << endl;                              // You can directly edit the values using these functions

  fourth.push_front(20);                                                          // You can insert to both ends using this function
  fourth.push_back(35);

  fourth.pop_front();                                                              // Similarly you can remove both ends using this function
  fourth.pop_back();

  fourth.sort(Compare);                                                           // You can sort it by adding a bool function that returns true if the 'left hand argument' should be placed before than the 'right hand argument';
                                                                                  // in this case the sort is by ascending.

  for (list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)         // Since a linked list does not have an index like a normal array, it needs an object that will traverse the list
    cout << *it << ' ';                                                           // The begin() and end() functions are simply markpoints for the iterator. begin() refers to the point at the start of the list, end() refers to the end of the list (after the last element)
                                                                                  // The iterator object does that, and acts like a pointer.

  cout << '\n';

  fourth.clear();                                                                 // empties the list

  /*
    Other useful functions:
      insert()          -   inserts an element in the middle of the list. Uses iterators.
      splice()          -   inserts elements from another list into the middle of the list. Uses iterators.
      erase()           -   removes element/s from the list. Uses iterators
      resize()          -   changes the current capacity of the list.
  */

  return 0;
}