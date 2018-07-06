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
    int carros, espaco, val, val2, poss = 1, last, cur;
    while (cin >> carros >> espaco && carros != 0) {
        stack<int> pilha;
        while (carros--){
            cin >> val >> val2;
            while(pilha.size() > 0 && pilha.top() <= val){
                pilha.pop();
            }
            if (pilha.size() > 0 && pilha.top() < val2)
                poss = 0;
            pilha.push(val2);
                
            if (pilha.size() > espaco)
                poss = 0;
            
        }
        
        if (poss == 1)
            cout << "Sim" << endl;
        else
            cout << "Nao" << endl;
        
        poss = 1;
        
    }
    
    return 0;
}
