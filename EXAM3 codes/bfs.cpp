#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int> > adjlist;
vector <bool> isvisited;
queue <int> bfsqueue;

int main() {
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

    //Begin BFS
    int s = 0;
    bfsqueue.push(s);
    isvisited[s] = true;

    while(!bfsqueue.empty()) {
        int u = bfsqueue.front();
        bfsqueue.pop();

        printf("%c\n", u + 'A');

        for(auto it = adjlist[u].begin(); it != adjlist[u].end(); ++it) {
            if(!isvisited[*it]) {
                bfsqueue.push(*it);
                isvisited[*it] = true;
            }
        }
    }
    //End BFS
}