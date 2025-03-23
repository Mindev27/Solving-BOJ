#include <bits/stdc++.h>
#include <random>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int mod = 1000000009;

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
    int M;
    ll N;
    cin >> M >> N;
    
    if(N == 0){
        cout << 1 << '\n';
        return;
    }
    if(N == 1){
        // 어떤 칸이든 선택 가능
        int ans = (1 << M) % mod;
        cout << ans << '\n';
        return;
    }
    
    // 모든 한 열의 배치
    vector<int> masks;
    for(int mask = 0; mask < (1 << M); mask++){
        masks.push_back(mask);
    }
    
    auto validAdj = [=](int a, int b) -> bool {
        int lim = (1 << M) - 1;
        // a에서 좌우로 2칸 이동한 자리와 b가 겹치면 안됨됨
        if( ((a << 2) & lim) & b ) return false;
        if( (a >> 2) & b ) return false;
        return true;
    };
    
    // 두 열 차이가 2인 경우
    auto validTwogap = [=](int a, int b) -> bool {
        int lim = (1 << M) - 1;
        if( ((a << 1) & lim) & b ) return false;
        if( (a >> 1) & b ) return false;
        return true;
    };

    struct State { int a, b; };
    vector<State> states;
    for(auto a : masks){
        for(auto b : masks){
            if(validAdj(a, b)){
                states.push_back({a, b});
            }
        }
    }
    int S = states.size();

    vector<vector<int>> trans(S);
    for (int i = 0; i < S; i++){
        int a = states[i].a, b = states[i].b;
        for (int j = 0; j < S; j++){
            // 상태 j는 (b, c)여야 함
            if(states[j].a != b) continue;
            int c = states[j].b;
            if(!validAdj(b, c)) continue;
            if(!validTwogap(a, c)) continue;
            trans[i].push_back(j);
        }
    }
    
    // f(n):= M행 n열 체스판에 대해 나이트를 놓는 경우의 수
    vector<int> seq; 
    // seq[0] = f(1), seq[1] = f(2)
    int f1 = (1 << M) % mod;
    seq.push_back(f1);
    seq.push_back(S % mod);
    
    // dp:= 체스판 열이 2개일 때, 각 상태의 경우의 수
    vector<int> dp(S, 1);
    // 충분한 초깃값의 개수
    int L = max(2 * S, 50);
    for (int n = 3; n <= L; n++){
        vector<int> ndp(S, 0);
        for (int i = 0; i < S; i++){
            if(dp[i] == 0) continue;
            for (int j : trans[i]){
                ndp[j] = (ndp[j] + dp[i]) % mod;
            }
        }
        dp = ndp;
        ll tot = 0;
        for (int x : dp){
            tot = (tot + x) % mod;
        }
        seq.push_back(tot);
    }
    
    // seq[k] = f(k+1)
    // N >= 2면 f(N) = seq[N-1]
    int ans = 0;
    if(N <= seq.size()){
        ans = seq[N - 1];
    } else {
        // 벌캠 돌리기
        ans = guess_nth_term(seq, N - 1) % mod;
    }
    cout << ans % mod << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
