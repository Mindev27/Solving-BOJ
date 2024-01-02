#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int board[505][505] = {};
    int dp[505][505] = {};
    int n = triangle.size();
    
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            board[i + 1][j + 1] = triangle[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            dp[i][j] += board[i][j];
        }
    }
    
    for(int j = 1; j <= n; j++){
        answer = max(answer, dp[n][j]);
    }
    
    return answer;
}