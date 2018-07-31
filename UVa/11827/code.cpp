#include <bits/stdc++.h>

using namespace std;

long gcd1(long p, long q) {
if (q > p) return(gcd1(q,p));
if (q == 0) return(p);
return( gcd1(q, p % q) );
}

int main() {
    int testes;
    cin >> testes;
    int val;
            string input;
    getline(cin, input);
    
    while(testes--){
        int max = 0;
        int aux;
        vector<int> valores;
       
        getline(cin, input);
         stringstream ss(input);
        while(ss >> val)
            valores.push_back(val);
        for(int i = 0; i < valores.size(); i++){
            for(int j = i+1; j < valores.size(); j++){
                aux = gcd1(valores[i],valores[j]);
                if(aux > max)
                    max = aux;
            }
        }
        
        cout << max << endl;
    }
    return 0;
}