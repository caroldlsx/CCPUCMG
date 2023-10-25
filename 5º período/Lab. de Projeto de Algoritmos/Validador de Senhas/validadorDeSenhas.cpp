/*
 *VALIDADOR DE SENHAS
 *@author Carolina Lima
 *Matricula: 561397
 *Complexidade: O (n² * m)
 */
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main()
{

    vector<string> s;

    string password;

    int lengthStr, caractere;

    bool upperCase = false, lowCase = false, space = false, 
         length = false, special = false, number = false;

    while(getline(cin, password)){
        if(password[password.length() - 1] == '\r'){
            password.pop_back(); // Apaga o último caractere da string
        }
        s.push_back(password); // Acrescenta ao final da string, aumentando seu comprimento em um.
    }

    for(int i = 0; i < s.size(); i++){
        
        lengthStr = s[i].length();

        for(int j = 0; j < lengthStr; j++){

            caractere = int(s[i][j]);

            if(lengthStr >= 6 && lengthStr <= 32){
                length = true;
                if (caractere >= 65 && caractere <= 90){
                    upperCase = true;
                } else if (caractere >= 97 && caractere <= 122){
                    lowCase = true;
                } else if (caractere >= 48 && caractere <= 57){
                    number = true;
                } else if (isspace(s[i][j])){
                    space = true;
                }
                else{
                    special = true;
                }
            }else {
                length = false;    
            }
        }

        if (upperCase && lowCase && number && !space && !special && length){
            cout << "Senha valida." << endl;
        } else {
            cout << "Senha invalida." << endl;
        }

        upperCase = false, lowCase = false, space = false, 
        length = false, special = false, number = false;
        
    }
    return 0;
}

