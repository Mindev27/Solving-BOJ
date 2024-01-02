#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int DIV = 1'000'000'007;
    bool water[105][105] = {};
    int dp[105][105] = {};
    
    // init
    for(int i = 0; i < puddles.size(); i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        water[y][x] = true;
    }
    dp[0][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!water[i][j]){
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV;
            }
        }
    }
    
    return dp[n][m];
}