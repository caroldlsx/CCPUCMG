/*
 *Expensive Subway
 *@author Carolina Lima
 *Matricula: 561397
 *A análise de complexidade foi feita observando o número de inserções no grafo
 *Função de Complexidade: 2 * N = 2 * número de conexões
 *Complexidade: O(n)
 */
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <map>

using namespace std;

void printaResultado(int custoMinimo){
    if(custoMinimo == -1){
        cout << "Impossible" << endl;
    } else {
        cout << custoMinimo << endl;
    }
}
int prim(map <string, map <string, int> > & grafo, string origem);

// algoritmo de prim, algumas partes foram retiradas da internet
int prim(map <string, map <string, int> > & grafo, string origem){
    map <string, bool> visitado;
    int custoMinimo = 0;

    for(auto i : grafo){
        visitado[i.first] = false;
    }

    set<pair<int, pair<string, string>>> heap;

    for(auto aresta : grafo[origem]){
        heap.insert(make_pair(aresta.second, make_pair(origem, aresta.first)));
    }
    visitado[origem] = true;

    while(!heap.empty()){
        pair <int, pair <string, string> > aresta = *heap.begin();
        heap.erase(heap.begin());
        origem = aresta.second.second;

        if(!visitado[origem]){
            visitado[origem] = true;
            custoMinimo += aresta.first;

            for(auto aresta : grafo[origem]){
                heap.insert(make_pair(aresta.second, make_pair(origem, aresta.first)));
            }
        }
    }
    // verificando se todas as estacoes foram visitadas
    for(auto estacao : visitado){
        if(!estacao.second){
            return -1;
        }
    }
    return custoMinimo;
}

int main()
{
    do{
        int numeroEstacoes = 0, numeroConexoes = 0;
        // a primeira linha nos diz quantos nos a arvore tem
        cin >> numeroEstacoes >> numeroConexoes;
        
        if(numeroEstacoes == 0 && numeroConexoes == 0) break;

        map<string, map<string, int>> grafo;
        
        // lendo as coordenadas e setando no grafo
        for(int i = 0; i < numeroEstacoes; i++){
            string estacao;
            cin >> estacao;
            map <string, int> arestas;
            grafo[estacao] = arestas;
        }

        for(int j = 0; j < numeroConexoes; j++){ // n vezes
            int custo;
            string estacao1, estacao2;
            cin >> estacao1 >> estacao2 >> custo;
            grafo[estacao1].insert(make_pair(estacao2, custo));
            grafo[estacao2].insert(make_pair(estacao1, custo));
        }
        string origem;
        cin >> origem;

        int custoMinimo = prim(grafo, origem);
        printaResultado(custoMinimo);

    }while(true);
    
    return 0;
}