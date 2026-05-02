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
    int n , k;
    cin >> n >> k;
    int x , a , b , c;
    cin >> x >> a >> b >> c;
    vector<int> ans;
    int last = x;
    ans.push_back(x);
    for(int i = 1; i <= n ; i++){
        int val = (last*a + b)%c;
        ans.push_back(val);
        last = val;
    }
    vector<int> op;
    int sum = 0;
    int left = 0;
    int right = 0;
    while(right < n){
        sum += ans[right];
        if(right - left + 1 == k){
            op.push_back(sum);
            sum -= ans[left];
            left++;
        }
        right++;
    }
    int total = op[0];
    for(int i = 1 ; i < op.size() ; i++){
        total = total ^ op[i];
    }
    cout << total << endl;
}

int32_t main(){
    fast;
    // int t = 1;
    // cin >> t;
    // while(t--){
        solve();
    // }
    // return 0;
}