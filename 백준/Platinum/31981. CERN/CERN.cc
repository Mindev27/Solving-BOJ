#include <algorithm>

#include <cmath>

#include <cstring>

#include <iostream>

#include <queue>

#include <vector>

#define ll long long

#define ld long double

#define X first

#define Y second

#define pii pair<int, int>

#define pll pair<ll, ll>

using namespace std;

int sqrtN;

struct Query {

  int idx, s, e, len;

  bool operator<(Query &x) {

    if (s / sqrtN != x.s / sqrtN)

      return s / sqrtN < x.s / sqrtN;

    return (s / sqrtN) & 1 ? e < x.e : e > x.e;

  }

};

vector<Query> query;

vector<int> v;

int n, q;

ll res = 0;

ll ans[500005]; // 쿼리의 답

ll cnt[500005]; // i의 빈도

ll table[500005]; // i 빈도의 숫자의 개수

ll one = 0, two = 0; // 1개 2개 이상 등장횟수 저장

void input() {

  cin >> n >> q;

  sqrtN = sqrt(n);

  v.resize(n + 1);

  for (int i = 1; i <= n; i++) {

    cin >> v[i];

  }

  for (int i = 0; i < q; i++) {

    int s, e;

    cin >> s >> e;

    query.push_back({i, s, e, e - s + 1});

  }

}

void Plus(int a) {

  if (cnt[a] != 0)

    table[cnt[a]] -= 1;

  cnt[a] += 1;

  if(cnt[a] == 2) two += 1; // 빈도 2이상 증가

  if(cnt[a] == 1) one += 1; // 빈도 1이상 증가

  table[cnt[a]] += 1;

  res = max(res, cnt[a]);

}

void Minus(int a) {

  table[cnt[a]] -= 1;

  if(cnt[a] == 2) two -= 1; // 빈도 2이상 감소

  if(cnt[a] == 1) one -= 1; // 빈도 1이상 감소

  if (cnt[a] == res && table[cnt[a]] == 0)

    res -= 1;

  cnt[a] -= 1;

  table[cnt[a]] += 1;

}

void solve() {

  sort(query.begin(), query.end());

  int s = 1, e = 0;

  for (int i = 0; i < q; i++) {

    while (s < query[i].s) Minus(v[s++]);

    while (s > query[i].s) Plus(v[--s]);

    while (e < query[i].e) Plus(v[++e]);

    while (e > query[i].e) Minus(v[e--]);

    int qLen = query[i].len; // 쿼리 길이

    // 길이가 짝수일때

    if(qLen % 2 == 0) {

      // 원소가 딱 반반씩이면 0

      if(table[res] == 2 && res == qLen/2)

        ans[query[i].idx] = 0;

      // 하나가 절반을 넘으면 1

      else if(res >= qLen/2)

        ans[query[i].idx] = 1;

      // 2개이상인 개수

      else ans[query[i].idx] = two;

    } else {

      // 길이가 홀수일때

      // 하나가 절반을 넘기면 1

      if(res >= (qLen + 1) / 2)

        ans[query[i].idx] = 1;

      // 1개이상인 개수

      else ans[query[i].idx] = one;

    }

  }

  for (int i = 0; i < q; i++)

    cout << ans[i] << "\n";

}

int main() {

  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);

  cin.tie(0);

  cout.tie(0);

  input();

  solve();

  return 0;

}

