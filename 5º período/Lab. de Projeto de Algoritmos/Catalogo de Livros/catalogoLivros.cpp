/*
 *Catalogo de Livros
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: 
 * FUNÇÃO DE COMPLEXIDADE: F(n) = P * M * F * Q * B -> O(n) = (PMFQB)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>


using namespace std;


int main()
{
    int k = 0, valor = 0, qtdLivros = 5, resultado = 0;
    vector <vector<int>> matrizLivros(qtdLivros);
    vector <int> livros(qtdLivros);
    vector <int> soma;

    /* na primeira quando i for variando, pego o inteiro correspondente
    * a quantidade de livros da materia
    */
    for(int i = 0; i < qtdLivros; i++){
        cin >> livros[i];
        for(int j = 0; j < livros[i]; j++){
            cin >> valor;
            matrizLivros[i].push_back(valor);
        }
    }

    // for(int a = 0; a < qtdLivros; a++){
    //     for(int b = 0; b < qtdLivros; b++){
    //         cout << matrizLivros[a][b] << " ";
    //     }
    //     cout << endl;
    // }

    for(int a = 0; a < livros[0]; a++){ // for do portugues - p vezes
        for(int b = 0; b < livros[1]; b++){ // for da matematica - mvezes
            for(int c = 0; c < livros[2]; c++){ // for da fisica - f vezes
                for(int d = 0; d < livros[3]; d++){ // for da quimica - q vezes
                    for(int e = 0; e < livros[4]; e++){ // for da biologia - b vezes
                        soma.push_back(matrizLivros[0][a] + matrizLivros[1][b] + matrizLivros[2][c] + matrizLivros[3][d] + matrizLivros[4][e]);
                    }
                }
            }
        }
    }

    sort(soma.begin(), soma.end(), greater<int>());
    cin >> k;
    for(int i = 0; i < k && i < soma.size(); i++){
        resultado += soma[i];
    }
    cout << resultado << endl;
    return 0;
}