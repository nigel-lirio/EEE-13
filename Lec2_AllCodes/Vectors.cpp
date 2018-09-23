// Taken From http://www.cplusplus.com/reference/vector/vector

#include <iostream>
#include <vector>                                   // also known as a dynamic array

#include <algorithm>                                // for the generic sort() function (this is different from the sort() member function of <list>)

using namespace std;

bool Descending(int a, int b)                       // Similar to the comparison function needed in qsort() only that it uses the Boolean class
{                                                   // In comparison to C, the Boolean class has a strict 'true' and 'false'. However, the "zero is true" and "non-zero is false" values can still be used.
  return a > b;
}

int main ()
{
  // constructors used in the same order as described above:
  vector<int> first;                                // empty vector of ints
  vector<int> second (4,100);                       // four ints with value 100
  vector<int> third (second);                       // a copy of second
  vector<string> fourth (3, "ahahhaa");             // four strings with value "ahahhaa"

  // vectors can also be used to construct from arrays/pointers:
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  // also works for iterators
  vector<int> sixth(fifth.begin(), fifth.end());

  // the size() member function returns the number of elements of the vector
  cout << "The size of the vector is: " << fifth.size() << endl;

  // you can add things at the end using the push_back() function. This effectively increases the size by one.
  fifth.push_back(69); 

  // you can also remove things at the back using the pop_back() function. This decreases the size by one.                             
  fifth.pop_back();

  // to sort you need to use the generic sort function included in the <algorithm> standard library.
  // The syntax is (start iterator, end iterator, [comparison function])
  // The default comparison function is the 'less' function (for ascending sorting);
  // You can specify the range using the first to arguments; in this case we are sorting from beginning to the end of the vector
  sort(fifth.begin(), fifth.end());                 

  // We can use our own custom boolean comparison functions.
  sort(sixth.begin(), sixth.end(), Descending);      

  //like lists, you can use iterators to traverse the dynamic array
  cout << "The contents of fifth are:";
  for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  // however, since vectors have indices, we can access them like an array
  cout << "The contents of the sixth are:";
  for(int i = 0; i < sixth.size(); i++)
    cout << ' ' << sixth[i];
  cout << '\n';

  // empties the vector.
  sixth.clear();                                  

  /*
    Other useful member functions in <vectors>
    insert()          -   inserts an element in the middle of the vector. Uses iterators.
    resize()          -   similar to realloc(), resizes the dynamic array, padding/removing elements as needed.
    erase()           -   removes elements from the vector. Uses iterators.
  */
  return 0;
}