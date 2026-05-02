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

int op(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    string st = to_string(n);
    int incl = INT_MAX;
    for (int i = 0; i < (int)st.size(); i++)
    {
        if (st[i] - '0' == 0)
        {
            continue;
        }
        incl = min(incl, 1 + op(n - (st[i] - '0'), dp));
    }
    return dp[n] = incl;
}

void solve()
{
    int n;
    cin >> n;
    // current states would be idx to traverse digits of number
    // total
    vector<int> dp(n + 1, -1);
    cout << op(n , dp) << endl;
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