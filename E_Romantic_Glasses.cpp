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
    vector<int> ans;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        if((i+1)%2 == 0){
            ans.push_back(x);
        }
        else{
            ans.push_back(-1*x);
        }
    }
    vector<int> prefix(n , 0);
    prefix[0] = ans[0];
    set<int> mp;
    mp.insert(ans[0]);
    for(int i = 1; i < n ; i++){
        prefix[i] = prefix[i-1]+ ans[i];
        if(mp.find(prefix[i]) != mp.end()){
            cout << "YES" << endl;
            return;
        }
        mp.insert(prefix[i]);
        if(prefix[i] == 0){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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