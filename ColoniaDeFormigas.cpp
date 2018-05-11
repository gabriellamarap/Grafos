#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Graph.cpp"

using namespace std;

int main () {

  int N, //qt de formigueiros
      A, //formigueiro
      L, //comprimento do tunel
      Q, //num de consultas
      S, //formigueiro de origem
      T, //formigueiro de destino
      min;

    cin >> N;

    while(N != 0) {

        Graph graph(N);

        for(int i = 1; i <= N - 1; i++) {
            cin >> A;
            cin >> L;
            graph.addEdge(i, A, L); // Insere aresta em v(i) - v(A), de peso L
        }

        cin >> Q;

        for(int i = 0; i < Q; i++) {
            cin >> S;
            cin >> T;
            min = graph.dfs(S, T);
            cout << min << ' ';
        }
        cout << '\n';
        cin >> N;
    }

    return 0;
}