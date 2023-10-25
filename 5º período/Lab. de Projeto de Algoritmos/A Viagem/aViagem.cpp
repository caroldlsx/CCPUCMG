 /*A Viagem
 *@author Carolina Lima
 *Matricula: 56139
 *Análise de complexidade: nº de comparações entre o array
 * = O(n) para cada viagem
 * = O(m*n) sendo m o número de viagens de cada rodada
 */
#include <iostream>
#include <vector>
#include <tgmath.h>
#include <stdio.h>
#include <iomanip> 
using namespace std;

int main()
{
    int n;
    
    while(cin >> n){
        
        if(n != 0){
            vector <int> array;
            int valor;
            char ponto;
            float media = 0, total = 0, menor = 0, maior = 0;
            float decimal = 0;

            for(int i = 0; i < n; i ++){
                cin >> valor >> ponto >> decimal;
                array.push_back(round(valor * 100 + decimal));
                total += array[i];
            }

            media = total / n;

            for(int i = 0; i < n; i++){
                if(array[i] <= media){ 
                    menor += (int)(media - array[i])/100.0;
                }else{
                    maior += (int)(array[i] - media)/100.0;
                }
            }
            if(menor > maior){
                cout << "$" <<  setprecision (2) << fixed << menor << endl;
            }else{
                cout << "$" << setprecision (2) << fixed << maior <<  endl;
            }
        }
        
    }
    
    return 0;
}