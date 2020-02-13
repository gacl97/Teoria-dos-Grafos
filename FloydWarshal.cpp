#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> v;
typedef vector<v> vv;

vv graph;

void Floyd_Warshall(lli qnt_vertex) {

    for(lli i = 1; i <= qnt_vertex; ++i) {
        for(lli j = 1; j <= qnt_vertex; ++j) {
            for(lli k = 1; k <= qnt_vertex; ++k) {

                if(graph[j][i] + graph[i][k] < graph[j][k]) {
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }
    cout << graph[1][qnt_vertex] << endl;
}

int main () {
    lli qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    graph.resize(qnt_vertex+1);
    lli u, v, cost;
    for(lli i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> cost;
        if(graph[u].size() == 0) {
            graph[u].resize(qnt_vertex+1, INT_MAX);
            graph[u][u] = 0;
        }
        if(graph[v].size() == 0) {
            graph[v].resize(qnt_vertex+1, INT_MAX);
            graph[v][v] = 0;
        }
        graph[u][v] = cost;
        graph[v][u] = cost;
    }

    Floyd_Warshall(qnt_vertex);
    return 0;
}