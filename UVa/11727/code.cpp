#include <bits/stdc++.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    long long a, b, c, max = 0, flag = 0, entries;
    float tmp, tmp2;
    cin >> entries;
    for(int i = 0; i < entries; i++) {
        cin >> a >> b >> c;
        if ((a > b && a < c) || (a > c && a < b))
            cout << "Case " << i+1 << ": " << a << endl;
        if ((b > a && b < c) || (b > c && b < a))
            cout << "Case " << i+1 << ": " << b << endl;
        if ((c > b && a > c) || (c > a && b > c))
            cout << "Case " << i+1 << ": " << c << endl;
    }

    return 0;
}
