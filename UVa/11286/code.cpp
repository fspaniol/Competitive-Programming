#include <bits/stdc++.h>

using namespace std;

map<vector<int>,int> pares;
vector<int> estudantes;

int main() {
    int entrada = 0;
    int curso;
    int max = 0;
    int diff = 1;
    vector<int> maior;
    while (cin >> entrada && entrada != 0) {
        for (int x = 0; x < entrada; x++) {
            for (int y = 0; y < 5; y++) {
                cin >> curso;
                estudantes.push_back(curso);
            }
            sort(estudantes.begin(), estudantes.end());
            pares[estudantes]++;
            //cout << estudantes[0] << ' ' << estudantes[1] << ' ' << estudantes[2] << ' ' << estudantes[3] << ' ' << estudantes[4]  << ' ' << pares[estudantes] << endl;
            if (pares[estudantes] == max && maior != estudantes)
                diff++;
            if (pares[estudantes] > max) {
                max = pares[estudantes];
                diff = 1;
                maior = estudantes;
            }
            estudantes.clear();
        }
        pares.clear();
        //cout << max << ' ' << diff << endl;
        cout << max * diff << endl;
        max = 0;
        diff = 1;
    }
    return 0;
}
