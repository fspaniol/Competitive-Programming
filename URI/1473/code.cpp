#include <bits/stdc++.h>

using namespace std;

map<int,bool> val;

int main(){
	int linhas, colunas, cont = 0;

	cin >> linhas >> colunas;
	int val[linhas+1][colunas+1];
	int dl = 0;
	int dx = 0;
	int aux;

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			cin >> val[i][j];
		}
	}

	for (int i = 0; i < linhas; i++) {
		aux = (val[i][0] - 1) / colunas;
		for(int j = 0; j < colunas; j++) {
			if ((val[i][j] - 1) / colunas != aux){
				//cout << val[i][0] << ' ' << val[i][j] << ' ' << aux << endl;
				cont += 100000;
			}
			if (val[i][j] != (aux * colunas) + j+1){
				//cout << val[i][j] << ' ' << aux << endl;
				//cout << (aux * colunas) + j+1 << endl;
				dl++;
			}
		}
	}
	//cout << dl << endl;
	dl = dl / linhas;

	for (int j = 0; j < colunas; j++) {
		aux = val[0][j] % colunas;
		for(int i = 0; i < linhas; i++) {
			if (val[i][j] % colunas != aux){
				//cout << val[0][j] << ' ' << val[i][j] << ' ' << aux << endl;
				cont += 100000;
			}
			if (aux == 0)
				aux = colunas;
			if (val[i][j] != (colunas * i) + aux) {
				//cout << val[i][j] << ' ' << aux << ' ' << (colunas * i) + aux<< endl;
				dx++;
			}
			if (aux == colunas)
				aux = 0;
		}
	}
	
	//cout << dx << endl;
	dx = dx / colunas;
	//cout << dl << ' ' << dx << endl;
	//cout << dl << ' ' << dx << endl;
	if (dx > 0)
		cont += dx - 1;

	if (dl > 0)
		cont += dl - 1;
	
	if ( cont >= 100000)
		cout << '*' << endl;
	else
		cout << cont << endl;
	return 0;
}
