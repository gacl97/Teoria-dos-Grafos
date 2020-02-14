# Teoria-dos-Grafos


Foi feito a implementação de todos os algoritmos visto em sala:
```
* Prim
* Kruskal
* Dijkstra
* Floyd Warshal
* Ford Fukerson
* Bellman Ford
```

Todos os algoritmos foram feitos para "rodar" com a seguinte entrada:
```
N = Quantidade de vértices e M = Quantidade de arestas

As M linhas seguintes são: 

Am = vértice de origem
Bm = vértice de destino 
Cm = custo para essa aresta

N, M 

A B C
....
....
....
Am Bm Cm
```
```
Exemplo de entrada:

5 6

1 2 4

1 3 3

4 3 6

4 5 2

2 4 1

3 5 5
```

Os vértices devem começar de 1 a N, entradas com vértices 0 irá gerar segmentation fault.

Ao rodar o algoritmo, colocar o grafo a ser usado no arquivo "input.txt" que estará junto aos programas.

Para rodar os algoritmos basta utilizar o makefile:

``` make "nome_do_algoritmo" ```

Todos os resultados dos algoritmos de distância são de 1 a N.