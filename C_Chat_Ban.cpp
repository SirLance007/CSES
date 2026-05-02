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
    int k , x;
    cin >> k >> x;
    int total = k*k;
    // max emote in a row -> k
    // mirror image ke upar
    int sum1 = ((k-1)*k)/2;
    int ans = 0;
    if(sum1 >= x){
        int row = 0;
        int left = 0;
        int right = k-1;
        while(left < right){
            int mid = left + (right-left)/2;
            
        }
    }
    // mirror image wali row par

    // mirror image ke neche wali row par
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