#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <vector <int> > adjlist;
vector <bool> isvisited;

void dfs(int nownode) {
    isvisited[nownode] = true;

    for(auto it = adjlist[nownode].begin(); it != adjlist[nownode].end(); ++it) {
        if(!isvisited[*it]) {
            dfs(*it);
        }
    }

    printf("%c\n", nownode + 'A');
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
        adjlist[v].push_back(u);
    }

    dfs(0);

    return 0;
}