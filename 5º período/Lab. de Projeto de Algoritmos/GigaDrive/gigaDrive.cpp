/*
 *
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: A complexidade sera feita analisando o numero de comparacoes da matriz.
 * FUNÇÃO DE COMPLEXIDADE = |j2 - j1 + 1|*|i2 - i1 + 1|*m
 *                        = |j2i2-j2i1+j2-j1i2+j1i1-j1+i2-i1+1|m
 *                        = |j2(i2-i1+1)-j1(i2+i1-1)+(i2-i1+1)|m
 *                        = O(m(j2(i2-i1+1)-j1(i2+i1-1)+(i2-i1+1))
 */
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int totalAzeitonas = 0, 
        n = 0, m = 0, // n = ordem da matriz, m = numero de jogadas
        i = 0, i1 = 0, j1 = 0, j = 0, i2 = 0, j2 = 0; 

    while(cin >> n >> m){    

        int matriz[n][n];

        for(int row = 0; row < n; row++){ // populando a matriz
            for(int col = 0; col < n; col++){
                cin >> matriz[row][col];
            }
        }
        for(int rounds = 0; rounds < m; rounds++){ // m vezes
            cin >> i >> j;

            matriz[i-1][j-1] = 1;

            cin >> i1 >> j1 >> i2 >> j2;

            for(int a = i1-1; a < i2; a++){ //(i2 - i1 + 1) vezes
                for(int b = j1-1; b < j2; b++){ //(j2 - j1 + 1) vezes
                    if(matriz[a][b]== 1) totalAzeitonas++;   // comparacao 
                }
                
            }
            cout << totalAzeitonas << endl;

            totalAzeitonas = 0, 
            i = 0, i1 = 0, j1 = 0, j = 0, i2 = 0, j2 = 0;
            
        }
    } 
    return 0;
}