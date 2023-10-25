/*
 *NOTAS E MOEDAS
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: O(n)
 */
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    double monetario;

    while(cin >> monetario){
        
                monetario = monetario + 0.0001;
        int valor = monetario;
        int aux = 100*monetario;

        cout << "NOTAS: " << endl;
        cout << valor/100 << " nota(s) de R$ 100.00" << endl;
        valor = valor%100;
        cout << valor/50 << " nota(s) de R$ 50.00" << endl;
        valor = valor%50;
        cout << valor/20 << " nota(s) de R$ 20.00" << endl;
        valor = valor%20;
        cout << valor/10 << " nota(s) de R$ 10.00" << endl;
        valor = valor%10;
        cout << valor/5 << " nota(s) de R$ 5.00" << endl;
        valor = valor%5;
        cout << valor/2 << " nota(s) de R$ 2.00" << endl;
        valor = valor%2;

        cout << "MOEDAS: " << endl;
        cout << valor/1 << " moeda(s) de R$ 1.00" << endl;
        aux = aux%100;
        cout << aux/50 << " moeda(s) de R$ 0.50" << endl;
        aux = aux%50;
        cout << aux/25 << " moeda(s) de R$ 0.25" << endl;
        aux = aux%25;
        cout << aux/10 << " moeda(s) de R$ 0.10" << endl;
        aux = aux%10;
        cout << aux/5 << " moeda(s) de R$ 0.05" << endl;
        aux = aux%5;
        cout << aux/1 << " moeda(s) de R$ 0.01" << endl;
    }

    return 0;

}