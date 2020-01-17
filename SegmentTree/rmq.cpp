//ltc.groverkss (Kunwar Shaanjeet Singh Grover)
//IIIT Hyderabad
// Mehul Mathur randi hain

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef pair<ll,ll> ii;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<ii> vii;                 // Vector of pairs
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

class SegmentTree
{
    private:
        vi st;
        ll n;
    public:
        SegmentTree(ll N)
        {
            n = N;
            st.resize(4 * n);
        }

        void build(vi &arr, ll left, ll right, ll pos = 1)
        {
            if (left == right)
                st[pos] = arr[left];
            else
            {
                ll mid = (left + right) / 2;
                build(arr, left, mid, pos << 1LL);
                build(arr, mid + 1, right, (pos << 1LL) + 1);
                st[pos] = min(st[pos << 1LL], st[(pos << 1LL) + 1]);
            }
        }

        ll rmq(ll l, ll r, ll left, ll right, ll pos = 1)
        {
            if (l > r)
                return LLONG_MAX;
            if (l == left && r == right)
                return st[pos];
            ll mid = (left + right) / 2;
            return min(rmq(l, min(r, mid), left, mid, pos << 1LL), rmq(max(l, mid + 1), r, mid + 1, right, (pos << 1LL) + 1));
        }

        void update(ll val, ll index, ll left, ll right, ll pos = 1)
        {
            if (left == right)
                st[pos] = val;
            else
            {
                ll mid = (left + right) / 2;
                if (mid <= right)
                    update(val, index, left, mid, pos << 1LL);
                else
                    update(val, index, mid + 1, right, (pos << 1LL) + 1);
                st[pos] = min(st[pos << 1LL], st[(pos << 1LL) + 1]);
            }
        }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    SegmentTree s(n);
    s.build(arr, 0, n - 1);

    ll q;
    cin >> q;
    while(q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            cout << s.rmq(x, y, 0, n - 1) << "\n";
        }
        else
        {
            ll index, value;
            cin >> index >> value;
            index--;
            s.update(value, index, 0, n - 1);
        }
        
    }
}
