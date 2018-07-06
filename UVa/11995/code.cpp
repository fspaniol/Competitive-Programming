#include <bits/stdc++.h>

using namespace std;

queue<int> lista;
stack<int> pilha;
priority_queue<int> prior;

void clean1(queue<int> &q)
{
    queue<int> empty;
    swap(q, empty);
}

void clean2(stack<int> &q)
{
    stack<int> empty;
    swap(q, empty);
}

void clean3(priority_queue<int> &q)
{
    priority_queue<int> empty;
    swap(q, empty);
}

int main()
{
    int k, a, b;
    int queue = 1, stack = 1, prio = 1;
    int sum;

    while (cin >> k)
    {
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            if (a == 1)
            {
                lista.push(b);
                pilha.push(b);
                prior.push(b);
            }
            else
            {
                if (lista.size() == 0)
                {
                    queue = 0;
                    stack = 0;
                    prio = 0;
                }
                else
                {
                    if (b != lista.front())
                        queue = 0;
                    if (b != pilha.top())
                        stack = 0;
                    if (b != prior.top())
                        prio = 0;

                    //cout << b << ' ' << lista.front() << ' ' << pilha.top() << ' ' << prior.top() << endl;

                    lista.pop();
                    pilha.pop();
                    prior.pop();
                }
            }
        }
        sum = queue + stack + prio;
        if (sum == 0)
            cout << "impossible" << endl;
        if (sum > 1)
            cout << "not sure" << endl;
        if (sum == 1)
        {
            if (stack == 1)
                cout << "stack" << endl;
            if (queue == 1)
                cout << "queue" << endl;
            if (prio == 1)
                cout << "priority queue" << endl;
        }
        clean1(lista);
        clean2(pilha);
        clean3(prior);
        queue = 1, stack = 1, prio = 1;
    }
    return 0;
}