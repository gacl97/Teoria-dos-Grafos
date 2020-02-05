#include<bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int>> vp;
typedef vector<vp> vv;
typedef vector<int> v;

vv graph;
v distances;

int Dijkstra() {

    priority_queue<pair<int,int>, vp, greater<pair<int,int>>> pq;
    distances[1] = 0;
    pq.push(make_pair(0,1));
    int head, cost;

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
    int qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    graph.resize(qnt_vertex+1);
    distances.resize(qnt_vertex+1, INT_MAX);
    
    int u, v, c;
    for(int i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v,c));
        graph[v].push_back(make_pair(u,c));
    }
    int total_cost = Dijkstra();
    cout << total_cost << endl;
    return 0;
}