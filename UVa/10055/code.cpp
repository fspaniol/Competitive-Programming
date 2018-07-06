#include <bits/stdc++.h>

using namespace std;

int main() {
     long long a, b;
     long long diff;
    while (cin >> a >> b){
        diff = b - a;
        if (diff < 0)
            diff *= -1;
        cout << diff << endl;
    }
    return 0;
}
