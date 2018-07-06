#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    int val, postes, cont;
    while (cin >> postes && postes != 0) {
        cont = 0;
        vector<int> cerca;
        while (postes--) {
            cin >> val;
            cerca.push_back(val);
        }
        
        // preenche lugar onde tem 3 vazios seguidos
        for (int i = 1; i < cerca.size(); i++) {
            if (cerca[i] == 0 && cerca[(i+1) % cerca.size()] == 0 && cerca[i-1] == 0) {
                //cout << i << endl;
                cerca[i] = 1;
                cont++;
                i++;
            }
        }
        
        // preenche o restante
        for (int i = 0; i < cerca.size(); i++) {
            if (cerca[i] == 0 && cerca[(i+1) % cerca.size()] == 0) {
                //cout << i << endl;
                cerca[i] = 1;
                cont++;
            }
        }
        
    cout << cont << endl;       
    }
    
    return 0;
}
