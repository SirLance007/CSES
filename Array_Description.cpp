// Hare Krishna
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
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    const int MOD = 1e9 + 7;

    vector<int> prev(m + 2, 0), curr(m + 2, 0);

    // Base case
    if(x[0] == 0){
        for(int v = 1; v <= m; v++) prev[v] = 1;
    } else {
        prev[x[0]] = 1;
    }

    // DP transitions
    for(int i = 1; i < n; i++){
        fill(curr.begin(), curr.end(), 0);

        for(int v = 1; v <= m; v++){

            if(x[i] != 0 && x[i] != v) continue;

            curr[v] = (prev[v] + prev[v-1] + prev[v+1]) % MOD;
        }

        prev = curr;
    }

    int ans = 0;
    for(int v = 1; v <= m; v++){
        ans = (ans + prev[v]) % MOD;
    }

    cout << ans << "\n";
}

int32_t main(){
    fast;
    // int t = 1;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}