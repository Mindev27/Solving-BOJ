#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[10] = {};
int answer = -1;
int order[10] = {};

// 던전을 돌면서 몇 개까지 탐험할 수 있는지 계산
void solve(int k, vector<vector<int>> dungeons) {   
    int cnt = 0;                                // 현재 탐험한 횟수
    
    for(int i = 0; i < dungeons.size(); i++){
        int cur = order[i];
        
        if(dungeons[cur][0] <= k){                // 탐험할 수 있다면
            k -= dungeons[cur][1];
            cnt++;
        }
        else{
            answer = max(answer, cnt);
            return;
        }
    }
    
    answer = max(answer, cnt);
}

// 가능한 탐험 던전의 조합 계산
void DFS(int depth, int limit, int k, vector<vector<int>> dungeons){
    if(depth == limit){             
        solve(k, dungeons);     // 조합을 찾았다면 탐험 횟수 계산
        return;
    }
    
    for(int i = 0; i < limit; i++){
        if(!visited[i]){
            order[depth] = i;
            visited[i] = true;
            DFS(depth + 1, limit, k, dungeons);
            visited[i] = false;
        }
    }
}
    
int solution(int k, vector<vector<int>> dungeons) {
    
    DFS(0, dungeons.size(), k, dungeons);
    
    return answer;
}