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

vector<int> num;


int main() {
    int entrada;
    bool cresce = 1;
    int cont = 1;
    int val, last;
    int first;
    while (cin >> entrada && entrada != 0) {
        while (entrada--){
            cin >> val;
            num.push_back(val);
        }
        for (int i = 1; i < num.size(); i++) {
            if (num[i] > num[i-1])
                if ( i == 1){
                    cresce = 1;
                    first = 1;
                }
                else {
                    if (cresce == 0) {
                        cresce = 1;
                        cont++;
                    }
                }
            else {
                if ( i == 1) {
                    cresce = 0;
                    first = 0;
                }
                else {
                    if (cresce == 1) {
                        cresce = 0;
                        cont++;
                    }
                }
            }
            
            //cout << num[i-1] << ' ' << num[i] << ' ' << cresce << ' ' << cont << endl;
        }
        if (num[num.size() - 1] > num[0] && cresce == first)
            cont++;
        if (num[num.size() - 1] < num[0] && cresce == first)
            cont++;
        //cout << num[num.size()-1] << ' ' << num[0] << ' ' << cresce << ' ' << cont << endl;
        
        cout << cont << endl;
        
        num.clear();
        cont = 1;
    }
    
    return 0;
}
