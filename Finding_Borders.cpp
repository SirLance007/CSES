// Code by Prankur Sharma
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
using namespace std;

#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

const int MOD = 1e9 + 7;
const int BASE = 131;

void solve() {
    string st;
    cin >> st;
    int n = st.size();

    vector<int> pow_base(n + 1, 1), prefix_hash(n + 1, 0), suffix_hash(n + 1, 0);

    // Precompute powers
    for (int i = 1; i <= n; i++) {
        pow_base[i] = (pow_base[i - 1] * BASE) % MOD;
    }

    // Prefix hash (left to right)
    for (int i = 0; i < n; i++) {
        prefix_hash[i + 1] = (prefix_hash[i] * BASE + st[i]) % MOD;
    }

    // Suffix hash (right to left)
    for (int i = n - 1; i >= 0; i--) {
        suffix_hash[i] = (suffix_hash[i + 1] * BASE + st[i]) % MOD;
    }

    // Check for prefix == reversed suffix
    for (int len = 1; len < n; len++) {
        // prefix hash of [0..len-1]
        int pre = prefix_hash[len];

        // reversed suffix hash of [n-len..n-1]
        int suf = (suffix_hash[n - len] - suffix_hash[n] * pow_base[len] % MOD + MOD) % MOD;

        if (pre == suf) cout << len << " ";
    }
    cout << endl;
}

int32_t main()
{
    fast;
    // int t = 1;
    // cin >> t;
    // while(t--){
    solve();
    // }
    // return 0;
}