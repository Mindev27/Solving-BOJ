#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[205] = {};
vector<int> v[205];

void BFS(int x){
    queue<int> q;
    
    q.push(x);
    visited[x] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // 인접 리스트로 만들기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j] == 1 && i != j){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            BFS(i);
            answer++;
        }
    }
    
    return answer;
}