#include <bits/stdc++.h>

using namespace std;

#define H 999999
typedef pair<int,int> ii;

int n, m, S, T;
int from, to, value;
int c = 1;

int main() {
    int tests;
    cin >> tests;
    int val;
    while(tests--){
        cin >> n >> m >> S >> T;
        vector<vector<ii>> latencies(n, vector<ii>());
        while(m--){
            cin >> from >> to >> value;
            latencies[from].push_back(ii(to,value));
            latencies[to].push_back(ii(from,value));
        }
        vector<int> d(n,H); // distance from S to all others
        d[S] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push(ii(0,S));
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            if(front.first == d[front.second]){
                for(int i = 0; i < latencies[front.second].size(); i++){
                    ii v = latencies[front.second][i];
                    if(d[front.second] + v.second < d[v.first]){
                        d[v.first] = d[front.second] + v.second;
                        pq.push(ii(d[v.first],v.first));
                    }
                }
            } 
        }
        
        if(d[T] == H)
            cout << "Case #" << c++ << ": unreachable" << endl;
        else
            cout << "Case #" << c++ << ": " << d[T] << endl;
    }
    return 0;
}