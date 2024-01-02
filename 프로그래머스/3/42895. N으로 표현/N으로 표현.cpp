#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v[10];          // i개를 써서 만들 수 있는 수들 저장

void push(int idx, int val){
    for(int i = 0; i < v[idx].size(); i++){
        if(v[idx][i] == val)
            return;
    }
    v[idx].push_back(val);
}

// N을 a번 쓴것과 b번 쓴것의 사칙연산 결과
bool solve(int a, int b, int number){
    for(int i = 0; i < v[a].size(); i++){
        for(int j = 0; j < v[b].size(); j++){
            // 합
            int sum = v[a][i] + v[b][j];
            if(sum == number) return true;
            push(a + b, sum);
            
            // 빼기
            int sub = v[a][i] - v[b][j];
            if(sub == number) return true;
            push(a + b, sub);
            
            // 곱
            int mul = v[a][i] * v[b][j];
            if(mul == number) return true;
            push(a + b, mul);
            
            // 나누기
            if(v[b][j] != 0){
                int div = v[a][i] / v[b][j];
                if(div == number) return true;
                push(a + b, div);
            }
        }
    }
    
    return false;
}

int getNNN(int N, int iter){ // N을 붙여놓은 수 반환
    int result = 0;
    while(iter--){
        result += N;
        result *= 10;
    }
    return result / 10;
}

int solution(int N, int number) {
    if(N == number) return 1;   // 예외 처리
    
    v[1].push_back(N);          // 초기화
    
    for(int used = 2; used <= 8; used++){
        
        // N을 이어붙인게 가능한지 확인
        int temp = getNNN(N, used);
        //cout << temp << '\n';
        if(temp == number) return used;
        v[used].push_back(temp);
        
        for(int pre = 1; pre <= used - 1; pre++){
            //cout << pre << ' ' << used - pre << '\n';
            if(solve(pre, used - pre, number)) return used;
        }
    }
    
    return -1;
}