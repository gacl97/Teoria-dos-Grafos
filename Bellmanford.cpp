#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> v;
typedef vector<pair<lli,lli>> vp;
typedef vector<vp> vv;
vv graph;
v distances;

void bellmanFord() {

    distances[1] = 0;
    for(lli j = 0; j < graph.size()-1; ++j) {

        for(lli i = 0; i < graph.size(); ++i) {

            for(auto x: graph[i]) {
                
                if (distances[i] == INT_MAX) { continue; }
                if(distances[i] + x.second < distances[x.first]) {
                    
                    distances[x.first] = distances[i] + x.second;
                }
            }
        }
    }
    cout << distances[graph.size()-1] << endl;
}

int main () {
    lli qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    graph.resize(qnt_vertex+1);
    distances.resize(qnt_vertex+1, INT_MAX);
    lli u, v, cost;
    for (lli i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> cost;
        graph[u].push_back(make_pair(v, cost));
    }
    bellmanFord();
    return 0;
}