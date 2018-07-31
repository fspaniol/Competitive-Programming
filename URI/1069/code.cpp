#include <bits/stdc++.h>

using namespace std;

int main()
{
   
    int entradas;
    string mina;
    cin >> entradas;
    while (entradas--) {
        cin >> mina;
        int abre = 0;
        int cont = 0;
        for (int i = 0; i < mina.length(); i++){
            if (mina[i] == '<') {
                abre++;
            }
            if (mina[i] == '>' && abre > 0) {
                abre--;
                cont++;
            }
        }
        
        cout << cont << endl;
    }

    return 0;
}