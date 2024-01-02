#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> q;                    // (현재 숫자, 탐색한 인덱스)
    
    q.push({numbers[0], 0});
    q.push({-numbers[0], 0});
    
    while(!q.empty()){
        int cur = q.front().first;              // 현재 숫자
        int idx = q.front().second;             // 현재 인덱스
        q.pop();
        
        //cout << cur << ' ' << idx << '\n';    // check
        
        idx += 1;                               // 다음 인덱스로 바꾸기
        
        if(idx == numbers.size()){              // 끝까지 탐색했다면 target인지 확인
            if(cur == target) answer++;
            continue;
        }
        
        q.push({cur + numbers[idx], idx});      // 다음수를 더한 경우 탐색
        q.push({cur - numbers[idx], idx});      // 다음수를 뺀 경우 탐색
    }
    
    return answer;
}