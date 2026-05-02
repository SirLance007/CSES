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

int op(int row, int col, vector<vector<char>> &ans, vector<vector<int>> &dp)
{
    int n = ans.size();
    int m = ans[0].size();
    if (row < 0 || row >= n || col >= m || col < 0)
    {
        return 0;
    }
    if (ans[row][col] == '*')
    {
        return 0;
    }
    if (row == n - 1 && col == m - 1)
    {
        return 1;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int right = op(row, col + 1, ans, dp);
    int bottom = op(row + 1, col, ans, dp);
    dp[row][col] = (right + bottom) % 1000000007;
    return dp[row][col];
}

void solve()
{
    int n;
    cin >> n;
    
    vector<vector<char>> ans(n , vector<char> (n));
    vector<vector<int>> dp(n+1 , vector<int> (n+1  , -1));
    if(ans[0][0] == '*'){
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            ans[i][j] = x;
        }
    }
    cout << op(0, 0, ans, dp) << endl;
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