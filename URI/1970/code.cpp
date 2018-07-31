#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
vvvvi M;

int getM(int i, int cart1, int cart2, int cart3) {
    if(cart1 < 0 || cart2 < 0 || cart3 < 0) return -1;
    if(i == 0) return 0;
    return M[i][cart1][cart2][cart3];
}

int iter(int n, vi& dura, int cart1, int cart2, int cart3) {
    for(int i = 0; i <= n; i++) {
        vvvi v3i;
        M.push_back(v3i);
        for(int c1 = 0; c1 <= cart1 ; c1++) {
            vvi v2i;
            M[i].push_back(v2i);
            for(int c2 = 0; c2 <= cart2 ; c2++) {
                vi v1i(cart3+1);
                M[i][c1].push_back(v1i);
//                 for(int c3 = 0; c3 <= cart3 ; c3++) {
                    
//                 }
            }
        }
    }
    for(int c1 = 0; c1 <= cart1 ; c1++) {
        for(int c2 = 0; c2 <= cart2 ; c2++) {
            for(int c3 = 0; c3 <= cart3 ; c3++) {
                for(int i = 1 ; i <= n; i++) {
                    bool maior = false;
                    if(dura[i] > c1 && dura[i] > c2 && dura[i] > c3){
                        maior = true;
                    }
                    vi v {c1, c2, c3};
                    if(maior) {
                         M[i][c1][c2][c3] = getM(i-1, c1, c2, c3);
                    } else {
                        int a = -1, b = -1, c= -1 , d= -1 ;
                        a = getM(i-1, c1, c2, c3);
                        if(dura[i] <= c1) {
                            b = dura[i] + getM(i-1, c1 - dura[i], c2, c3);
                        }
                        if(dura[i] <= c2) {
                            c = dura[i] + getM(i-1, c1, c2 - dura[i], c3);
                        }
                        if(dura[i] <= c3) {
                            d = dura[i] + getM(i-1, c1, c2, c3 - dura[i]);
                        }
                        M[i][c1][c2][c3] = max(a, max(b, max(c, d)));
                    }
                }
            }
        }
    }
    
    return getM(n, cart1, cart2, cart3);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vi duracoes, cartuchos;
    duracoes.push_back(0);
    for(int i = 0 ; i < n;i++) {
        int a; cin >> a;
        duracoes.push_back(a);
    }
    for(int i = 0 ; i < k;i++) {
        int a; cin >> a;
        cartuchos.push_back(a);
    }
    cout << iter(n, duracoes, cartuchos[0],  k > 1? cartuchos[1] : 0, k > 2? cartuchos[2] : 0) << endl;
    return 0;
}
