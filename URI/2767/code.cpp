#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k, val, aux;
    while(cin >> n >> m >> k){
        int restos[100001];
        memset(restos,0,100001);
        long long soma = 0;
        while(n--){
            cin >> val;
            restos[val%k]++;
        }
        while(m--){
            cin >> val;
            soma += restos[(k - (val%k))%k];
        }
        cout << soma << endl;
    }

    return 0;
}

