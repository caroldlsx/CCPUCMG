/*
    @author: Heleny Maria Diniz Bessa
    Matrícula: 553250
    Complexidade:
        Caso analisado: Contagem de notas e moedas.
        Melhor caso == pior caso: do jeito que fiz, parece que inteiro e decimal são números diferentes,
                                mas é um número que estão em variáveis diferentes então chamarei de N o número em seu todo.
                                A complexidade de cada while é O(N/100), O((N/100)/50), O(((N/100)/50)/20), O((((N/100)/50)/20)/10), O(((((N/100)/50)/20)/10)/5)...
                                Assim, a complexidade final seria a soma desses whiles todos. Como constantes não são consideradas em cálculos de complexidade que tem
                                um variável, a complexidade final é de O(N).
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int countGlobal = -1;
int countAtual = -1;
int pointPeao = 1;
int N = 0, M = 0, K = 0;
int numPeoes = 0;
priority_queue <int, vector<int>, greater<int> > pq;
vector<vector<bool>> mBlacklist;
ofstream myfile;

void esvaziarBlacklist() {
    for(int i = 0; i < N; i++) {
        vector<bool> booltemp;
        for(int j = 0; j < M; j++) {
            booltemp.push_back(false);
        }
        mBlacklist.push_back(booltemp);
    }
    return;
}

void acharPeao(int i, int j, vector<vector<char>> mJogo, vector<vector<int>> mControle) {
    if(i >= N || j >= M) return;
    if(i < 0 || j < 0) return;
    if(mJogo[i][j] == '#') return;
    //if(mControle[i][j] == countGlobal - 1) return;
    //if(mJogo[i][j] == 'C' && numPeoes < K && countGlobal > -1) return;
    //cout << "mControle de " << i << " " << j << " = " << mControle[i][j] << endl;
    //cout << "pointPeao = " << pointPeao << endl;

    if(/*numPeoes == K || */ mControle[i][j] < pointPeao && mBlacklist[i][j] == false) { //SÓ PRA VER UMA COISA
        countGlobal++;
        if(mJogo[i][j] == 'P' && numPeoes < K) {
            numPeoes++;
            pointPeao = countGlobal;
            myfile << "eh peao!" << endl;
            //mJogo[i][j] = 'F';
            /*
                O PROBLEMA AGORA (17:37H)
                    Como fazer - na hora que o pointPeao for atualizado - com que este peão que já foi checado não seja contado novamente?
                    Por exemplo, pegou P1 e pegou P2, agora hora de voltar. Se na volta, acabar caindo em P1, vai contar como novo peão
                    e vai atualizar pointPeao. NÃO pode mudar para 'F' como eu fiz porque ainda é preciso testar outros caminhos! Matriz
                    de jogo em especial deve ser mantida intacta.
                    1) if(mJogo[i][j] == 'P' && numPeoes < K)?
            */
        }
        else if(mJogo[i][j] == 'C' && numPeoes == K) {
            cout << "                                                       entrou adicionando: " << countGlobal << endl;
            pq.push(countGlobal);
            countGlobal--;
            return;
        }
        mBlacklist[i][j] = true;
        mControle[i][j] = countGlobal;
        myfile << "novo mControle de " << i << " " << j << " = " << mControle[i][j] << endl;
        myfile << "   primeiro loop " << i << " " << j << endl;
        acharPeao(i-1, j+2, mJogo, mControle);
        myfile << "   voltou do primeiro loop " << i << " " << j << endl;
        myfile << "   segundo loop " << i << " " << j << endl;
        acharPeao(i+1, j+2, mJogo, mControle);
        myfile << "   terceiro loop " << i << " " << j << endl;
        acharPeao(i+2, j+1, mJogo, mControle);
        myfile << "   voltou do terceiro loop " << i << " " << j << endl;
        myfile << "   quarto loop " << i << " " << j << endl;
        acharPeao(i+2, j-1, mJogo, mControle);
        myfile << "   voltou do quarto loop " << i << " " << j << endl;
        myfile << "   quinto loop " << i << " " << j << endl;
        acharPeao(i+1, j-2, mJogo, mControle);
        myfile << "   voltou do quinto loop " << i << " " << j << endl;
        myfile << "   sexto loop " << i << " " << j << endl;
        acharPeao(i-1, j-2, mJogo, mControle);
        myfile << "   voltou do sexto loop " << i << " " << j << endl;
        myfile << "   setimo loop " << i << " " << j << endl;
        acharPeao(i-2, j+1, mJogo, mControle);
        myfile << "   voltou do setimo loop " << i << " " << j << endl;
        myfile << "   ultimo loop " << i << " " << j << endl;
        acharPeao(i-2, j-1, mJogo, mControle);
        myfile << "   voltou do ultimo loop " << i << " " << j << endl;

        mControle[i][j] = 0;
        countGlobal--;
        if(mJogo[i][j] == 'P') numPeoes--;
        mBlacklist[i][j] = false;
        string tal = mBlacklist[i][j] == true ? "true" : "false";
        myfile << "mBlacklist[i][j] == " << tal << endl;
    }
    return;
}

int main()
{
    char delimitador = '.';
    string linha = " ";

    // getline(cin, linha, delimitador);
    //     v = stoi(linha);
    //     getline(cin, linha);
    //     e = stoi(linha);
    //cin >> num;
    //while (num)
    cin >> N;
    //cout << N << endl;
    cin >> M;
    //cout << M << endl;
    cin >> K;
    //cout << K << endl;
    //while (getline(cin, linha, delimitador))
    while(M > 0 && N > 0 && K > 0)
    {
        vector<vector<int>> mControle;
        vector<vector<char>> mJogo;
        //vector<vector<bool>> mBlacklist;
        int coroaLinha = 0;
        int coroaColuna = 0;

        for(int i = 0; i < N; i++) {
            vector<int> inttemp;
            vector<char> chartemp;
            vector<bool> booltemp;
            char temp = ' ';
            for(int j = 0; j < M; j++) {
                //cout << "oi";
                //cin >> mJogo[i][j];
                cin >> temp;
                chartemp.push_back(temp);
                //cout << "aqui";
                //mControle[i][j] = 0;
                if(temp == 'C') {
                    coroaLinha = i;
                    coroaColuna = j;
                    inttemp.push_back(-1);
                } else inttemp.push_back(0);
                booltemp.push_back(false);
                //cout << chartemp[j];
                //cout << mJogo[i][j];
            }
            //cout << endl;
            mJogo.push_back(chartemp);
            mControle.push_back(inttemp);
            mBlacklist.push_back(booltemp);
        }

        myfile.open ("example.txt");

        acharPeao(coroaLinha, coroaColuna, mJogo, mControle);

        cout << "aqui ó " <<  pq.top() << endl;

        //pq.clear();
        //ou
        while(!pq.empty()) {
            pq.pop();
        }
        countAtual = 0;
        cin >> N >> M >> K;
    }
}