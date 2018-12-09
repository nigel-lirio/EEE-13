#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#include <string>
#include <map>
using namespace std;
// GLOBAL VARIABLES
vector<Node> masterList;
list<Node> currentList; //FOR ALLOW AND FORBID REMOVE STRING FROM ITERATION LIST
map<std::string, int> func;
queue<std::string> input_queue;
//CLASSES
class Node{
    int id;
    string word;
    map<int, int> base_cost;
    public:
    Node(std::string, int, int);
    std::string fword();
    int fid();
    bool compare(std::string);
    int fbase_cost(int);
    void node_costs(int);
};
Node::Node(std::string inp, int N, int z){
    this->id = z;
    this->word = inp;
    for(int i =0; i < N; i++){
        if(i != z){
            this->base_cost[i] = 0;
        }
    }
}
//CLASS FUNCTIONS
std::string Node::fword(){
    return this->word;
}
int Node::fid(){
    return this->id;
}
bool Node::compare(std::string A){
    return (this->word == A);
}
int Node::fbase_cost(int A){
    return this->base_cost.find(A)->second;
}
void Node::node_costs(int N){
    for(int a =0; a < N; a++){
        if(a != this->id){
            base_cost[a] = get_base_cost(this->word, masterList[a].fword());
        }
    }
}
//FUNCTIONS

int get_base_cost(std::string A, std::string B){

}/*
int get_total_cost(std::string A, std::string B){

}*/
void start(int Q){
    for(int i = 0; i < Q; i++){
        //MakeGraph(currentList);
    }
}
int main(){
    int N, Q, i;
    func["COST"] = 0;
    func["ALLOW"] = 1;
    func["FORBID"] = 2;
    cin >> N;
    cin >> Q;
    masterList.reserve(N);
    string input;
    for(i = 0; i < N; i++){
         cin >> input;
         Node temp(input, N, i);
         masterList.push_back(temp);
         currentList.push_back(temp);
    }
    for(i = 0; i < Q; i++){
        //GET OPERATIONS
        cin >> input;
        input_queue.push(input);
        if(func.find(input)->second == 0){
            for(int z = 0; z < 2; z++){
                cin >> input;
                input_queue.push(input);
            }
        }
        else{
            cin >> input;
            input_queue.push(input);
        }
    }
    while(!input_queue.empty()){
        input = input_queue.front();
        cout << input << endl;
        input_queue.pop();
    }
}