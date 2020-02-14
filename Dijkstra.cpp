#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<pair<lli,lli>> vp;
typedef vector<vp> vv;
typedef vector<lli> v;

vv graph;
v distances;

lli Dijkstra() {

    priority_queue<pair<lli,lli>, vp, greater<pair<lli,lli>>> pq;
    distances[1] = 0;
    pq.push(make_pair(0,1));
    lli head, cost;

    while(!pq.empty()) {
        head = pq.top().second;
        cost = pq.top().first;
        pq.pop();

        for(auto x: graph[head]) {

            if(cost + x.second < distances[x.first]) {
                distances[x.first] = cost + x.second;
                pq.push(make_pair(cost + x.second, x.first));
            }
        }
    }

    return distances[graph.size()-1];
}

int main() {
    lli qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    graph.resize(qnt_vertex+1);
    distances.resize(qnt_vertex+1, INT_MAX);
    
    lli u, v, c;
    for(lli i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v,c));
        graph[v].push_back(make_pair(u,c));
    }
    lli total_cost = Dijkstra();
    cout << total_cost << endl;
    return 0;
}