// vector.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;  // []; empty
    arr.push_back(3);  // [3]
    arr.push_back(10);  // [3,10]
    arr.push_back(5);  // [3,10,5]
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.pop_back();  // [3,10]
    arr.push_back(7);  // [3,10,7]
    arr.push_back(6);  // [3,10,7,6]
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.clear();  // []; empty
    arr.push_back(1);  // [1]
    arr.push_back(13);  // [1,13]
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.assign(5,7);  // [7,7,7,7,7]; assign 5 elements with value 7
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = vector<int>({5,7,8});  // [5,7,8]; constructing with initializer lists also works
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> other({9,10,12});  // [9,10,12]
    for(int i = 0; i<other.size(); i++){
        cout << other[i] << " ";
    }
    cout << endl;

    return 0;
}