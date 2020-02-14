#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> v;
typedef vector<v> vv;

vv graph;
v path;
v visited;

// Bfs para percorrer o grafo, salvando o caminho que será usado para obter o gargalo, se realmente houver caminho para o nó final continua com o ford fukerson
bool bfs(lli begin, lli target) {
    
    v queue;
    queue.push_back(begin);
    path[begin] = begin;
    visited[begin] = 1;
    lli head;
    
    while(!queue.empty()) {

        head = queue.front();
        queue.erase(queue.begin());
        
        for(int i = 1; i < graph[head].size(); ++i) {

            if(!visited[i]) {
                if(graph[head][i] != 0) {
                    visited[i] = 1;
                    path[i] = head;
                    queue.push_back(i);
                }
            }
        }
    }
    if(path[target] != -1) {
        return true;
    }
    return false;
}

// Função para pergar o gargalo, o menor fluxo que pode passar no caminho inteiro
void get_path_flow(lli target, lli *path_flow) {

    lli u;
    for(lli v = target; v != 1; v = path[v]) {
        u = path[v];
        if(graph[u][v] < *path_flow) {
            *path_flow = graph[u][v];
        }
    } 
}

// Função para atualizar o grafo, tirando o valor do gargalo na aresta de "ida" e adicionando no resíduo "volta"
void update_graph(lli target, lli path_flow) {
    
    lli u;
    for(lli v = target; v != 1; v = path[v]) {
        u = path[v];
        graph[u][v] -= path_flow;
        graph[v][u] += path_flow;
    }
}

// Rodar o bfs enquanto houver caminho para passar, se não houver, significa que não é possível chegar mais no ultimo nó
lli Ford_Fukerson(lli begin, lli target) {

    lli max_flow = 0;
    while(bfs(1,5)) {
        lli path_flow = 99999999999;
        get_path_flow(target, &path_flow);
        max_flow += path_flow;
        update_graph(target,path_flow);
        path.clear();
        path.resize(graph.size(), -1);
        visited.clear();
        visited.resize(graph.size());
    }
    return max_flow;
}

int main() {
    lli qnt_vertex, qnt_edges;
    cin >> qnt_vertex >> qnt_edges;
    graph.resize(qnt_vertex+1);
    path.resize(qnt_vertex+1,-1);
    visited.resize(qnt_vertex+1,0);

    lli u, v, cost;
    for(int i = 0; i < qnt_edges; ++i) {
        cin >> u >> v >> cost;
        if(graph[u].size() == 0) {
            graph[u].resize(qnt_vertex+1);
            graph[u][u] = 0;
        }
        if(graph[v].size() == 0) {
            graph[v].resize(qnt_vertex+1);
            graph[v][v] = 0;
        }
        graph[u][v] = cost;
        graph[v][u] = 0;
    }   
    print_graph();
    lli max_flow = Ford_Fukerson(1, qnt_vertex);
    cout << "Max flow: " << max_flow << endl;
    return 0;
}
