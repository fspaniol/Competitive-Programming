#include <bits/stdc++.h>

using namespace std;

int distancias[102][102];
int soma, cont;
int c = 1;

void zeraDistancias() {
    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++){
            distancias[i][j] = 500;
        }
    }
}

void calcula(){
    soma = 0;
    cont = 0;
    for (int i = 1; i < 102; i++){
        for(int j = 1; j < 102; j++){
            if(distancias[i][j] != 500 && i != j){
                cont++;
                soma += distancias[i][j];
            }
        }
    }
}

void calc(){
    for (int k = 1; k < 102; ++k)
            for (int i = 1; i < 102; ++i)
                for (int j = 1; j < 102; ++j)
                    distancias[i][j] = min(distancias[i][j], distancias[i][k] + distancias[k][j]);
    calcula();
}

int main() {
    int a, b;
    while(cin >> a >> b && a != 0){
        zeraDistancias();
        distancias[a][b] = 1;
        while(cin >> a >> b && a != 0){
            distancias[a][b] = 1;
        }
        calc();       
        cout << "Case " << c++ << ": average length between pages = " << setprecision(3) << fixed << double(soma) / cont << " clicks" << endl;
    }
    
    return 0;
}