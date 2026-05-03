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

int op(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= (int)nums1.size() || j >= (int)nums2.size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (nums1[i] == nums2[j])
    {
        return dp[i][j] = 1 + op(nums1, nums2, i + 1, j + 1, dp);
    }
    else
    {
        return dp[i][j] = max(
            op(nums1, nums2, i + 1, j, dp),
            op(nums1, nums2, i, j + 1, dp)
        );
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n); // optimized input logic a bit
    vector<int> nums2(m);
    
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    // 1. Fill the DP table and get the max length
    int ans1 = op(nums1, nums2, 0, 0, dp);
    cout << ans1 << endl;

    vector<int> pencho;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (nums1[i] == nums2[j]) {
            // If they match, it's part of the subsequence! Move diagonally.
            pencho.push_back(nums1[i]);
            i++;
            j++;
        } else if (op(nums1, nums2, i + 1, j, dp) > op(nums1, nums2, i, j + 1, dp)) {
            // If dropping nums1[i] gives a better length, move down
            i++;
        } else {
            // Otherwise, move right
            j++;
        }
    }

    for (auto it : pencho)
    {
        cout << it << " ";
    }
    cout << endl;
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