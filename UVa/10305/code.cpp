#include <bits/stdc++.h>

using namespace std;

void DFS(int n, int visit[],vector<int> preferencias[], vector<int> &resp)
{
    if (visit[n] == 1) return;
    visit[n] = 1;

    for ( int i = 0; i < preferencias[n].size(); i++) {
        if (visit[preferencias[n][i]] != 2)
            DFS(preferencias[n][i], visit, preferencias, resp);
    }
    visit[n] = 2;
    resp.push_back(n);
}

int main()
{
    int n, m, i, j;
    while (cin >> n >> m){
        if (n == 0 && m == 0)
            return 0;
        vector<int> preferencias[101];
        vector<int> resp;
        bool ja[101] = {0};
        int visit[101] = {0};
        while (m--) {
            cin >> i >> j;
            preferencias[i].push_back(j);
            ja[j] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!ja[i]) // só faz DFS se não tiver sido preferencia de alguem
                DFS(i ,visit, preferencias, resp);
        }
        
        for (int i = resp.size()-1; i >= 0; i--)
            cout << resp[i] << ' ';
        cout << endl;
        
    }
    
    return 0;
}

