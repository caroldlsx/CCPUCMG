/*
 *Arvore Genealogica
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: A complexidade sera feita analisando o numero de comparacoes da matriz.
 * FUNÇÃO DE COMPLEXIDADE: Ο(n + m). Como n + m é o tamanho do grafo, o algoritmo é linear.
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>

using namespace std;
  
map<string, int> mapa;

int grafo[1000][1000] = {0};
int vetor[1000] = {0};
int posicao = -1;
/*
*Metodo mappFunction
*@param string str 
*@return inteiro com a posicao no mapa
*a ser inserida no grafo
*/
int mappFunction(string str){
    int j;

    //iterator eh usado pra apontar o endereco de memoria
    map<string, int>::iterator it = mapa.find(str);
    if(it != mapa.end()){ //mapa.end() retorna o iterator para o ultimo elemento no mapa
        j = it->second;
    }else{
        mapa.insert(pair<string, int>(str,++posicao));
        j = posicao;
    }
    
    return j;
}

void dfs(int i, int m, int numero)
{
    if (vetor[i]){
        return;
    }

    vetor[i] = ++numero;

    for (int j = 0; j < m; j++){ // m vezes
        if (grafo[i][j]){
            dfs(j, m, numero); 
        }
            
    }  
}

int main()
{
    int m = 0, n = 0;
    string str;

    cin >> m >> n;

    for(int i = 0; i < m; i++){
        string nome1, relacao, nome2;
        cin >> nome1 >> relacao >> nome2;
        int j1 = mappFunction(nome1);
        int j2 = mappFunction(nome2);
        grafo[j1][j2] = grafo[j2][j1] = 1;
    }
    int numero = 0;

    for(int i = 0; i < m; i++){
    
        if (!vetor[i]){
            dfs(i, m, numero++);
        }
        
    }
    // for(auto i : mapa){
    //     cout << i.first << endl;
    // }
    cout << numero << endl;
    return 0;
}