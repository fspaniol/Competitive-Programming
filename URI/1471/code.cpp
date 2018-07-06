#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
	int num, voltou;
	cin >> num >> voltou;
	int mapa[num+5] = {0};
	int aux;
	bool flag = false;
	if (num == voltou)
		flag = true;
	for (int i = 0; i < voltou; i++){
		cin >> aux;
		mapa[aux] = 1;
	}
	if (flag == false) {
		for (int i = 1; i <= num; i++){
			if (mapa[i] == 0)
				cout << i << ' ';
		}
		cout << endl;
	} else {
		cout << '*' << endl;
	}

	return 0;

}
