#include <bits/stdc++.h>

using namespace std;

int caso = 1;

int main() {
    int tests;
    cin >> tests;
    string entrada;
    while (tests--){
        int sum = 0;
        int restos[3] = {0};
        cin >> entrada;
        for(int i = 0; i < entrada.length(); i++){
            sum += entrada[i] - 48;
            restos[(entrada[i] - 48) % 3]++;
        }
        
        int turnos = 0;
        
        if(sum % 3 != 0 && restos[sum % 3] > 0){
            turnos++;
            restos[sum % 3]--;
        }
        
        if(turnos > 0 || sum  % 3 == 0)
            turnos += restos[0];
        if((restos[1] == 1 && restos[2] == 0) || (restos[1] == 0 && restos[2] == 1))
            turnos++;
        if(turnos % 2 == 0)
            cout << "Case " << caso++ << ": T" << endl;
        else
            cout << "Case " << caso++ << ": S" << endl;
    }
    return 0;
}