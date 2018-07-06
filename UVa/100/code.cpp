#include <bits/stdc++.h>
#include <string.h>

using namespace std;

long long calcula(long long x) {
    long long cont = 1;
    while(x != 1){
        if(x % 2 == 0)
            x /= 2;
        else
            x = x * 3 + 1;
        cont++;
    }
    return cont;
}

int main()
{
    long long a, b, max = 0, tmp, tmp2, flag = 0;
    string line;
    while (cin >> a >> b) {
        if (a > b){
            tmp2 = a;
            a = b;
            b = tmp2;
            flag = 1;
        }
        for (int i = a; i <= b; i++) {
            tmp = calcula(i);
            if (tmp > max)
                max = tmp;
        }
        if (flag == 1)
            cout << b << ' ' << a << ' ' << max << endl;
        else
            cout << a << ' ' << b << ' ' << max << endl;
        max = 0;
        flag = 0;
    }

    return 0;
}
