#include <iostream>
#include <stack>
using namespace std;
void span(int *city, int n, int *spans){
  /* ALGORITHM BASED ON:
    https://www.geeksforgeeks.org/the-stock-span-problem/
    https://www.youtube.com/watch?v=1Q94XEp1yfk
  */
  stack<int> cityStack;
  stack<int> cityRevStack;
  //COUNT NUMBER OF PRECEDING VALUES THAT ARE GREATER THAN HEIGHT OF CITY[Z]
  cityStack.push(0); 
  spans[0] = 1;
  for(int z = 1; z < n; z++){
    while(!(cityStack.empty() ) && city[cityStack.top()] <= city[z]){
      cityStack.pop();
    }
    if(cityStack.empty()){
      spans[z] = z+1;
    }
    else{
      spans[z] = z - cityStack.top();
    }
    cityStack.push(z);
  }
  //COUNT NUMBER OF SUCCEEDING VALUES THAT ARE GREATER THAN HEIGHT OF CITY[Z]
  cityRevStack.push(n-1);
  for(int z = n-2; z >= 0; z--){
    while(!(cityRevStack.empty() ) && city[cityRevStack.top()] <= city[z]){
      cityRevStack.pop();
    }
    //FINAL VALUE is NUMBER OF SUCCEEDING VALUES + NUMBER OF PRECEDING VALUES
    if(cityRevStack.empty()){
      spans[z] += (n-1)-z;
    }
    else{
      spans[z] += (cityRevStack.top()-z)-1;
    }
    cityRevStack.push(z);
  }
}
int main(){
  int x;
  cin >> x; 
  int* city = new int[x];
  int* spans = new int[x];
  for(int z = 0; z < x; z++){
    cin >> city[z];
  }
  span(city, x, spans);
  for(int z = 1; z < x-1; z++){
    cout << spans[z] << endl;
  }

  delete spans;
  delete city;
}