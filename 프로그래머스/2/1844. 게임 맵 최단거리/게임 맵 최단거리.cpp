#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int N, M;

int BFS(int a, int b, vector<vector<int>> maps) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    queue<tuple<int ,int, int>> q;
    vector <vector <bool>> visited(N,vector<bool>(M,false));
    
    visited[a][b] = true;
    q.push({a, b, 1});
    
    while(!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        
        // cout << x << ' ' << y << ' ' << d << '\n';
        
        if(x == N - 1 && y == M - 1) {
            return d;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            if(visited[nx][ny] || maps[nx][ny] == 0) continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny, d + 1});
        }
    }
    
    return -1;
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    N = maps.size();
    M = maps[0].size();
    
    answer = BFS(0, 0, maps);
    
    return answer;
}