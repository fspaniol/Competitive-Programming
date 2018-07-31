#include <bits/stdc++.h>

using namespace std;

int moedas[101];
int knapSack(int N, int W){
    int A[25001] = {0};

    for(int i = 1; i<= N; i++)
        for(int j = W; j>0; j--){
            if(moedas[i]<= j)
                A[j] = max(A[j], moedas[i] + A[j - moedas[i]]);
        }
   return A[W];
}

int main()
{

    int entradas, valorTotal, n;
    cin >> entradas;
    while(entradas--){
        cin >> n;
        valorTotal = 0;
        for(int i = 1; i<=n; i++){
            cin >> moedas[i];
            valorTotal += moedas[i];
            }

    cout << valorTotal - 2*knapSack(n, valorTotal/2) << endl;
    }
    return 0;
}