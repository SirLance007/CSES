// Hare Krishna
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

long long op(long long  n , vector<long long> &dp){
    // cout << n << endl;
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    long long one = op(n-1 , dp);
    long long two = op(n-2 , dp);
    long long three = op(n-3 , dp);
    long long four = op(n-4 , dp);
    long long five = op(n-5 , dp);
    long long six = op(n-6 , dp);
    long long ans = (one + two + three + four + five + six)%1000000007;
    return dp[n] = ans;
}

void solve(){
    long long n;
    cin >> n;
    vector<long long> dp(n+1 , -1);
    cout << op(n , dp) << endl;
}

int32_t main(){
    fast;
    // int t = 1;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    solve();
    return 0;
}