#include <bits/stdc++.h>

using namespace std;

int tabuleiro[10];
int cp[10];

bool place(int newRow, int newCol) {
    for (int prevRow = 1; prevRow < newRow; prevRow++){
        int prevCol = tabuleiro[prevRow];
        if (newCol == prevCol)
            return false;
        if(abs(newRow - prevRow) == abs(newCol - prevCol))
            return false;
    }
    return true;
}

int backtrack(int row){
    if (row == 9) return 0;
    int tot = 100000;
    for (int col = 1; col < 9; col++){
        if (place(row, col)){
            tabuleiro[row] = col;
            tot = min(tot, col == cp[row]? backtrack(row+1) : 1 + backtrack(row+1));
        }
    }
    
    return tot;
}

void copyTabuleiro(){
    for (int i = 1; i < 9; i++)
        cp[i] = tabuleiro[i];
}

int countDifference(){
    int cont = 0;
    for (int i = 1; i < 9; i++){
        if (cp[i] != tabuleiro[i])
            cont++;
    }
    
    return cont;
}

void print_solution(){
    for (int i = 1; i < 9; i++)
        cout << tabuleiro[i] << ' ';
    cout << endl;
}

int main()
{
    int num;
    int cont = 1;
    while (cin >> num)
    {
        tabuleiro[1] = num;
        for (int i = 2; i < 9; i++){
            cin >> num;
            tabuleiro[i] = num;
        }
        
        copyTabuleiro();
        cout << "Case " << cont++ << ": " << backtrack(1) << endl;
    }

    return 0;
}
