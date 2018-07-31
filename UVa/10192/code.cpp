#include <bits/stdc++.h>

using namespace std;
string f;
string s;
int cont = 0;
int dp[101][101];

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int dfs(int i, int j) {
    if (i > f.size() || j > s.size())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int res;
    if (f[i] == s[j])
        res = 1 + dfs(i+1,j+1);
    else
        res = max(dfs(i+1,j),dfs(i,j+1));
    
    dp[i][j] = res;
    
    return res;
}

void clean() {
    for(int i = 0; i < 101; i++){
        for(int j=0; j < 101; j++)
            dp[i][j] = -1;
    }
}

int main() {
    
    while(getline(cin,f) && f != "#") {
        getline(cin,s);
        cont++;
        clean();
        cout << "Case #" << cont << ": you can visit at most " << dfs(0,0)-1 << " cities." << endl;
    }
    
}