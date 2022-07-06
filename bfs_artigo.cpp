// Busca em largura em Grafos


#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Grafo
{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências
    vector<string> nomes;
public:
	Grafo(vector<string> nomes); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo

	// Faz uma BFS a partir de um vértice
	void bfs(int v);
};

Grafo::Grafo(vector<string> nomes)
{
	V = int(nomes.size()); // Atribui o número de vértices
	this->nomes = nomes; // Atribui nomes dos vértices
	adj = new list<int>[V]; // Cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// Adicionar vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados

	// Marcar todos como não visitados
	for(int i = 0; i < V; i++)
		visitados[i] = false;

    fila.push(v);
    visitados[v] = true;

	while(!fila.empty())
	{
		v = fila.front();

		fila.pop();

		cout << "Visitando vertice " << nomes[v] << " ...\n";


		list<int>::iterator it;

		// busca por todos os vizinhos não visitados
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				visitados[*it] = true;
				fila.push(*it);
			}
		}
	}
}

int main()
{
	vector<string> nomes = {"0BlocoH","1Estacionamento","2InstitutoFisica","3UFfinance","4UFF","5PosGeografia","6InstitutoGeociencias","7InstComputacao"};

	Grafo grafo(nomes);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(0, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(1, 5);
	grafo.adicionarAresta(2, 3);
	grafo.adicionarAresta(2, 5);
    	grafo.adicionarAresta(4, 6);
    	grafo.adicionarAresta(5, 6);
    	grafo.adicionarAresta(5, 7);
    	grafo.adicionarAresta(6, 7);


	grafo.bfs(0);

	return 0;
}
