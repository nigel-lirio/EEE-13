// vector_cpp11.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> arr({"cat", "dog", "giraffe"});

    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for(auto itr = arr.begin(); itr!=arr.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}