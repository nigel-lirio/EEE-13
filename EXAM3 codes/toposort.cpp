#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

vector <vector <int> > adjlist;
vector <bool> isvisited;
stack <int> toposorted;

void dfs(int nownode) {
    isvisited[nownode] = true;

    for(auto it = adjlist[nownode].begin(); it != adjlist[nownode].end(); ++it) {
        if(!isvisited[*it]) {
            dfs(*it);
        }
    }

    toposorted.push(nownode);
}

int main(void) {
    int nnodes, nedges;

    cin >> nnodes >> nedges;

    adjlist.resize(nnodes + 5);
    isvisited.resize(nnodes + 5, false);

    for(int i = 0; i < nedges; ++i) {
        int u, v;

        cin >> u >> v;

        adjlist[u].push_back(v);
    }

    //This is needed if you have multiple source nodes
    //What if there are nodes that do not have incoming edges?
    //e.g: Math 17, ES 1
    for(int i = 0; i < nnodes; ++i) {
        if(!isvisited[i]) {
            dfs(i);
        }
    }

    while(!toposorted.empty()) {
        int u = toposorted.top();
        toposorted.pop();

        printf("%c\n", u + 'A');
    }

    return 0;
}