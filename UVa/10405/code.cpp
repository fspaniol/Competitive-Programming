#include <bits/stdc++.h>

using namespace std;

int pd[1001][1001];
  
int lcs(string s1, string s2) {
    memset(pd, 0, sizeof(pd));
  
    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1] == s2[j-1])
                pd[i][j] = pd[i-1][j-1] + 1;  
            else {
                if(pd[i-1][j] > pd[i][j-1])
                    pd[i][j] = pd[i-1][j];
                else
                    pd[i][j] = pd[i][j-1]; 
            }
        }
    }
   return pd[s1.length()][s2.length()];
}

int main() {
    string s1, s2;
    while(getline(cin,s1)) {
        getline(cin,s2);
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}

