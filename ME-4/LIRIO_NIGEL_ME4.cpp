#include <iostream>
#include <array>
#include <vector>
using namespace std;
class Item{
    public:
    int weight;
    int index;
    int basket;
    void print_basket(){
        cout << ++basket << " ";
    }
};
void sort_basket(vector<Item> &temp, int m, int div, vector<Item> &num){
    // BASED ON GREEDY ALGORITHM = https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
    for(int x = 0; div > 0;){        
        if(temp[x].weight <= div){
            div -= temp[x].weight;
            num[temp[x].index].basket =  m;
            temp.erase(temp.begin()+x);
            x = 0;
        }
        else{
            x++;
        }
        
    }
}
int main(){
    int n, m, sum = 0;
    cin >> n;
    vector<Item> num(n);
    for(int x = 0; x < n; x++){
        cin >> num[x].weight;
        sum += num[x].weight;
        num[x].index = x;
    }
    vector<Item> temp(num);
    cin >> m;
    int div = sum/m;
    for(int x = 0; x < m; x++){

        sort_basket(temp, x, div, num);
    }
    for(int x = 0; x < n; x++){
        num[x].print_basket();
    }
    return 0;
}
