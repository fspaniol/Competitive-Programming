#include <bits/stdc++.h>
#include <string.h>
#include <math.h>

using namespace std;

bool is_integer(float k)
{
  return std::floor(k) == k;
}

int main()
{
    long long a, b, max = 0, flag = 0;
    float tmp, tmp2;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        if (a > b){
            tmp2 = a;
            a = b;
            b = tmp2;
        }
        for (int i = a; i <= b; i++) {
            tmp = sqrt(i);
            if (is_integer(tmp) == true) 
                max++;
        }
        cout << max << endl;
        max = 0;
    }

    return 0;
}
