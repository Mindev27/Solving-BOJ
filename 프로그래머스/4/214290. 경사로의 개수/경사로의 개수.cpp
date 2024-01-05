#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

const int MOD = 1'000'000'007;
int row, col, mSize, dSize;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ll dp[105][70][70] = {}; // i단계에서, j에서 k로 가는 경우의 수


// 행렬을 곱하는 함수
vector<vector<ll>> multiple(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    vector<vector<ll>> ans(mSize, vector<ll>(mSize));

    for(int i = 0; i < mSize; i++){
        for(int j = 0; j < mSize; j++){
            for(int k = 0; k < mSize; k++){
                ans[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
            }
        ans[i][j] %= MOD;
        }
    }
    return ans;
}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    row = grid.size();
    col = grid[0].size();
    mSize = row * col;
    dSize = d.size();
    
    // dp로 각 경로의 경우의 수 계산
    for(int i = 0; i < mSize; i++)
        dp[0][i][i] = 1;
    
    for(int i = 1; i <= d.size(); i++) {
        for(int j = 0; j < mSize; j++) {
            int x = j / col;
            int y = j % col;
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx < 0 || row <= nx || ny < 0 || col <= ny)
                    continue;
                if(grid[nx][ny] - grid[x][y] != d[i - 1])
                    continue;
                
                for(int s = 0; s < mSize; s++)
                    dp[i][s][nx * col + ny] = (dp[i][s][nx * col + ny] + dp[i - 1][s][j] % MOD) % MOD;
            }
        }
    }
    
    // 인접행렬로 만들기
    vector<vector<ll>> adj(mSize, vector<ll>(mSize));
    for(int i = 0; i < mSize; i++) {
        for(int j = 0; j < mSize; j++) {
            adj[i][j] = dp[dSize][i][j];
        }
    }

    // 답을 저장할 단위행렬 만들기
    vector<vector<ll>> answer(mSize, vector<ll>(mSize));
    for(int i = 0; i < mSize; i++)
        answer[i][i] = 1;
    
    // 인접행렬을 거듭제곱하면서 경우의 수를 계산
    while(k > 0) {
        if(k & 1) {
            answer = multiple(answer, adj);
            k -= 1;
        }
        adj = multiple(adj, adj);
        k /= 2;
    }

    ll result = 0;
    // 인접행렬의 합을 다 더하기
    for(int i = 0; i < mSize; i++){
        for(int j = 0; j < mSize; j++){
            result = (result + answer[i][j] % MOD) % MOD;
        }
    }
    
    return result;
}