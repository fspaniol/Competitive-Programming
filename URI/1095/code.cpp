#include <bits/stdc++.h>

using namespace std;

int matriz[5][5];

int dfs(int x, int y) {
    int val = 0;
    if (x == 4 && y == 4)
        return 1;
    matriz[x][y] = -1;
    if (x < 4 && matriz[x+1][y] == 0)
        val = dfs(x+1, y);
    if (val != 1 && y < 4 && matriz[x][y+1] == 0) 
        val = dfs(x, y+1);
    if (val != 1 && y > 0 && matriz[x][y-1] == 0)
        val = dfs(x, y-1);
    if (val != 1 && x > 0 && matriz[x-1][y] == 0)
        val = dfs(x-1,y);
    
    return val;
}

void calcular() {
    int x;
    x = dfs(0,0);
    if (x == 1)
        cout << "COPS" << endl;
    else
        cout << "ROBBERS" << endl;
}

int main()
{
   int entradas;
    int aux;
    cin >> entradas;
    while (entradas--){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                cin >> aux;
                matriz[i][j] = aux;
            }
        }
        calcular();
    }

    return 0;
}