#include <bits/stdc++.h>

using namespace std;

int tamanho;

bool isPerfectSquare(long long n){
    // cout << "Trying " << n << endl;
    long long squareRootN=(long long)round((sqrt(n)));
    if(squareRootN*squareRootN == n) {
        return true; 
    }
    return false; 

}

bool verifica(int x, vector<int> &valores){
    for (int i = 1; i < tamanho+1; i++){
        if(valores[i] == 0){
            valores[i] = x;
            return true;
        }
        
        if(isPerfectSquare(valores[i] + x)) {
            valores[i] = x;
            return true;
        }
    }

    return false;
}

void inicializa_vector(vector<int> &valores){
    for(int i = 0; i <= tamanho; i++)
        valores.push_back(0);
}

int main()
{
    int testes;
    cin >> testes;
    while (testes--) {
        cin >> tamanho;
        vector<int> valores;
        inicializa_vector(valores);
        bool okay;
        int i = 1;
        while(verifica(i, valores)){
            i++;
        }
        cout << i-1 << endl;
    }

    return 0;
}
