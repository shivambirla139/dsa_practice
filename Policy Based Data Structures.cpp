#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ================= ORDERED SET =================
// Unique elements, sorted + order statistics
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

/*
USAGE:

ordered_set<int> st;

st.insert(x);                  // insert
st.erase(x);                   // erase
st.find(x);                    // iterator

st.order_of_key(x);            // count of elements < x
st.find_by_order(k);           // iterator to k-th (0-based)
*st.find_by_order(k);          // value at k

// NOTES:
- No duplicates
- O(log N)
*/


// ================= ORDERED MULTISET =================
// Allows duplicates using (value, unique_id)
template<typename T>
using ordered_multiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

/*
USAGE:

ordered_multiset<int> ms;
int id = 0;

ms.insert({x, id++});          // insert duplicate

ms.order_of_key({x, 0});       // count elements < x
ms.find_by_order(k);           // iterator to k-th
ms.erase(ms.lower_bound({x,0})); // erase one occurrence

// NOTES:
- pair ensures uniqueness
*/


// ================= HASH TABLE (FAST MAP) =================
template<typename K, typename V>
using hash_map = gp_hash_table<K, V>;

/*
USAGE:

hash_map<int,int> mp;

mp[key] = value;
mp[key];                       // access

// NOTES:
- Faster than unordered_map
*/


// ================= HASH SET =================
template<typename T>
using hash_set = gp_hash_table<T, null_type>;

/*
USAGE:

hash_set<int> st;

st.insert(x);
st.find(x);

// NOTES:
- Similar to unordered_set
*/


// ================= PBDS PRIORITY QUEUE =================
template<typename T>
using pbds_pq = __gnu_pbds::priority_queue<T>;

/*
USAGE:

pbds_pq<int> pq;

auto it = pq.push(x);          // insert, returns iterator
pq.top();                      // max element
pq.pop();                      // remove top

pq.modify(it, new_val);        // update value

// NOTES:
- Supports update via iterator (unlike STL pq)
*/


void solveTestcase() {
 
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        if (fopen("in.txt", "r")) {
            freopen("in.txt", "r", stdin);
            freopen("out.txt", "w", stdout);
        }
    #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Test Case : " << i << endl;
        solveTestcase();
        // cout << endl << endl;
    }
}
