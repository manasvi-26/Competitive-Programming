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
#define ALPHA 26
#define digit(a) (a - 'a')

class Node
{
    public:
        ll count[ALPHA];
        Node *next[ALPHA];
    
    Node()
    {
        for (auto it: next)
            it = NULL;
        for (auto it: count)
            it = NULL;
    }
};

class Trie
{
    public:
        Node *root;
        Trie()
        {
            root = new Node;
        }

        void Insert(string in)
        {
            auto current = root;
            for (auto it: in)
            {
                current->count[digit(it)]++;
                if (!current->next[digit(it)] && it != in[in.size() - 1])
                    current->next[digit(it)] = new Node;
                current = current->next[digit(it)];
            }
        }

        void DeleteAll(Node *current)
        {
            for (auto it: current->next)
                if (it != NULL)
                    DeleteAll(it);
            delete(current);
        }

        ~Trie()
        {
            DeleteAll(root);
        }
};

Trie s;

ll solve()
{
    ll count = 0;
    for (int i = 0; i < 26; i++)
    {
        while(s.root->count[i] >= 2)
        {
            ll check = 0;
            Node *tmp = s.root;
            tmp->count[i] -= 2;
            check++;
            for (int i = 0; i < 26; i++)
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string x;
            s.Insert(x);
        }
        
        s.DeleteAll(s.root);
    }
}