#include <bits/stdc++.h>

using namespace std;

map<int,bool> val;

int main(){
	int pontos;
	cin >> pontos;
	int sum = 0;
	int cont = 0;
	int aux;
	int eq[pontos];
	for (int i = 0; i < pontos; i++){
		cin >> aux;
		sum += aux;
		eq[i] = sum;
		val[sum] = true;
	}
	val[0] = val[sum];
	int distance = sum / 3;
	for (int i = 0; i < pontos; i++) {
		if(val[(eq[i]+distance) % sum] && val[(eq[i] + 2 * distance) % sum])
			cont++;
	}
	cout << cont / 3 << endl;
	return 0;
}
