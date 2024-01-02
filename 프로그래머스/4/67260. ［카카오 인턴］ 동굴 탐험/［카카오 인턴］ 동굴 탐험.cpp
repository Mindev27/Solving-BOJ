#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, int> orderMap;
vector<bool> visited;
vector<bool> blocked;
map<int, vector<int>> tree;   
queue<int> q;

// path를 tree형태로 저장하는 함수
void makeTree(vector<vector<int>> &path) {
    for (auto &edge : path) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
}

// 칸이 열리는지 확인
void checkOrderMap(int x){
    if(orderMap.find(x) != orderMap.end()){ // x가 order에 있는 경우
        int next = orderMap[x];
        if(visited[next]){
            q.push(next);
        }
        blocked[next] = false;
    }
}

void BFS(int start){
    visited[start] = true;
    q.push(start);
    checkOrderMap(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < tree[cur].size(); ++i){
            int next = tree[cur][i];
            
            if(visited[next]) continue; // 방문했으면 넘어가기
            visited[next] = true;
            
            if(blocked[next]) continue; // 막혀있으면 넘어가기
            
            checkOrderMap(next); // 다른곳이 열리는지 확인
            q.push(next);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    visited.resize(n, false);
    blocked.resize(n, false);
    
    // 트리형태로 저장
    makeTree(path);
    
    // order을 map으로 저장
    for(auto &edge : order){
        orderMap[edge[0]] = edge[1];
        blocked[edge[1]] = true;
        
        // 0을 먼저 방문하는데 0을 방문할 조건이 있으면 항상 false
        if(edge[1] == 0) 
            return false;
    }

    BFS(0); // 0에서 탐색
    
    // 모두 막혀있지도 않고 모두 방문해야 클리어
    for(int i = 0; i < n; i++){
        if(!visited[i] || blocked[i]){
            return false;
        }
            
    }
    
    return true;
}