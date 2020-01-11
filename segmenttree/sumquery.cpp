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

class SegmentTree
{
    private:
        vi arr;
        ll n;
    public:
        SegmentTree(vi &in)
        {
            n = in.size();
            arr.resize(2 * n);
            for (int i = 0; i < n; i++)
                arr[i + n] = in[i];
            
            for (int i = n - 1; i > 0; i--)
                arr[i] = arr[i << 1LL] + arr[(i << 1LL) + 1];
        }

        void modify(ll pos, ll val)
        {
            pos += n;
            for (arr[pos] = val; pos > 1; pos >>= 1)
                arr[pos >> 1] = arr[pos] + arr[pos ^ 1];
        }

        ll query(ll l, ll r)
        {
            ll res = 0;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1)
            {
                if (l & 1)
                    res += arr[l++];
                if (r & 1)
                    res += arr[--r];
            }
            return res;
        }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vi in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    
    SegmentTree st(in);

    cout << st.query(1, n) << "\n";
    st.modify(n, 0);
    cout << st.query(3, n) << "\n";    
}