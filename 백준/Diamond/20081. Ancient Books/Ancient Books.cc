#include "books.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
순열 사이클이 생길거같음
일단 간선 기준으로 왼->오 오->왼의 책이동 개수는 같음
그러면 딱 간선마다 지나가야하는게 같으면 순열 사이클에서 옮겨질듯
그럼 s=0이라고 해봐 그럼 무조건 0포함 순열 사이클은 돌면돼
또 0으로 와야하니까 일단 순열이 하나면 쉽다
순열이 다르면?
구간이 겹치면 걍 또 될듯
안겹치면 사이에 이동해야하니까 2 * (순열개수 - 1) 감성
s가 0이 아니면 어캄쇼

일단 0일때 짜

*/

ll minimum_walk(std::vector<int> p, int s) {
    int n = p.size();

    ll d = 0;
    for (int i = 0; i < n; i++) {
        d += abs(i - p[i]);
    }

    vector<int> prefixMax(n), suffixMin(n);
    vector<char> suffixNoT(n);

    prefixMax[0] = p[0];
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], p[i]);
    }

    suffixMin[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMin[i] = min(suffixMin[i + 1], p[i]);
    }

    suffixNoT[n - 1] = (p[n - 1] != (n - 1));
    for (int i = n - 2; i >= 0; i--) {
        suffixNoT[i] = suffixNoT[i + 1] || (p[i] != i);
    }

    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        bool noCross = (prefixMax[i] <= i) && (suffixMin[i + 1] >= i + 1);

        bool noright = suffixNoT[i + 1];

        if (noCross && noright) {
            cnt++;
        }
    }

    return d + 2LL * cnt;

    return 0;
}
