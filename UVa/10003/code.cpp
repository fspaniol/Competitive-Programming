#include <bits/stdc++.h>

using namespace std;

int cuts, size, pieces[52] = {0};

int pd() {
    int val[52][52] = {}, a, b, c, d;
    for(a = 2; a <= cuts; a++) {
        for(b= 0, c= a+b; c <= cuts; b++, c++) {
            int min = 2147483647, t;
            for(d = b+1; d < c; d++) {
                t = val[b][d] + val[d][c] + pieces[c] - pieces[b];
                if(min > t)
                    min = t;
            }
            val[b][c] = min;
        }
    }
    return val[0][cuts];
}
int main() {
    while(cin >> size && size) {
        cin >> cuts;
        for(int i = 1; i <= cuts; i++)
           cin >> pieces[i];
        pieces[++cuts] = size;
        cout << "The minimum cutting is " << pd() << "." << endl;
    }
    return 0;
}
