// Code by Prankur Sharma
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> ans(n);
    ans[0] = x;
    for (int i = 1; i < n; i++) 
        ans[i] = (ans[i-1]*a + b) % c;

    deque<int> dq; // store indices of elements
    int total = 0;

    for (int i = 0; i < n; i++) {
        // Remove all elements from back >= current element
        while (!dq.empty() && ans[dq.back()] >= ans[i]) 
            dq.pop_back();

        dq.push_back(i);

        // Remove elements outside the window
        if (dq.front() <= i - k) 
            dq.pop_front();

        // Window formed
        if (i >= k - 1) 
            total ^= ans[dq.front()];
    }

    cout << total << "\n";
}

int32_t main() {
    fast;
    solve();
}
