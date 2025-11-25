#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ask(vector<int>& I) {
    cout << "? " << I.size();
    for (int x : I) cout << ' ' << x;
    cout << '\n';
    cout.flush();

    int c; cin >> c;
    vector<int> rec(c);
    for (int i = 0; i < c; i++) {
        cin >> rec[i];
    }
    return rec;
}

// I에서 rec제거
vector<int> remv(vector<int>& I, vector<int>& rec) {
    vector<int> nxt;
    int j = 0, R = rec.size();
    for (int x : I) {
        while (j < R && rec[j] < x) j++;
        if (j < R && rec[j] == x) continue;
        nxt.push_back(x);
    }
    return nxt;
}



void solve() {
    int N; cin >> N;
	int M = N * N + 1;

	vector<vector<int>> layer(N + 1);
	vector<int> I(M);
	iota(I.begin(), I.end(), 1);

	bool answered = false;

	for (int r = 1; r <= N; r++) {
		vector<int> rec = ask(I);
		layer[r] = rec;
		I = remv(I, rec);

		// 증가
		if (rec.size() >= N + 1) {
			cout << "! ";
			for (int k = 0; k <= N; k++) {
				if (k) cout << ' ';
				cout << rec[k];
			}
			cout << '\n';
			cout.flush();
			answered = true;
			break;
		}
	}

	if (answered) return;

	// 자 이제 모든레이어 크기 <= N  무좋건 I에 최소 1개남음
	
	int cur = I.front();
	vector<int> ans(N + 1);
	ans[N] = cur;

	for (int r = N; r >= 1; r--) {
		auto &L = layer[r];
		int pos = (upper_bound(L.begin(), L.end(), cur - 1) - L.begin());
		int pick = L[pos - 1];
		ans[r - 1] = pick;
		cur = pick;
	}

	cout << "! ";
	for (int i = 0; i <= N; i++) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}