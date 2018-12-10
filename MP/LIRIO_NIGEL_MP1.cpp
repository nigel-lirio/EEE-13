#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
using namespace std;
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
    void node_costs(int, int);
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
void Node::node_costs(int node, int cost){
    this->base_cost[node] = cost;
}
// GLOBAL VARIABLES
vector<Node> masterList;
vector<Node> currentList; //FOR ALLOW AND FORBID REMOVE STRING FROM ITERATION LIST
map<std::string, int> func;
queue<std::string> input_queue;
vector<std::vector<int> > adjMatrix;
//FUNCTIONS
int get_base_cost(std::string A, std::string B){
    //Algorithm based on https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
    int length = A.length();
    int VAL[length+1][length + 1];
    for(int i = 0; i <= length; i++){
      for(int j = 0; j <= length; j++){
        if(i == 0 || j == 0){
          VAL[i][j] = 0;
        }
        else if(A[i-1] == B[j-1]){
          VAL[i][j] = VAL[i-1][j-1] + 1;
        }
        else{
          VAL[i][j] = max(VAL[i-1][j], VAL[i][j-1]);
        }
      }
    }
  int dis = (length - VAL[length][length]) * 2;
  return (dis * dis);
}
void fill_costs(int N){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(masterList[i].fid() != j){
        masterList[i].node_costs(j, get_base_cost(masterList[i].fword(), masterList[j].fword()));
      }
    }
  }
}

void MakeGraph(){
    int current_elements = currentList.size(), i, j, k;
    adjMatrix.clear();
    adjMatrix.resize(current_elements);
    for(i=0; i < current_elements; i++){
        adjMatrix[i].resize(current_elements);
        for(j = 0; j < current_elements; j++){
            if(i == j){
                adjMatrix[i].push_back(0);
            }
            else{
                adjMatrix[i][j] = currentList[i].fbase_cost(currentList[j].fid());
            }
        }
    }
    /*for(i=0; i < current_elements; i++){
        cout << i << ": ";
        for(j = 0; j < current_elements; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }*/
    for(k = 0; k < current_elements; k++){
        for(i = 0; i < current_elements; i++){
            for(j = 0; j < current_elements; j++){
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }
}
void remove_node(std::string A){
    int current_elements = currentList.size();
    for(int i = 0; i < current_elements; i++){
        if(A == currentList[i].fword()){
            currentList.erase(currentList.begin()+i);
            break;
        }
    }
}
void add_node(std::string A){
    int total_elements = masterList.size();
    for(int i = 0; i < total_elements; i++){
        if(A == masterList[i].fword()){
            currentList.push_back(masterList[i]);
            break;
        }
    }
}
int get_total_cost(std::string A, std::string B){
    int current_elements = currentList.size(), x, y;
    for(int i = 0; i < current_elements; i++){
        if(A == currentList[i].fword()){
            x = i;
        }
        else if(B == currentList[i].fword()){
            y = i;
        }
    }
    return adjMatrix[x][y];
}
void start(int Q){
    MakeGraph();
    array<std::string, 2> inputq;
    string inp;
    int i, k;
    for(i = 0; i < Q; i++){
        inp = input_queue.front();
        input_queue.pop();
        switch(func.find(inp)->second){
            case 0:
                for(k = 0; k < 2; k++){
                    inp = input_queue.front();
                    inputq[k] = inp;
                    input_queue.pop();
                }
                cout << get_total_cost(inputq[0], inputq[1]) << endl;
                break;
            case 1:
                inp = input_queue.front();
                input_queue.pop();
                add_node(inp);
                MakeGraph();
                break;
            case 2:
                inp = input_queue.front();
                input_queue.pop();
                remove_node(inp);
                MakeGraph();
                break;
        }
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
    }
    fill_costs(N);
    currentList = masterList;
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
    start(Q);
}