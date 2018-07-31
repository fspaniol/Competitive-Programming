#include <bits/stdc++.h>

using namespace std;

int bebidas;
int rest;
int cont = 1;

int main () {
    while(cin >> bebidas) {
        map<string, int> mapBebidas;
        string nomes[105];
        string a, b;
        int aux;
        // cada numero vai ter o seu vector de restricoes
        vector<int> restricoes[105];
        int niveis[105] = {};
        // pega bebidas
        for(int i = 0; i < bebidas; i++){
            cin >> nomes[i];
            mapBebidas[nomes[i]] = i;
        }
        // pega restricoes
        cin >> rest;
        for (int i = 0; i < rest; i++) {
            cin >> a >> b;
            restricoes[mapBebidas[a]].push_back(mapBebidas[b]);
            niveis[mapBebidas[b]]++;
        }
        
        cout << "Case #" << cont << ": Dilbert should drink beverages in this order:";
       
        priority_queue<int, vector<int>, greater<int> > ordem;
        for(int i = 0; i < bebidas; i++)
            if(niveis[i] == 0) {
                ordem.push(i);
            }
        while(!ordem.empty()) {
            int top = ordem.top();
            ordem.pop();
            for(int i = 0; i < restricoes[top].size(); i++) {
                niveis[restricoes[top][i]]--;
                if(niveis[restricoes[top][i]] == 0)
                    ordem.push(restricoes[top][i]);
            }
            cout << " " << nomes[top];
        }
        
        cout << "." << endl << endl;
        cont++;
    }
    return 0;
}