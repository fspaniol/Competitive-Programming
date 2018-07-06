#include <bits/stdc++.h>

using namespace std;

vector<int> entries;
vector<int> sum;

int main() {
     long long a, b;
     long long diff;
    long long num;
    long long cost = 0;
    long long partial = 0;
    
    while (cin >> a && a != 0){
        for (int x = 0; x < a; x++){
            cin >> num;
            entries.push_back(num);
        }
        
        for(int i = 0; i < entries.size()-1; i++){
            sort(entries.begin(),entries.end());
            cost = entries[i] + entries[i+1];
            entries[i+1] = cost;
            partial += cost;        
        }
        cout << partial << endl;
        entries.clear();
        partial = 0;
    }
    return 0;
}
