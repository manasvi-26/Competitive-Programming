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
#define MAX (ll)(1e3 + 5)
string a, b, lcs;
ll dp[MAX][MAX];
ll doit[MAX][MAX];

ll solve(ll i, ll j)
{
    if (i < 0 || j < 0)
        return 0;
    
    if (dp[i][j] == -1)
    {
        ll s1 = solve(i - 1, j - 1) + 1;
        ll s2 = solve(i - 1, j);
        ll s3 = solve(i, j - 1);

        ll ans = 0;
        if (a[i] == b[j])
            ans = max(ans, s1);
        
        ans = max(ans, s2);
        ans = max(ans, s3);

        if (ans == s1 && a[i] == b[j])
            doit[i][j] = 0;
        else if (ans == s2)
            doit[i][j] = 1;
        else
            doit[i][j] = 2;
        dp[i][j] = ans;
    }
    return dp[i][j];
}

void process(ll i, ll j)
{
    if (i < 0 || j < 0)
        return;

    if (doit[i][j] == 0)
        lcs.pb(a[i]), process(i - 1, j - 1);
    else if (doit[i][j] == 1)
        process(i - 1, j);
    else if (doit[i][j] == 2)
        process(i, j - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    solve(a.size() - 1, b.size() - 1);
    process(a.size() - 1, b.size() - 1);

    for (auto it = lcs.rbegin(); it != lcs.rend(); it++)
        cout << *it;
    cout << "\n";
}
