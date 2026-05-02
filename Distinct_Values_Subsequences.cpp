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

// Observation 
// We can make a suffix array indicating number of distinc elements till the index from the last
// After that we can make all the combinations 
// which are n * n-1

// Test case
// 1 2 1 3
// suffix -> 3 3 2 1
// total -> [ 1 , 2 ] [ ]

void solve(){
    int n;
    cin >> n;
    vector<int> ans;
    unordered_set<int , int> st;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        ans.push_back(x);
    }

}

int32_t main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}