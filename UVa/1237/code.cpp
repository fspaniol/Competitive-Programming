#include <bits/stdc++.h>

using namespace std;

struct car
{
    string name;
    int lowest;
    int highest;
};

int main()
{
    int testes, entradas, valor, actual;
    cin >> testes;

    while (testes--)
    {
        vector<car> carros;
        cin >> entradas;
        while (entradas--)
        {
            car carro;
            cin >> carro.name >> carro.lowest >> carro.highest;
            carros.push_back(carro);
        }
        cin >> entradas;
        while (entradas--)
        {
            cin >> valor;
            actual = -1;
            for (int i = 0; i < carros.size(); i++)
            {
                if (valor >= carros[i].lowest && valor <= carros[i].highest)
                {
                    if (actual == -1)
                        actual = i;
                    else
                        actual = -2;
                }
            }
            if (actual < 0)
                cout << "UNDETERMINED" << endl;
            else
                cout << carros[actual].name << endl;
        }
        if (testes > 0)
            cout << endl;
    }
    return 0;
}
