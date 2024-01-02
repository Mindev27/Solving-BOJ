#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int p = 29;             // 라빈-카프에 쓰일 소수
const int MOD = 10007;        // 오버플로우 방지를 위한 MOD 연산
int L;
string word;
int pre[200005];              // p 거듭제곱을 바로 가져오기 위함
vector<int> hashTable[10007]; // hashTable[i] 해시값이 i일때 시작 인덱스 저장

// 해시테이블 초기화 함수
void init() {
  for(int i = 0; i < 10007; i++) {
    hashTable[i].clear();
  }
}

// 두 문자열이 정말로 같은지 확인
bool check(int s1, int s2, int l) {
  for(int i = 0; i < l; i++) {
    if(word[s1 + i] != word[s2 + i])
      return false;
  }
  return true;
}

// 길이 l의 반복 부분 문자열이 있는지 슬라이드 윈도우로 확인
bool isOkLength(int l) {
  init();
  // 0 ~ l - 1 까지의 해시값 계산
  ll key = 0;
  for(int i = 0; i < l; i++)
    key = (key * p + (word[i] - 'a')) % MOD;

  hashTable[key].push_back(0);           // key값을 해시값으로 가지는 숫자는 0부터 시작
  ll hash = key;
  for(int i = l; i < L; i++) {
    hash = (hash - (word[i - l] - 'a') * pre[l - 1]) % MOD;
    hash = (hash + MOD) % MOD;
    hash = (hash * p + (word[i] - 'a')) % MOD;
    
    if(!hashTable[hash].empty()) {       // 해시값이 있었다면 두 문자열을 비교
      for(int index : hashTable[hash]) {
        if(check(index, i - l + 1, l))   // 같은 문자열이 있다면 True반환
          return true;
      }
    }
    hashTable[hash].push_back(i - l + 1);
  }
  return false;
}

// 매개변수 탐색으로 반복 부분문자열의 길이 찾기
int solve(int s, int e) {
  while (s < e) {
    int m = (s + e + 1) / 2;
    if (isOkLength(m)) s = m;
    else e = m - 1;
  }
  return s;
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> L >> word;

  // p의 거듭제곱 값들을 미리 저장
  pre[0] = 1;
  for(int i = 1 ; i < 200005; i++) {
    pre[i] = (pre[i - 1] * p) % MOD;
  }
  
  cout << solve(0, L);

  return 0;
}