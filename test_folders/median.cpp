#include <iostream>
#include <queue>
using namespace std;
//Algorithm from Joie Llantero
void median(double *arr, int n){
    //Priority Queue allows elements to be prioritized at pop
    //Two queues are initialized: the max and min heap
    priority_queue<double> maxh; 
    // priority queue is default max heap stored in stl
    //stores the upper half elements
    priority_queue<double,vector<double>,greater<double> > minh; 
    //making it to min heap in stl
    //Initialize default median
    double med = arr[0];
    maxh.push(arr[0]); 
    // Array of elements are traveresed until all elements are stored in either heaps.
    // Algorithm below segregates elements into the max/min heap and balances them.
    for (int i=1; i < n; i++) 
    { 
        double x = arr[i]; 
        // If max heap has more elements
        if (maxh.size() > minh.size()) 
        { 
            //if the element is less than the median then push on to the maxheap else put in min heap
            if (x < med){
                minh.push(maxh.top()); 
                maxh.pop();
                maxh.push(x);
                //balances heap by moving biggest element in max heap in min heap  
            } 
            else
            {
                minh.push(x);
            }
            med = (maxh.top() + minh.top())/2.0; 
            //median adds biggest element in max and smallest element in min heap
        } 
        // When both heaps have the same number of elements
        else if (maxh.size()==minh.size()) 
        { 
            //Median is greatest of max heap or lowest of min heap
            if (x < med) 
            { 
                maxh.push(x);
                med = (double)maxh.top(); 
            } 
            else
            { 
                minh.push(x); 
                med = (double)minh.top(); 
            } 
            //Results in unbalanced heaps
        } 
  
        //Min heap has more elements
        else
        {
            //smallest of min heap is moved to max heap 
            if (x > med) 
            { 
                maxh.push(minh.top()); 
                minh.pop(); 
                minh.push(x); 
            } 
            else
            {
                maxh.push(x); 
            }
  
            med = (maxh.top() + minh.top())/2.0; 
        } 
    } 
    //end of loop signifies that all elements are in the heap
    cout << med << endl;
}

int main(){
    double arr[] = {5, 15, 10, 20, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    median(arr, n); 
    return 0; 
}