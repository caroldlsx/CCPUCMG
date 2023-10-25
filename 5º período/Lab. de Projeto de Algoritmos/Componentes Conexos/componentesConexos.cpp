/*
 *Componentes Conexos
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: A complexidade sera feita analisando o numero de comparacoes da matriz.
 * FUNÇÃO DE COMPLEXIDADE: Ο(n²).
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;


int main()
{
    int n, v, e, casos = 1; 

    cin >> n;

	for(int i = 0; i < n; i++){
		cin >> v >> e;
        
		char grafo[v][v];

        memset(grafo,'-',sizeof(grafo));
        char u, p;

        for(int i = 0; i < v; i++)
        {
            grafo[i][0]=i+97;
        }
		for(int j = 0; j < e; j++){
			cin >> u >> p;

            grafo[u-97][p-97]=p;
            grafo[p-97][u-97]=u;
		}
        
        cout << "Case #" << casos++ << ":" << endl;

		int nodes[v];
        memset(nodes,-1,sizeof(nodes));
        int count = 0;
        for(int i = 0; i < v; i++)
        {
            bool linha = false;
            stack<char> pilha;
            if(nodes[i] == -1){
            pilha.push(i+97);
            count++;
            nodes[i] = 1;
            linha = true;
            }
            stack<char> pilha2;
            int countPilha=0;
            while(!pilha.empty()){
                  char d=pilha.top();
                  if(countPilha!=0)
                  pilha2.push(d);
                  else cout << d <<",";
                  pilha.pop();
                  countPilha++;
            for(int j = 0; j < v; j++) // n vezes
            {
                if(grafo[d-97][j]!='-') 
                {
                    if(nodes[grafo[d-97][j]-97]==-1)
                    {
                        linha = true;
                        nodes[grafo[d-97][j]-97]=1;
                        pilha.push(grafo[d-97][j]);
                    }
                }
            }
            }vector<char> s;
            while(!pilha2.empty())
            {
                char tp=pilha2.top();
                s.push_back(tp);pilha2.pop();
            }
            sort(s.begin(),s.end());
            for(int i=0;i<s.size();i++)cout<<s[i]<<",";
            if(linha)
            cout << endl;
        }
        cout << count << " connected components" << endl;
        cout<<endl;
	}

    return 0;
}