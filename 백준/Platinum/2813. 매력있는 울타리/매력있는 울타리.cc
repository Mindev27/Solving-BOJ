#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;
int dong[300005] = {};
int answer[300005] = {};
vector<int> sang;
vector<int> uu, ud, du, dd;

void input() {
  cin >> N;
  for(int i = 0; i < N; ++i) {
    cin >> dong[i];
  }

  for(int i = 0; i < N; ++i) {
    int a; cin >> a;
    sang.push_back(a);
  }
}

// 3개씩 패턴을 분석 후 가운데 인덱스를 저장
void makePattern() {
  for(int i = 0; i < N - 2; ++i) {
    if(dong[i] < dong[i + 1] && dong[i + 1] < dong[i + 2])
      uu.push_back(i + 1);
    else if(dong[i] < dong[i + 1] && dong[i + 1] > dong[i + 2])
      ud.push_back(i + 1);
    else if(dong[i] > dong[i + 1] && dong[i + 1] < dong[i + 2])
      du.push_back(i + 1);
    else if(dong[i] > dong[i + 1] && dong[i + 1] > dong[i + 2])
      dd.push_back(i + 1);
  }
}

bool compare(int &a, int &b) {
  return a > b;
}

void solve() {
  sort(sang.begin(), sang.end(), compare); // 울타리를 내림차순으로 정렬
  
  makePattern(); // 패턴 만들기

  // du는 가장 작은수부터 넣기
  for(int i = 0; i < du.size(); ++i) {
    int curIndex = du[i];
    answer[curIndex] = sang.back();
    sang.pop_back();
  }

  // 시작이 내려가있거나 끝이 내려가있는 경우에도 작은 수 넣기
  if(dong[0] < dong[1]) {
    answer[0] = sang.back();
    sang.pop_back();
  }
  if(dong[N - 2] > dong[N - 1]){
    answer[N - 1] = sang.back();
    sang.pop_back();
  }

  reverse(sang.begin(), sang.end()); // 오름차순으로 바꾸기
  
  // ud는 가장 큰수부터 넣기
  for(int i = 0; i < ud.size(); ++i) {
    int curIndex = ud[i];
    answer[curIndex] = sang.back();
    sang.pop_back();
  }

  // 시작이 올라가있거나 끝이 올라가있는 경우에 큰수 넣기
  if(dong[0] > dong[1]) {
    answer[0] = sang.back();
    sang.pop_back();
  }
  if(dong[N - 2] < dong[N - 1]){
    answer[N - 1] = sang.back();
    sang.pop_back();
  }

  reverse(sang.begin(), sang.end()); // 내림차순으로 바꾸기
  
  // uu는 가장 작은수부터 넣기
  for(int i = 0; i < uu.size(); ++i) {
    int curIndex = uu[i];
    answer[curIndex] = sang.back();
    sang.pop_back();
  }

  reverse(sang.begin(), sang.end()); // 오름차순으로 바꾸기

  // dd는 가장 큰수부터 넣기
  for(int i = 0; i < dd.size(); ++i) {
    int curIndex = dd[i];
    answer[curIndex] = sang.back();
    sang.pop_back();
  }

  // 매력도 계산
  ll result = 0;
  for(int i = 0; i < N - 1; ++i) {
    result += abs(answer[i] - answer[i + 1]);
  }
  cout << result << '\n';
  for(int i = 0; i < N; ++i) {
    cout << answer[i] << ' ';
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();
  
  return 0;
}
