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

// Observation
// beauty -> bi
// beauty increasing order mai honi chaiye
//

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans.push_back(x);
        st.insert(x);
    }
    // int maxi = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int last;
    //     if (i == 0)
    //     {
    //         last = n - 1;
    //     }
    //     else
    //     {
    //         last = i - 1;
    //     }
    //     int total = 1;
    //     int prev = ans[i];
    //     int idx = i + 1;
    //     while (idx != last)
    //     {
    //         if (ans[idx] > prev)
    //         {
    //             prev = ans[i];
    //             total++;
    //         }
    //         idx = (idx+1)%;
    //     }
    //     maxi = max(maxi, total);
    // }
    // cout << maxi << endl;
    cout << st.size() << endl;
}

int32_t main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}