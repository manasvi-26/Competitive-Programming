#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
typedef vector <ll> vi;                 // Vector of long long
typedef vector <vi> vvi;                // Vector of vi
typedef vector <pair<ll,ll>> vp;        // Vector of pairs
#define sz(a) int((a).size())           // Function to determine size of any container
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index

void merge(ll arr[], ll l, ll m, ll r);
void mergesort(ll arr[], ll l, ll r);

int main(void)
{
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void merge(ll arr[], ll l, ll m, ll r)
{
    ll n1 = m - l + 1;
    ll n2 = r - m;

    ll L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[n1 + l + i];
    
    ll i = 0, j = 0, k = l;
    while(i != n1 && j != n2)
    {
        if (L[i] > R[j])
            arr[k] = R[j], j++, k++;
        else
            arr[k] = L[i], i++, k++;
    }

    while(i != n1)
        arr[k] = L[i], k++, i++;
    
    while(j != n2)
        arr[k] = R[j], k++, j++;
}

void mergesort(ll arr[], ll l, ll r)
{
    if (r != l)
    {
        ll m = (r + l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}