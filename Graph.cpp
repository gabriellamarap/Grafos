#include <iostream>
#include <list>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

class Graph {

private:
    int numVertex;
    int **adj;
    bool *visited;

public:
    Graph(int numVertex);
    ~Graph();
    void addEdge(int origin, int destin, int weight);
    int delEdge(int origin, int destin);
    int getEdge(int origin, int destin);
    void display();
    void print();
    bool isConnected(int origin, int destin);
    bool emptyMat(int v);
    int getNumVertex();
    int dfs(int origin, int destin);
    int dfs(int origin, int destin, int prev);
    void dfsT(int node);
    void bfsT(int node);

};

/**
 * Construtor
 */
Graph::Graph(int numVertex) {

    this->numVertex = numVertex;

    visited = new bool [numVertex]; // Criando um array de bool [visitado = true || não visitado = false]

    // Alocando memória para a matriz de adjacência
    adj = new int* [numVertex];
    for (int i = 0; i < numVertex; i++) {
        adj[i] = new int [numVertex];
        for(int j = 0; j < numVertex; j++) {
            adj[i][j] = 0; // Inicializando todas as posições com 0
        }
    }
}

/**
 * Destrutor
 */
Graph::~Graph() {
  for (int i = 0; i < this->numVertex; i++) {
    delete [] this->adj[i];
  }
  delete [] this->adj;
}

/**
 * Retorna o número de vértices do Grafo
 */
int Graph::getNumVertex() {
    return this->numVertex;
}

/**
 * Adiciona uma aresta do vértice "origin" até o "destin", de peso "weight"
 */
void Graph::addEdge(int origin, int destin, int weight) {

    // Verifica se os vértices são válidos
    if( origin > this->numVertex || destin > this->numVertex || origin < 0 || destin < 0) {
        cout << "Invalid edge!\n";
    }
    else {
        adj[origin][destin] = weight; // Adiciona o "destin" como adjacente de "origin"
        adj[destin][origin] = weight; // Adiciona o "origin" como adjacente de "destin"
    }
}

/**
 * Verifica se dois vértices estão conectados
 */
bool Graph::isConnected(int origin, int destin) {
    return (this->adj[origin][destin] > 0);
}

/**
 * Deleta uma aresta que conecta o vértice "origin" ao "destin" e retorna seu peso ou 0 (caso não exista)
 */
int Graph::delEdge(int origin, int destin) {

    int wei = this->adj[origin][destin];

    // Verifica se a aresta existe
    if(wei > 0) {
        this->adj[origin][destin] = this->adj[destin][origin] = 0; // Seta o valor da aresta como 0 (apaga)
        return wei;
    }
    else {
        return 0;
    }
}

/**
 * Retorna o peso, ou 0 (caso não exista), da aresta que conecta o vértice "origin" ao "destin"
 */
int Graph::getEdge(int origin, int destin) {
    int wei = this->adj[origin][destin];

    // Verifica se a aresta existe
    wei > 0 ? wei : 0;
}

/**
 * Faz uma busca por profundidade do vértice "origin" até o "destin"
 */
int Graph::dfs(int origin, int destin) {
    return dfs(origin, destin, origin);
}

int Graph::dfs(int origin, int destin, int prev) {

    int sum = 0;

    for( int i = (prev + 1) % getNumVertex(); i != prev; i = (i + 1) % getNumVertex() ){

        // Verifica se o vértice de origem e o "i" estão conectados e se "i" não é o vértice anterior
        if(adj[origin][i] != 0 && i != prev){
            sum = dfs(i, destin, origin);
        }

        // Verifica se já achou alguma aresta ou se "i" é o vértice de destino e tem conexão com o atual
        if(sum != 0 || (i == destin && adj[origin][i] != 0)){
            sum += adj[origin][i]; // Somar o peso da aresta
            break;
        }
    }
    return sum;
}

/**
 * Faz a busca por profundidade no Grafo, a partir do vértice "node"
 */
void Graph::dfsT(int node) {
    this->visited[node] = true;
    int i;
    cout << node << " ";

    for(i = 0; i < this->numVertex; i++) {
        if(adj[node][i] && !this->visited[i]) {
            dfsT(i);
        }
    }

    cout << endl;
}

/**
 * Faz a busca por largura no Grafo, a partir do vértice "node"
 */
void Graph::bfsT(int node) {
    this->visited[node]=true;
    queue<int> qu;
    qu.push(node);

    while(!qu.empty()) {
        int element = qu.front();
        int i;
        qu.pop();
        cout << element << " ";
        for(i = 0; i < this->numVertex; i++) {
            if(adj[element][i] && !this->visited[i]) {
                qu.push(i);
                this->visited[i] = true;
            }
        }
    }
}

/**
 * Verifica se o vértice é isolado
 */
bool Graph::emptyMat(int v) {
  for (int i = 0; i < this->numVertex; i++) {
    if (adj[v][i] > 0) {
      return false;
    }
  }
  return true;
}

/**
 * Printa o Grafo
 */
void Graph::display() {

    cout << "\n\n            ";
    for(int i = 0; i < this->numVertex; i++) {
      printf("%10d  ", i);
    }

    cout << "\n\n";
    for (int i = 0; i < this->numVertex; i++) {

      printf("%10d  ", i);
      for (int j = 0; j < this->numVertex; j++) {
        printf("%10d  ", this->adj[i][j]);
      }
      cout << endl;
    }
    cout << "\n\n";
}

/*
int main() {

    Graph g(6);
    g.addEdge(1, 0, 8);
    g.addEdge(2, 1, 7);
    g.addEdge(3, 1, 9);
    g.addEdge(4, 0, 3);
    g.addEdge(5, 4, 2);

    cout << "MATRIZ DE ADJACÊNCIA:\n";
    g.display();

    cout << "\n\nDFS(2,3):\n" << g.dfs(2,3);

    cout << "\n\nDFS(5,2):\n" << g.dfs(5,2);

    return 0;
}
*/
