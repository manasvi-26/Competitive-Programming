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

int main(void)
{
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

