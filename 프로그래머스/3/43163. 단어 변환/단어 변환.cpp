#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    vector<bool> visited((int)words.size(), false);
    q.push({begin, 0});
    
    while(!q.empty()) {
        auto [cur, d] = q.front();
        q.pop();
        
        if(cur == target) return d;
        
        for(int idx = 0; idx < words.size(); idx++) {
            if(visited[idx]) continue;
            
            // 1자리만 다르면 바꿀수있음
            int diff = 0;
            for(int i = 0; i < cur.size(); i++) {
                if(cur[i] != words[idx][i]) diff++;
            }
            
            if(diff == 1) {
                visited[idx] = true;
                q.push({words[idx], d+1});
            }
        }
    }
    
    
    return 0;
}