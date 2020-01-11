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

class Node
{
    public:
        map<pair<ll,ll>,ll> count;
        map<pair<ll,ll>, Node*> next;
};

class Trie
{
    public:
        Node *root;
    
    Trie()
    {
        root = new Node;
    }

    void Insert(string str)
    {
        auto current = root;
        ll sz = str.size();
        for (int i = 0; i < sz; i++)
        {
            current->count[{str[i], str[sz - i - 1]}]++;
            if (current->next[{str[i], str[sz - i - 1]}] == NULL && i != sz - 1)
                current->next[{str[i], str[sz - i - 1]}] = new Node;
            current = current->next[{str[i], str[sz - i - 1]}];
        }
    }

    void DeleteAll(Node *current)
    {
        for (auto i = current->next.begin(); i != current->next.end(); i++)
        {
            if (i->ss != NULL)
                DeleteAll(i->ss);
        }
        delete(current);
    }
};

int main(void)
{
    
}