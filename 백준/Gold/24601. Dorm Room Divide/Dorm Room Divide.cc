#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Point {
    double x, y;
};

double area(Point &a, Point &b, Point &c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

void solve(){
    int N;
    cin >> N;

    Point p[200005];
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    Point piv = p[0];
    double total = 0;
    double prefix[200005];
    memset(prefix, 0, sizeof(prefix));

    for (int i = 1; i < N - 1; i++) {
        total += area(piv, p[i], p[i + 1]);
        prefix[i] = total;
    }

    // 반나누는 곳 찾기
    double halfArea = total / 2.0;
    int l = 1, r = N - 2;
    Point ans;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[mid] >= halfArea) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    double rem = halfArea - prefix[r];
    double seg = area(piv, p[r + 1], p[r + 2]);
    double ratio = rem / seg;

    // 내분점
    ans.x = p[r + 1].x + ratio * (p[r + 2].x - p[r + 1].x);
    ans.y = p[r + 1].y + ratio * (p[r + 2].y - p[r + 1].y);

    cout << fixed << setprecision(10) << ans.x << " " << ans.y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}