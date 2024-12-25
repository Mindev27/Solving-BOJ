#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int A[5] = { 1, 1, 2, 6, 4 };

unordered_map<string, int> memo;

pair<string, int> div5(string N) {
    string q = "";
    int rem = 0;
    for (char c : N) {
        int d = c - '0';
        int num = rem * 10 + d;
        int q_d = num / 5;
        rem = num % 5;
        q += to_string(q_d);
    }

    int pos = q.find_first_not_of('0');
    if (pos != string::npos) {
        q = q.substr(pos);
    }
    else {
        q = "0";
    }
    return { q, rem };
}

int mod4(string N) {
    int rem = 0;
    for (char c : N) {
        rem = (rem * 10 + (c - '0')) % 4;
    }
    return rem;
}

// N!의 마지막 수 구하기
int D(string N) {
    if (N == "0") return 1;
    if (memo.find(N) != memo.end()) return memo[N];

    pair<string, int> dq = div5(N);
    string q = dq.X;
    int r = dq.Y;

    int d_q = D(q);

    int l_r = A[r];

    // 2^(floor(N/5)) mod 10
    int pow2;
    if (q == "0") {
        pow2 = 1;
    }
    else {
        int q_mod4 = mod4(q);
        switch (q_mod4) {
        case 1: pow2 = 2; break;
        case 2: pow2 = 4; break;
        case 3: pow2 = 8; break;
        case 0: pow2 = 6; break;
        }
    }

    // (D(q) * L(r) * 2^(floor(N/5))) mod 10
    int temp = (d_q * l_r) % 10;
    int d = (temp * pow2) % 10;

    memo[N] = d;
    return d;
}

void solve() {
    string s;
    cin >> s;
    int result = D(s);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }

    return 0;
}
