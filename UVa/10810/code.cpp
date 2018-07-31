#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll quickSort(ll arr[], ll temp[], int left, int mid, int right)
{
    ll inversoes = 0;
 
    ll i = left, j = mid, k = left; 
    
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inversoes = inversoes + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inversoes;
}

ll quick(ll arr[], ll temp[], int left, int right)
{
    ll mid, inv_count = 0;
    if (right > left)
    {
        
        mid = (right + left)/2;
        inv_count  = quick(arr, temp, left, mid);
        inv_count += quick(arr, temp, mid+1, right);
 
        inv_count += quickSort(arr, temp, left, mid+1, right);
    }
 
    return inv_count;
}
 
int main()
{
    int n;
    while(cin >> n && n!= 0) {
        int vecSize = n;
        ll v[vecSize], aux[vecSize];
        for(int i = 0 ; i < n;i++) {
            cin >> v[i];
        }
        cout << quick(v, aux, 0, vecSize - 1) << endl;        
    }
}
