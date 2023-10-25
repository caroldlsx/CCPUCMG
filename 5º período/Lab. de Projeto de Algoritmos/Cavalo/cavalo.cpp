/*
 *CAVALO
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: 
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
const int possiveisMovimentos = 8;
int iMovimento[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int jMovimento[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int countPeao = 0;
char tabuleiro[8][8];


void achaCaminho(int movimento, int n, int m, int k, int iCavalo, int jCavalo){

    int iNovo = 0, jNovo = 0;

    cout << "movimento: " << movimento << endl << "n: " << n << endl 
         << "m: " << m << endl << "k: " << k << endl 
         << "iCavalo: " << iCavalo << endl << "jCavalo: " << jCavalo << endl;

    if(movimento == n * m) return;
    if(countPeao == k) return;

    for(int mov = 0; mov < possiveisMovimentos; mov++){
        iNovo = iCavalo + iMovimento[mov];
        jNovo = jCavalo + jMovimento[mov];

        cout << "iNovo: " << iNovo << endl 
             << "jNovo: " << jNovo << endl;

        if(iNovo < 0 || iNovo >= n || jNovo < 0 || jNovo >= m) continue;
        if(tabuleiro[iNovo][jNovo] == '#') return;
        if(tabuleiro[iNovo][jNovo] == 'P') countPeao++;
        achaCaminho(movimento + 1, n, m, k, iNovo, jNovo);
        cout << "countPeao: " << countPeao << endl;
    }
    
    
}

int solve(int n, int m, int k){

    int iCavalo = 0, jCavalo = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tabuleiro[i][j] == 'C'){
                iCavalo = i;
                jCavalo = j;
            }
        }
    }
    achaCaminho(1, n, m, k, iCavalo, jCavalo);
    cout << countPeao;

}

int main()
{

    int n, m, k;
    char caracter;

    do{
        cin >> n >> m >> k;

        if(n == 0 && m == 0 && k == 0) break;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> caracter;
                tabuleiro[i][j] = caracter;
            }
            
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               cout << tabuleiro[i][j] << " ";
            }
            cout << endl;
        }

        solve(n, m, k);

    }while(true);
    
    return 0;

}