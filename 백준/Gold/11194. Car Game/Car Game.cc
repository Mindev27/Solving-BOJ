#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    vector<vector<vector<int>>> next_arrays(N);
    for (int idx = 0; idx < N; idx++) {
        string &word = words[idx];
        int len = word.length();
        vector<vector<int>> next(len + 1, vector<int>(26, -1));
        for (int c = 0; c < 26; ++c) {
            next[len][c] = -1;
        }
        for (int i = len - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++) {
                if (word[i] - 'a' == c) {
                    next[i][c] = i;
                } else {
                    next[i][c] = next[i + 1][c];
                }
            }
        }
        next_arrays[idx] = move(next);
    }
    for (int plate_idx = 0; plate_idx < M; plate_idx++) {
        string plate;
        cin >> plate;
        vector<int> letters(3);
        for (int i = 0; i < 3; i++) {
            letters[i] = plate[i] - 'A';
        }
        bool found = false;
        for (int idx = 0; idx < N; idx++) {
            string &word = words[idx];
            vector<vector<int>> &next = next_arrays[idx];
            int pos = 0;
            int len = word.length();
            bool match = true;
            for (int k = 0; k < 3; k++) {
                if (pos >= len || next[pos][letters[k]] == -1) {
                    match = false;
                    break;
                }
                pos = next[pos][letters[k]] + 1;
            }
            if (match) {
                cout << word << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No valid word\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    return 0;
}
