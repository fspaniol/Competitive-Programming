#include <bits/stdc++.h>

using namespace std;

bool pr[1000001];
vector<int> primos;

void preenche(){
    pr[0] = false;
    pr[1] = false;
    memset(pr,true,1000000);
    
    for(int i=4;i<1000001;i+=2) 
        pr[i] = false;
    
    for(int i=3;i<1000000;i+=2){
        if(pr[i]){
            if(i<500000) {
                primos.push_back(i);
            }
            for(int j=2;j*i<1000000;j++) 
                pr[i*j] = false;
        }
    }
}

int main() {
    int val;
    int a, b;
    preenche();
    while(cin >> val && val != 0){
        int i = 0;
        while(true){
            a = primos[i];
            b = val - a;
            if(pr[b])
                break;
            i++;
        }
        cout << val << " = " << a << " + " << b << endl;
    }
    return 0;
}