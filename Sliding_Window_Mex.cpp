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

// Approach
// 

void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> ans;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        ans.push_back(x);
    }
    vector<int> op;
    unordered_map<int , int> mp;
    int left = 0;
    int right = 0;
    int mex = 0;
    while(right < n){
        // agar ans mai already mex hai toh next wala mex ho jayega
        if(ans[right] == mex){
            // Now jab tak mex hai tab tak 
            while(mp.find(mex) == mp.end()){
                mex++;
            }
        }
        // freq add kardi
        mp[ans[right]]++;
        // agar size barabar hai toh
        if(right-left+1 == k){
            op.push_back(mex);
            mp[ans[left]]--;
            if(mp[ans[left]] == 0){
                mp.erase(ans[left]);
            }
            if(ans[left] <= mex){
                int freq = mp[ans[left]];
                if(freq == 0){
                    mex = ans[left];
                }
                left++;
            }
        }
        right++;
    }
    for(auto it : op){
        cout << it << " ";
    }
    cout << endl;
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