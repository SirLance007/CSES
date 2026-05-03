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

// I completed your 'op' function to handle the BFS frontier logic
string op(vector<vector<char>> &grid, int n) {
    string result = "";
    result += grid[0][0];

    // Track active cells (the "frontier")
    vector<pair<int, int>> active;
    active.push_back({0, 0});
    
    // Visited array to prevent TLE by not processing the same cell twice
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    // A valid path takes exactly 2*n - 2 steps
    for (int step = 0; step < 2 * n - 2; step++) {
        char min_char = 'Z' + 1; 
        vector<pair<int, int>> next_candidates;

        // 1. Gather all valid right and down neighbors
        for (auto it : active) {
            int r = it.first;
            int c = it.second;

            // Check Down
            if (r + 1 < n && !visited[r + 1][c]) {
                visited[r + 1][c] = true;
                next_candidates.push_back({r + 1, c});
            }
            // Check Right
            if (c + 1 < n && !visited[r][c + 1]) {
                visited[r][c + 1] = true;
                next_candidates.push_back({r, c + 1});
            }
        }

        // 2. Find the smallest character among these neighbors
        for (auto it : next_candidates) {
            if (grid[it.first][it.second] < min_char) {
                min_char = grid[it.first][it.second];
            }
        }

        result += min_char;
        active.clear();

        // 3. Keep ONLY the neighbors that contain the minimum character
        for (auto it : next_candidates) {
            if (grid[it.first][it.second] == min_char) {
                active.push_back(it);
            }
        }
    }
    
    return result;
}

void solve(){
    int n;
    cin >> n;
    
    // FIX: You must give the 2D vector a size before using ans[i][j]
    vector<vector<char>> ans(n, vector<char>(n));
    
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            char x;
            cin >> x;
            ans[i][j] = x;
        }
    }

    // Call the function and print the result
    cout << op(ans, n) << "\n";
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