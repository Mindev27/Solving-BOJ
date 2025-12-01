// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
상태가 대충 24^2개고 나이트 움직일때 상태전이가 유한상태전이
그러면 선형이네

벌캠이 증명됏다

아 1e6+7은 합성수였네
29 * 34483

*/

int MOD = 1000007;
int mod;

// 구사과의 벌캠 템플릿 : https://gist.github.com/koosaga/d4afc4434dbaa348d5bef0d60ac36aa4

ll ipow(ll x, ll p){
    ll ret = 1, piv = x;
    while(p){
        if(p & 1) ret = ret * piv % mod;
        piv = piv * piv % mod;
        p >>= 1;
    }
    return ret;
}

vector<int> berlekamp_massey(vector<int> x){
    vector<int> ls, cur;
    int lf, ld;
    for(int i = 0; i < x.size(); i++){
        ll t = 0;
        for(int j = 0; j < cur.size(); j++){
            t = (t + 1ll * x[i - j - 1] * cur[j]) % mod;
        }
        if((t - x[i]) % mod == 0) continue;
        if(cur.empty()){
            cur.resize(i + 1);
            lf = i;
            ld = (t - x[i]) % mod;
            continue;
        }
        ll k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
        vector<int> c(i - lf - 1);
        c.push_back(k);
        for(auto &j : ls) c.push_back(-j * k % mod);
        if(c.size() < cur.size()) c.resize(cur.size());
        for(int j = 0; j < cur.size(); j++){
            c[j] = (c[j] + cur[j]) % mod;
        }
        if(i - lf + (int)ls.size() >= (int)cur.size()){
            tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
        }
        cur = c;
    }
    for(auto &i : cur) i = (i % mod + mod) % mod;
    return cur;
}

int get_nth(vector<int> rec, vector<int> dp, ll n){
    int m = rec.size();
    vector<int> s(m), t(m);
    s[0] = 1;
    if(m != 1) t[1] = 1;
    else t[0] = rec[0];
    auto mul = [&rec](vector<int> v, vector<int> w){
        int m = v.size();
        vector<int> t(2 * m);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                t[j + k] += 1ll * v[j] * w[k] % mod;
                if(t[j + k] >= mod) t[j + k] -= mod;
            }
        }
        for(int j = 2 * m - 1; j >= m; j--){
            for(int k = 1; k <= m; k++){
                t[j - k] += 1ll * t[j] * rec[k - 1] % mod;
                if(t[j - k] >= mod) t[j - k] -= mod;
            }
        }
        t.resize(m);
        return t;
    };
    while(n){
        if(n & 1) s = mul(s, t);
        t = mul(t, t);
        n >>= 1;
    }
    ll ret = 0;
    for(int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % mod;
    return ret % mod;
}

int guess_nth_term(vector<int> x, ll n){
    if(n < x.size()) return x[n];
    vector<int> v = berlekamp_massey(x);
    if(v.empty()) return 0;
    return get_nth(v, x, n);
}

struct elem { int x, y, v; }; // A_(x, y) <- v, 0-based. no duplicate please..

vector<int> get_min_poly(int n, vector<elem> M){
    // smallest poly P such that A^i = sum_{j < i} {A^j * P_j}
    vector<int> rnd1, rnd2;
    mt19937 rng(0x14004);
    auto randint = [&rng](int lb, int ub){
        return uniform_int_distribution<int>(lb, ub)(rng);
    };
    for(int i = 0; i < n; i++){
        rnd1.push_back(randint(1, mod - 1));
        rnd2.push_back(randint(1, mod - 1));
    }
    vector<int> gobs;
    for(int i = 0; i < 2 * n + 2; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            tmp += 1ll * rnd2[j] * rnd1[j] % mod;
            if(tmp >= mod) tmp -= mod;
        }
        gobs.push_back(tmp);
        vector<int> nxt(n);
        for(auto &i : M){
            nxt[i.x] += 1ll * i.v * rnd1[i.y] % mod;
            if(nxt[i.x] >= mod) nxt[i.x] -= mod;
        }
        rnd1 = nxt;
    }
    auto sol = berlekamp_massey(gobs);
    reverse(sol.begin(), sol.end());
    return sol;
}

ll det(int n, vector<elem> M){
    vector<int> rnd;
    mt19937 rng(0x14004);
    auto randint = [&rng](int lb, int ub){
        return uniform_int_distribution<int>(lb, ub)(rng);
    };
    for(int i = 0; i < n; i++) rnd.push_back(randint(1, mod - 1));
    for(auto &i : M){
        i.v = 1ll * i.v * rnd[i.y] % mod;
    }
    auto sol = get_min_poly(n, M)[0];
    if(n % 2 == 0) sol = mod - sol;
    for(auto &i : rnd) sol = 1ll * sol * ipow(i, mod - 2) % mod;
    return sol;
}

// 여기까지가 템플릿임

void solve() {
    int n;
    ll K;
    cin >> n >> K;

    int sz = 2 * n;
    int S = sz * sz;

    vector<vector<int>> adj(S);
    int dr[8] = {1,2,2,1,-1,-2,-2,-1};
    int dc[8] = {2,1,-1,-2,-2,-1,1,2};

    auto inside = [&](int r, int c){
        return (0 <= r && r < sz && 0 <= c && c < sz);
    };

    auto id = [&](int r, int c){
        return r * sz + c;
    };

    for(int r = 0; r < sz; r++){
        for(int c = 0; c < sz; c++){
            int u = id(r, c);
            for(int k = 0; k < 8; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(inside(nr, nc)){
                    int v = id(nr, nc);
                    adj[u].push_back(v);
                }
            }
        }
    }

    // 모서리 인덱스들
    vector<int> corners;
    corners.push_back(id(0, 0));
    corners.push_back(id(0, sz - 1));
    corners.push_back(id(sz - 1, 0));
    corners.push_back(id(sz - 1, sz - 1));

    // BM용 수열 길이 대충 크게
    int L = 3 * S + 10;

    auto compute_seq_nth = [&](int prime_mod)->int {
            mod = prime_mod;
            vector<int> cur(S), nxt(S);
            cur[id(0,0)] = 1;

            vector<int> pref(L);

            for(int t = 0; t < L; t++){
                // ft := 정확히 t번 움직여서 모서리에 있는 경우의 수
                int ft = 0;
                for(int c : corners){
                    ft += cur[c];
                    if(ft >= mod) ft -= mod;
                }

                if(t == 0) pref[t] = ft;
                else{
                    pref[t] = pref[t - 1] + ft;
                    if(pref[t] >= mod) pref[t] -= mod;
                }

                // 다음 상태로 전이
                fill(nxt.begin(), nxt.end(), 0);
                for(int u = 0; u < S; u++){
                    int val = cur[u];
                    if(!val) continue;
                    for(int v : adj[u]){
                        nxt[v] += val;
                        if(nxt[v] >= mod) nxt[v] -= mod;
                    }
                }
                cur.swap(nxt);
            }
            int res = guess_nth_term(pref, K);
            if(res < 0) res += mod;
            return res;
        };


    int P1 = 29;
    int P2 = 34483;

    int a1 = compute_seq_nth(P1);
    int a2 = compute_seq_nth(P2);
    
    // MOD = 1000007 = 29 * 34483
    ll M1 = 34483;   // MOD / 29
    ll M2 = 29;      // MOD / 34483
    ll INV1 = 15;    // 34483^-1 mod 29
    ll INV2 = 16647; // 29^-1 mod 34483

    ll x = 0;
    x += 1LL * a1 * M1 % MOD * INV1 % MOD;
    x += 1LL * a2 * M2 % MOD * INV2 % MOD;
    x %= MOD;
    if(x < 0) x += MOD;

    cout << x << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}