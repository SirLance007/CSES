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
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> ans;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        ans.push_back(x);
    }
    vector<int> apartment;
    for(int i = 0; i < m ; i++){
        int x;
        cin >> x;
        apartment.push_back(x);
    }
    sort(ans.begin() , ans.end());
    unordered_set<int> st;
    for(int i = 0; i < n ; i++){
        int one = ans[i]-k;
        int two = ans[i]+k;
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