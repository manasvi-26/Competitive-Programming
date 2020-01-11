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

ll n;
vvi g;
vi visit;
queue <ll> q;

void bfs(void)
{
    if (q.empty())
        return;

    ll u = q.front();
    q.pop();

    if (visit[u] == 0)
        cout << u + 1 << " ";
    visit[u] = 1;

    for (auto it: g[u])
    {
        if (visit[it] == 0)
            q.push(it);
    }

    bfs();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m;
    cin >> n >> m;
    g.resize(n);
    visit.resize(n, 0);

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;

        g[x - 1].pb(y - 1);
        g[y - 1].pb(x - 1);
    }

    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            count++;
            cout << "Component " << count << ": ";
            q.push(i);
            bfs();
            cout << "\n";
        }
    }
}
