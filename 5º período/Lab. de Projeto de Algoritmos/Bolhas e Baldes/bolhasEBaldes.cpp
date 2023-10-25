/*
 *Bolhas e Baldes
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: 
 *OMPLEXIDADE: n (log(n))
 */
#include <iostream>
#include <vector>
#include <stdio.h>

int counter;

using namespace std;

void printaResultado(){
    if(counter % 2) cout << "Marcelo" << endl;
    else cout << "Carlos" << endl;
}

void merge(vector <int> &sequencia, int esq, int meio, int dir){
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    //temp arrays
    vector <int> esquerdo(n1);
    vector <int> direito(n2);

    for (int i = 0; i < n1; i++){ 
        esquerdo[i] = sequencia[esq + i];
    }
    for (int j = 0; j < n2; j++){ 
        direito[j] = sequencia[meio + 1 + j];
    }

    //faz o merge dos arrays temporarios de volta para o array sequencia
    int i = 0, j = 0, k = esq; //index inicial do primeiro array e do segundo

    while(i < n1 && j < n2){
        if(esquerdo[i] <= direito[j]){
            sequencia[k] = esquerdo[i];
            i++;
        } else{
            sequencia[k] = direito[j];
            counter += (int)n1 - i;
            j++;
        }
        k++;
    }

    //copia os elementos remanescentes de esquerdo[], se houver algum
    while(i < n1){
        sequencia[k] = esquerdo[i];
        i++;
        k++;
    }

    //copia os elementos remanescentes de direito[], se houver algum
    while(j < n2){
        sequencia[k] = direito[j];
        j++;
        k++;
    }    
}

void mergeSort(vector <int> &sequencia, int esq, int dir){
    if (esq >= dir) return;

    int meio = esq + (dir - esq)/2;
    mergeSort(sequencia, esq, meio);
    mergeSort(sequencia, meio + 1, dir);
    merge(sequencia, esq, meio, dir);
    
}

int main()
{
    
    while(true){ 
        int n, valor;
        counter = 0;
        
        cin >> n;
        if(n == 0) break;

        vector<int> sequencia;

        for(int i = 0; i < n; i++){
            cin >> valor;
            sequencia.push_back(valor);
        }
        // cout << n;
        // for(int i = 0; i < n; i++){
        //     cout << " " << sequencia[i];
        // }
        // cout << endl;
        
        int seqSize = sequencia.size();

        mergeSort(sequencia, 0, seqSize - 1);
        printaResultado();

        sequencia.clear();

    }

    return 0;
}