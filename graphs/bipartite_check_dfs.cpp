#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef vector <ll> vi;                 // Vector of long long
typedef vector <vi> vvi;                // Vector of vi
typedef vector <pair<ll,ll>> ii;        // Vector of pairs
#define ff first                        // For pairs
#define ss second                       // For pairs
#define sz(a) int((a).size())           // Function to determine size of any container
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >

ll n, flag = 0;
vvi g;
vi color;

void dfs(ll u)
{

    if (flag == 1)
        return;

    for (auto it: g[u])
    {
        if (color[it] == -1)
            color[it] = 1 - color[u];
        else if (color[it] == color[u])
        {
            flag = 1;
            return;
        }
    }
    
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m;
    cin >> n >> m;

    g.resize(n);
    color.resize(n, -1);

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;

        g[x - 1].pb(y - 1);
        g[y - 1].pb(x - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            dfs(i);
        }

        if (flag == 1)
            break;
    }

    if (flag == 1)
        cout << "-1\n";
    else
    {
        for (auto it: color)
            cout << it << " ";
        cout << "\n";
    }
}
