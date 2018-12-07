#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std; 
class Obj{
    public:
    int weight;
    int value;
};
//Classic Knapsack algorithm as discussed
int knapS(vector<Obj> &objs, int x, int capacity){
    if(x == 0 || capacity == 0){
        return 0;
    }
    if(objs[x-1].weight > capacity){
        return knapS(objs,x-1,capacity);
    }
    else{
        return max((objs[x-1].value + knapS(objs, x-1, (capacity-objs[x-1].weight))), knapS(objs, x-1, capacity));
    }
}    
int main()
{
    int x, maxW;
    cin >> x; 
    vector<Obj> objectList;
    int val,wei,z;
    //Objects are constructed individually
    for(int j = 0; j < x; j++){
        cin >> val;
        cin >> wei;
        cin >> z;
        //constructs object z times
        for(int y = 0; y < z; y++){
            Obj oA;
            oA.value = val;
            oA.weight = wei;
            objectList.push_back(oA);
        }
    }
    cin >> maxW;
    int n = objectList.size();
    //Use classic algorithm on expanded objects list
    cout << knapS(objectList, n, maxW) << endl;
    return 0;
}
