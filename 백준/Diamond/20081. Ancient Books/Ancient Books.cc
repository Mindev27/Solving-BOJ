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

풀이 보고 풂
*/
const int MAXN = 1000005;

int n;
int a[MAXN];
int compId[MAXN];
int compL[MAXN];
int compR[MAXN];
int vis[MAXN];
int compCnt;

void extendInterval(int &l, int &r) {
    int leftPos = min(compL[compId[l]], compL[compId[r]]);
    int rightPos = max(compR[compId[l]], compR[compId[r]]);

    while (l > leftPos || r < rightPos) {
        if (l > leftPos) {
            --l;
            leftPos = min(leftPos, compL[compId[l]]);
            rightPos = max(rightPos, compR[compId[l]]);
        }
        else {
            ++r;
            leftPos = min(leftPos, compL[compId[r]]);
            rightPos = max(rightPos, compR[compId[r]]);
        }
    }
}

ll minimum_walk(vector<int> p, int s) {
    n = (int)p.size();

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] = p[i];
        ans += abs(i - p[i]);
    }

    if (ans == 0)
        return 0;

    // vis 초기화
    for (int i = 0; i < n; i++)
        vis[i] = 0;

    int nonTrivL = s, nonTrivR = s;
    compCnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;

        ++compCnt;
        compL[compCnt] = compR[compCnt] = i;

        int u = i;
        while (!vis[u]) {
            vis[u] = 1;
            compId[u] = compCnt;
            compL[compCnt] = min(compL[compCnt], u);
            compR[compCnt] = max(compR[compCnt], u);
            u = a[u];
        }

        if (a[i] != i) {
            nonTrivL = min(nonTrivL, compL[compCnt]);
            nonTrivR = max(nonTrivR, compR[compCnt]);
        }
    }

    int l = s, r = s;

    while (true) {
        extendInterval(l, r);

        int lp = l, rp = r;
        int lq = l, rq = r;
        ll lCost = 0, rCost = 0;

        while (lp > nonTrivL && rp == r) {
            --lp;
            extendInterval(lp, rp);
            lCost += 2;
        }

        while (rq < nonTrivR && lq == l) {
            ++rq;
            extendInterval(lq, rq);
            rCost += 2;
        }

        if (rp == r) {
            ans += lCost + rCost;
            break;
        }

        ans += min(lCost, rCost);
        l = lp;
        r = rp;
    }

    return ans;
}