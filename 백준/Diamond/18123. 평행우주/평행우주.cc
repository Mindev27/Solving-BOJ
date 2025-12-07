// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long

// 풀이 보고 풂

int s;
vector<int> g[35];
int subSize[35];
int best;
vector<int> cents;

int getCent(int u, int p) {
    int sz = 1;
    int maxSub = 0;
    for (int v : g[u])
        if (v != p) {
            int csz = getCent(v, u);
            sz += csz;
            if (csz > maxSub)
                maxSub = csz;
        }
    int up = s - sz;
    if (up > maxSub)
        maxSub = up;

    if (maxSub < best) {
        best = maxSub;
        cents.clear();
        cents.push_back(u);
    }
    else if (maxSub == best) {
        cents.push_back(u);
    }
    return sz;
}

string encodeTree(int u, int p) {
    vector<string> child;
    for (int v : g[u])
        if (v != p) {
            child.push_back(encodeTree(v, u));
        }
    sort(child.begin(), child.end());
    string res = "1";
    for (auto &c : child)
        res += c;
    res += "0";
    return res;
}

ull strToMask(const string &s) {
    ull x = 0;
    for (char c : s) {
        x <<= 1;
        if (c == '1')
            x |= 1;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;

    unordered_set<ull> st;

    for (int idx = 0; idx < n; idx++) {
        cin >> s;
        for (int i = 0; i < s; i++)
            g[i].clear();

        for (int i = 0; i < s - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ull code;

        if (s == 1) {
            code = 2ULL;
        }
        else {
            best = 1e9;
            cents.clear();
            getCent(0, -1);

            string a = encodeTree(cents[0], -1);
            if (cents.size() == 1) {
                code = strToMask(a);
            }
            else {
                string b = encodeTree(cents[1], -1);
                if (a < b)
                    code = strToMask(a);
                else
                    code = strToMask(b);
            }
        }

        st.insert(code);
    }

    cout << st.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}
