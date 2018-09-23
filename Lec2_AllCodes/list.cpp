// list.cpp
#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> l;  // []; empty

    l.push_back(3);  // [3]
    l.push_back(5);  // [3,5]
    l.push_back(4);  // [3,5,4]
    l.push_front(6);  // [6,3,5,4]
    l.push_back(7);  // [6,3,5,4,7]
    l.push_back(8);  // [6,3,5,4,7,8]

    for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    list<int>::iterator it = l.begin(); // [<6>,3,5,4,7,8]
    cout << *it << endl;  // 6 

    it++;  // [6,<3>,5,4,7,8]
    cout << *it << endl;  // 3

    advance(it,3);  // [6,3,5,4,<7>,8]; Pretty much it += 3, or it++ repeatedly. Like mentioned, traversal of iterators takes O(n).
    cout << *it << endl;  // 7

    l.insert(it,12);  // [6,3,5,4,12,<7>,8]
    l.insert(it,15);  // [6,3,5,4,12,15,<7>,8]
    for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    cout << "it still points to " << *it << endl;  // 7

    advance(it, -4);  // [6,3,<5>,4,12,15,7,8]
    cout << "it now points to " << *it << endl;  // 5

    it = l.erase(it);  // [6,3,<4>,12,15,7,8] returns the element after the deleted one
    cout << "it now points to " << *it << endl;  // 4

    for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    *it = 99;  // [6,3,<99>,12,15,7,8]

    for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}