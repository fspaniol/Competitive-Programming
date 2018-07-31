#include <bits/stdc++.h>

using namespace std;

int main() {
	long long val[201][201] = {0};
	int n, k;
	val[0][0] = 1;
	for(n = 1; n <= 200; n++) {
		val[n][0] = 1;
		for(k = 1; k <= n; k++)
			val[n][k] = (val[n-1][k-1] + val[n-1][k])%1000000;
	}
    while(cin >> n >> k) {
        if(n == 0 && k == 0)
            break;
        cout << val[n+k-1][k-1] << endl;
    }
    return 0;
}