#include <bits/stdc++.h>

using namespace std;

int mapa[201][201] = {0};
int cores[201];
int nodos;

int dfs(int pos, int cor){
    int ans = 0;
    cores[pos] = cor;
    for(int i = 0; i < nodos; i++){
        if (mapa[pos][i] == 1) {
            if (cores[i] == -1)
                ans += dfs(i,1-cor);
            else {
                if (cores[i] == cor)
                    return 1;
            }
        }
     }
    return ans;
}

void limpa(){
    for (int x = 0; x < 201; x++){
        for (int y = 0; y < 201; y++) {
            mapa[x][y] = 0;
        }
        cores[x] = -1;
    }
}

int main()
{
    int arestas, x, y;
    while (cin >> nodos && nodos != 0) {
        cin >> arestas;
        limpa();
        while(arestas--) {
            cin >> x >> y;
            mapa[x][y] = 1;
            mapa[y][x] = 1;
        }
        int result = dfs(0,0);
        if (result == 1) 
            cout << "NOT BICOLORABLE." << endl;
        else
            cout << "BICOLORABLE." << endl;
    }
   
    return 0;
}