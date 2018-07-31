#include <bits/stdc++.h>

using namespace std;

int N, M, A, c = 1;
int conn[10005];
int sum, airports;

struct dis{
    int from;
    int to;
    int value;
};

vector<dis> dist;

bool cmp(dis f, dis s){
    if(f.value < s.value)
        return true;
    return false;
}

int parent (int u){
    if(conn[u]==u)return u;
    else return conn[u]= parent(conn[u]);
}

void cl(){
    for(int i = 0; i < 10005; i++){
            conn[i] = i;
    }
    dist.clear();
    sum = 0;
    airports = N;
}

void calc(){
    for(int i = 0; i < dist.size(); i++){
        if(dist[i].value >= A) 
            return;
        int first = parent(dist[i].from);
        int second = parent(dist[i].to);
        if(first != second){
            sum += dist[i].value;
            conn[first] = conn[second];
            if(--airports==1)
                return;
        }
    }
}

int main() {
    int tests, to, from, val;
    cin >> tests;
    dis tmp;
    while(tests--){        
        // receive the data
        cin >> N >> M >> A;
        cl();
        while(M--){
            cin >> tmp.from >> tmp.to >> tmp.value;
            dist.push_back(tmp);
        }
        
        // do your thing
        sort(dist.begin(), dist.end(), cmp);
        calc();
        cout << "Case #" << c++ << ": " << sum+airports*A << " " << airports << endl;
    }   
    
    return 0;
}