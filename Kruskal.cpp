#include<bits/stdc++.h>

using namespace std;

typedef vector<tuple<int,int,int>> vt;
typedef vector<int> v;

v dad_node, ranks;
vt edges;

int find(int x) {

    if(x == dad_node[x]) {
        return x;
    }
    return  dad_node[x] = find(dad_node[x]);
}

void Union(tuple<int,int,int> i) {

    int x = find(get<1>(i));
    int y = find(get<2>(i));

    if(ranks[x] >= ranks[y]) {
        dad_node[y] = x;
        if(ranks[x] == ranks[y]) {
            ranks[x] += 1;
        }
    } else {
        ranks[x] = y;
    }
}

void kruskal() {

    int cost = 0;
    for(auto i: edges) {
        cost += get<0>(i);
        Union(i); 
    }
    cout << cost << endl;
}

int main () {
    int qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    dad_node.resize(qnt_vertex+1);
    ranks.resize(qnt_vertex+1);
    int u, v, c;
    for (int i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> c;
        edges.push_back(make_tuple(c,u,v));
        edges.push_back(make_tuple(c,v,u));
    }
    sort(edges.begin(),edges.end());
    kruskal();
    return 0;
}