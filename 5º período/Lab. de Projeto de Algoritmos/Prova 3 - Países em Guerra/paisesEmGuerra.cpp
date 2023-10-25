/*
 *PAISES EM GUERRA
 *@author Carolina Lima
 *Matricula: 561397
 *Analise de Complexidade: Como percorremos cada vertice uma vez e cada aresta uma vez, a complexidade fica O(m log n)
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <limits.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int matriz[500][500];
#define bitShiftOperation 1 << 25

int dijkstra(int inicio, int fim, int n){
    int menorDistancia, proximoVertice;
    int distancia[n];
    bool comunicacao[n];

    for(int i = 1; i <= n; i++){
        distancia[i] = bitShiftOperation;
        comunicacao[i] = false;
    }

    distancia[inicio] = 0;

    for(int i = 1; i <= n; i++){
        menorDistancia = bitShiftOperation;

        if(comunicacao[fim]) break;

        for(int j = 1; j <= n; j++){
            if(distancia[j] < menorDistancia && !comunicacao[j]){
                menorDistancia = distancia[j];
                proximoVertice = j;
            }
        }

        if(menorDistancia == bitShiftOperation) break;
        comunicacao[proximoVertice] = true;

        for(int j = 1; j <= n; j++){
            if(menorDistancia + matriz[proximoVertice][j] < distancia[j]){
                distancia[j] = menorDistancia + matriz[proximoVertice][j];
            }
        }
    }
    return distancia[fim];
}

int main()
{
    int n, e, x, y, h, k, o, d, m;

    while((cin >> n >> e) && (n || e)){

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                matriz[i][j] = bitShiftOperation;
            }
        }
        while(e--){
            cin >> x >> y >> h;
            matriz[x][y] = h;
            if(matriz[y][x] != bitShiftOperation){
                matriz[x][y] = matriz[y][x] = 0;
            }
        }

        cin >> k;
        
        for(int i = 0; i < k; i++){
            cin >> o >> d;
            m = dijkstra(o, d, n);
            if(m == bitShiftOperation){
                cout << "Nao e possivel entregar a carta" << endl;
            }else{
                cout << m << endl;
            }
        }
        cout << endl;
    }
    return 0;
}