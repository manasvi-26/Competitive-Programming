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
string a, b;
ll dp[MAX][MAX];

ll solve(ll i, ll j)
{
    if (i < 0 || j < 0)
        return max(i + 1, j + 1);
    
    if (dp[i][j] == -1)
    {
        ll ans = (ll)(1e12);
        if (a[i] == b[j])
            ans = min(ans, solve(i - 1, j - 1));
        
        ans = min(ans, solve(i - 1, j - 1) + 1);
        ans = min(ans, solve(i - 1, j) + 1);
        ans = min(ans, solve(i, j - 1) + 1);

        dp[i][j] = ans;
    }
    return dp[i][j];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << solve(a.size() - 1, b.size() - 1) << "\n";    
}
