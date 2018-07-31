#include <bits/stdc++.h>

using namespace std;

unsigned long long val[30001];
int moedas[5] = {1, 5, 10, 25, 50};

int main()
{
    int aux;
    val[0] = 1;
    
    for (int m = 0; m < 5; ++m)
    {
        for (int i = moedas[m]; i < 30001; ++i)
        {
            val[i] += val[i - moedas[m]];
        }
    }
    
    while (cin >> aux) {
        if (val[aux] == 1)
            cout << "There is only 1 way to produce " << aux << " cents change." << endl;
        else
            cout << "There are " << val[aux] << " ways to produce " << aux << " cents change." << endl;
    }
    
    return 0;
}
