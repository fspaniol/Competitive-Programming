#include <bits/stdc++.h>
#include <string.h>
#include <math.h>

using namespace std;


int main()
{
    int a, b, c, high = 0, tmp;
    cin >> a >> b >> c;
    if (a > b)
        high = a;
    else
        high = b;
    if (high < c)
        high = c;
    cout << high << " eh o maior" << endl;

    return 0;
}