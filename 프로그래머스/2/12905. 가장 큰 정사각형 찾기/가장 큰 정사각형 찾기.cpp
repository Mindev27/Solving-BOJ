#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    const int SIZE = 1005;
    int dp[SIZE][SIZE] = {};

    int row = board.size();
    int col = board[0].size();
    
    // 이차원 배열로 옮기기
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            dp[i + 1][j + 1] = board[i][j];
        }
    }
    
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(dp[i][j] == 1){
                int minNum = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] = minNum + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    return answer * answer;
}