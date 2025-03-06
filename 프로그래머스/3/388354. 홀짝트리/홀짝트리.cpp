#include <bits/stdc++.h>

// 일단 각 노드의 숫자를 홀짝으로 미리 구별하자
// 홀짝트리인 경우 -> 홀수는 자식이 홀수, 짝수는 자식이 짝수개
// 역홀짝트리인 경우 -> 홀수는 자식이 짝수개, 짝수는 자식이 홀수개
// 리프노드는 0인거?
// 일단 리프가 아니면 무조건 부모가 하나있음 그러면 루트 빼고는 모두 (degree-1)이 자식개수다
// 일단 degree개수를 모두 세자
// N^2은 TLE
// degree를 모두 세고나서 
// 좌표압축으로 40만 정점개수
// 2 3 4 6
// 1 3 1 1
// 일단 홀짝 트리만 생각하자
// 위아래 기우성 같다 -> 루트가 되어야함, 그리고 나머지는 모두 달라야함?
// 역홀짝트리
// 위아래 기우성 다른게 루트, 나머지는 기우성 같아야함
// 일단 트리끼리 미리 나누자 -> 유파?
// 풀이:
// value값으로 좌표압축하고 유파로 간선마다 그룹화
// 그룹별로 기우성의 개수를 세기
// 기우성 같은거 == 1: +1 홀짝트리
// 기우성 다른거 == 1: +1 역홀짝트리
// ** 인덱스 -> 값 :node, 값 -> 인덱스 : mp

using namespace std;

int N, M;
int p[400005];
bool visited[400005];
map<int, int> mp; // key:값 value:인덱스
int degree[400005]; // 인덱스기반 degree수

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if(x < y) p[y] = x;
    else p[x] = y;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    N = nodes.size();
    M = edges.size();
    
    for(int i = 0; i < N; i++) {
        mp[nodes[i]] = i;
        p[i] = i;
    }
    
    for(int i = 0; i < M; i++) {
        int u = edges[i][0], v = edges[i][1];
        
        degree[mp[u]]++; degree[mp[v]]++;
            
        auto uIdx = mp[u], vIdx = mp[v];
        // cout << uIdx << ' ' << vIdx << '\n';
        merge(uIdx, vIdx);
    }
    
    // for(int i = 0; i < N; i++) {
    //     cout << find(i) << ' ';
    // }
    // cout << '\n';
    
    map<int, vector<int>> trees;
    for (int i = 0; i < N; i++) {
        int root = find(i);
        trees[root].push_back(nodes[i]);
    }
    
    
    for (auto &group : trees) {
        int same = 0;
        int diff = 0;
        for (int val : group.second) {
            // cout << val << ' ';
            if(val % 2 == degree[mp[val]] % 2) same++;
            else diff++;
        }
        // cout << '\n';   
        // cout << same << ' ' << diff << '\n';
        if(same == 1) answer[0]++;
        if(diff == 1) answer[1]++;
    }
    
    return answer;
}
















