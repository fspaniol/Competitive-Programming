#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ent[4];
    for (int i = 0; i < 4; i++)
        cin >> ent[i];
    
    sort(ent,ent+4);
    
    int teama = ent[0] + ent[3];
    int teamb = ent[1] + ent[2];
    int s = teama - teamb;
    if(s < 0)
        s *= -1;
    cout << s << endl;

    return 0;
}
