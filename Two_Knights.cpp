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

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int size = i * i;
        int allWays = size * (size - 1) / 2;
        int badWays = 0;
        badWays += 8 * (i - 4) * (i - 4);
        badWays += 6 * (i-4)*4;
        badWays += 4 * (i-3) * 4;
        badWays += 3 * 8;
        badWays += 2 * 4;
        badWays /= 2;
        cout << allWays - badWays << endl;
    }
}

int32_t main()
{
    fast;
    // int t = 1;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
    // return 0;
}