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

void Union(int x, int y) {

    if(ranks[x] >= ranks[y]) {
        dad_node[y] = x;
        if(ranks[x] == ranks[y]) {
            ranks[x] += 1;
        }
    } else {
        dad_node[x] = y;
    }
}

void kruskal() {

    int x, y, cost = 0;
    for(auto i: edges) {
        x = find(get<1>(i));
        y = find(get<2>(i));

        if(x != y) {
            cost += get<0>(i);
            Union(x,y);
        } 
    }
    cout << cost << endl;
}

int main () {
    int qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    dad_node.resize(qnt_vertex+1);
    ranks.resize(qnt_vertex+1,0);
    int u, v, c;
    for(int i = 0; i < qnt_vertex+1; ++i) {
        dad_node[i] = i;
    }
    for (int i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> c;
        edges.push_back(make_tuple(c,u,v));
    }
    sort(edges.begin(),edges.end());
    kruskal();
    return 0;
}
