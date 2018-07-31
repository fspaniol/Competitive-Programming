#include <bits/stdc++.h>

using namespace std;

struct rota {
    string origem;
    string destino;
    int distancia;
} rotas[80000];

int visitados[500];


bool bigger(rota i, rota j) {
    if(i.distancia < j.distancia)
        return true;
    return false;
}

int checkOrigin(int n){
    if (visitados[n] == n)
        return n;
    return visitados[n] = checkOrigin(visitados[n]);
}

int main () {
    
    int e, r;
    string s;
    string start;
    while(cin >> e >> r && e != 0) {
        map<string,int> index;
        for (int i = 0; i < 500; i++)
            visitados[i] = i;
        
        // Get stations
        for(int i = 0; i < e; i++){
            cin >> s;
            index[s] = i;
        }
        
        // Get routes
        for(int i = 0; i < r; i++){
            rota x;
            cin >> x.origem >> x.destino >> x.distancia;
            rotas[i] = x;
        }
        
        // Get where we are starting
        cin >> start;
        
        // Ordena o vetor de rotas para começar a pegar as menores primeiro
        sort(rotas, rotas+r, bigger);
        
        int sum = 0;
        int nodos = e - 1;
        
        // Usa todas as menores rotas enquanto algum dos dois pontos não tiver sido conectado
        for(int i = 0; i < r && nodos; i++){
            int a = checkOrigin(index[rotas[i].origem]);
            int b = checkOrigin(index[rotas[i].destino]);
            if(a != b) {
                visitados[a] = b;
                nodos--;
                sum += rotas[i].distancia;
                //cout << rotas[i].origem << " " << rotas[i].destino << " " << rotas[i].distancia << endl;
            }
        }
        // Imprime o resultado
        if ( !nodos )
            cout << sum << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}