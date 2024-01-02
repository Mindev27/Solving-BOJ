#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer = 1000;

void solve(int n, vector<vector<int>> linked) {
    cout << "solve" << '\n';
    vector<int> v[105];
    bool visited[105] = {};
    queue<int> q;
    
    // 먼저 인접 리스트로 바꾸기
    for(int i = 0; i < linked.size(); i++){
        int a = linked[i][0];
        int b = linked[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
        
        cout << a << ' ' << b << '\n';
    }
    
    q.push(1);
    visited[1] = true;
    
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
    
    int setA = 0;
    int setB = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]) setA++;
        else setB++;
    }
    
    cout << abs(setA - setB) << '\n';
    answer = min(answer, abs(setA - setB));
}

int solution(int n, vector<vector<int>> wires) {
    for(int i = 0; i < wires.size(); i++){      // wires에서 하나를 빼고 돌리기
        vector<vector<int>> linked;
        for(int j = 0; j < wires.size(); j++){
            if(i != j) linked.push_back(wires[j]);
        }
        
        solve(n, linked);
    }
    
    return answer;
}