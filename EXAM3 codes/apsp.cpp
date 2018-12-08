#include <iostream>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {
    int nnodes, src, dst, w;

    cin >> nnodes;

    int adjmat[nnodes][nnodes];

    for (int i = 0; i < nnodes; ++i) {
        for (int j = 0; j < nnodes; ++j) {
            if(i != j) {
                adjmat[i][j] = INF;
            }
            else {
                adjmat[i][j] = 0;
            }
        }
    }

    while (cin >> src) {
        cin >> dst;
        cin >> w;
        adjmat[src][dst] = w;
        adjmat[dst][src] = w;
    }


    for(int k = 0; k < nnodes; ++k) {
        for(int i = 0; i < nnodes; ++i) {
            for(int j = 0; j < nnodes; ++j) {
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
        }
    }

    for(int i  = 0; i < nnodes; ++i) {
        printf("Distances from node %d:\n", i);

        for(int j = 0; j < nnodes; ++j) {
            printf("\tNode %d: %d\n", j, adjmat[i][j]);
        }
    }
}