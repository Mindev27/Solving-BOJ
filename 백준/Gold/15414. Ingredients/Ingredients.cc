#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int MAX = 10005;
const int INF = 999999999;
int B, N;
vector<vector<pair<int, pii>>> edges;
map<string, ll> nodes;
vector<string> dishNames;
pii dishes[MAX];
int known[MAX];
int prest[MAX + 5];

ll node(string &s) {
  ll &n = nodes[s];
  if (!n) {
    edges.push_back(vector<pair<int, pii>>());
    n = edges.size();
  }
  return n - 1;
}

pii &get(ll n) {
  pii &res = dishes[n];
  if (known[n]++ || edges[n].size() == 0)
    return res;
  res = make_pair(INF, 0);
  for (ll i = 0; i < edges[n].size(); i++) {
    pii &b = get(edges[n][i].X);
    res = min(res, {b.X + edges[n][i].Y.X, -(b.Y + edges[n][i].Y.Y)});
  }
  res.Y = -res.Y;
  return res;
}

void input() {
  cin >> B >> N;

  for (int i = 0; i < N; i++) {
    string result, base, ing;
    int price, prestige;
    cin >> result >> base >> ing >> price >> prestige;
    ll der = node(result), bas = node(base);
    edges[der].push_back({bas, {price, prestige}});
  }

  for (int i = (int)edges.size() - 1; i >= 0; i--) {
    pii &d = get(i);
    int price = d.X, prestige = d.Y;
    for (int b = 0; b <= B - price; b++)
      prest[b] = max(prest[b], prest[b + price] + prestige);
  }
}

void solve() {
pii best = {-1, 0};
  for (int i = 0; i <= B; i++)
    best = max(best, {prest[i], i});
  cout << best.X << '\n';
  cout << B - best.Y;
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