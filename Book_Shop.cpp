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
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

// int op(int idx, int x, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp)
// {
//     if (idx >= prices.size())
//     {
//         return 0;
//     }
//     if (x < 0)
//     {
//         return INT_MIN;
//     }
//     if (dp[idx][x] != -1)
//     {
//         return dp[idx][x];
//     }
//     int incl = INT_MIN;
//     if(x - prices[idx] >= 0){
//         incl = pages[idx] + op(idx + 1, x - prices[idx], prices, pages, dp);
//     }
//     int excl = op(idx+1 , x , prices , pages , dp);
//     return dp[idx][x]= max(incl , excl);
// }
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);

    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }

    cout << dp[x] << endl;
}

int32_t main()
{
    fast;
    // int t = 1;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    solve();
    return 0;
}