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
    string st;
    cin >> st;
    int n = st.size();
    for(int i = 1 ; i < n ; i++){
        if(st[i-1] == st[i]){
            char prev = st[i-1];
            char next = (i+1 < n) ? st[i+1] : '\0'; 
            char newChar = prev + 1;
            if(newChar > 'z') newChar = 'a';
            if(next && newChar == next){ 
                newChar++;
                if(newChar > 'z') newChar = 'a';
            }
            st[i] = newChar;
        }
    }
    cout << st << endl;
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