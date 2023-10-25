/*
 *BLOBS
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: O(n) = O( n * log2 c)
 */
#include <iostream>
using namespace std;

int contaDias(float c){
    int dias = 0;
    while(c > 1){     // log2 c
        c = c/2;
        dias++;    
    }
    return dias;
}

int main()
{
    int n, count;

    cin >> n;
 
    float food[n];
   
    for(int i = 0; i < n; i++){ // será executado n vezes
        cin >> food[i];      

        count = contaDias(food[i]);
          
        cout << count << " dias" << endl;
    }    
    return 0;
}

