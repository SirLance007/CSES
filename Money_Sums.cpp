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
    int n;
    cin >> n;

    vector<int> coins(n);
    int total = 0;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
        total += coins[i];
    }

    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for(int coin : coins){
        for(int s = total; s >= coin; s--){
            if(dp[s - coin])
                dp[s] = true;
        }
    }

    vector<int> ans;
    for(int s = 1; s <= total; s++){
        if(dp[s]) ans.push_back(s);
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main(){
    fast;
    // int t = 1;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    solve();
    return 0;
}