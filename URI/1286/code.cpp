#include <bits/stdc++.h>

using namespace std;

struct pedido {
    int pizzas;
    int tempo;
};

bool cmp(pedido a, pedido b) {
    return a.tempo > b.tempo;
}

vector<pedido> ped;
int top;
int size;

int dfs(int i, int current){
    if (i == size)
        return 0;
    
    int a, b;
    if(current + ped[i].pizzas <= top){
        a = ped[i].tempo + dfs(i+1, current+ped[i].pizzas);
        b = dfs(i+1, current);
    } else {
        return dfs(i+1, current);
    }
    
    if (a > b)
        return a;
    return b;
}

int main() {
    int pedidos;
    while(cin >> pedidos && pedidos != 0) {
        cin >> top;
        size = pedidos;
        pedido tmp;
        while(pedidos--){    
        cin >> tmp.tempo >> tmp.pizzas;
        ped.push_back(tmp);   
        }
        sort(ped.begin(), ped.end(), cmp);
        cout << dfs(0, 0) << " min." << endl;
        ped.clear();
    }
    return 0;
}

