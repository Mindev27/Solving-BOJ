// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
2000이라 N^2하면 되나
중간에 경유해서 한번에 여러개 옮기는게 더 이득일때가 있네
플로이드워셜 돌리기에는 터지고..

일단 k로 옮긴다고 해보자. 무조건 각 좌표에서 한번씩 옮겨야하는건 자명함
간선이 총 N^2개임 여기서 뭘 채택하지
느낌상 트리가 되어야할듯함 

일단 k방향으로 하는 유향 그래프중에서 k로 이을때
가중치를 거리 더하기 비용으로 가중치를 매기고 트리를 만들자
아 근데 k방향이 아닌방향으로 만들면 애매한데

매 시행마다 트리를 만들어야할까? 
간선 N^2개에 크루스칼N^2logN^2 
돌리면 N^3logN^2인디 더 줄일 방법이 있나


일단 방식이 k아래에 서브트리가 있으면 그 서브트리를 다 모으고 한번에 하는게 무조건 최적임
방향을 안정하고 한번에 트리롤 못만들까?

사실 물류 트리는 맨해튼 거리만 쓰면 안되나
안됨

일단 루트에 상관없이 트리모양이 똑같을거 같음
이걸 어떻게 만드냐가 관건인데

일단 서브트리를 다 계산할때 deg(x) - 1만큼 더해질거임
그럼 각각이 (deg(x) - 1) * cost(x)인데 (k빼고)

MST 비용을 계산할때 이걸 어떻게 적용하지
근데 결국 모든 degree * 간선 가중치면
모든 간선의 시작 끝점을 더하는게 아닌가?

그러면 가중치를 cx+cy로하면 되는거 맞네
그러면 무향그래프고 딱 되는듯


*/



struct grage {
    ll x, y, c;
};

ll N;
ll allCost = 0;
ll total = 0;
ll p[2005];
vector<grage> v;

int find(ll x) {
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}

void Merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    if(b > a) p[b] = a;
    else p[a] = b;
}


void solve() {
    cin >> N;
    for(ll i = 0; i <= N; i++) p[i] = i;
    v.resize(N);
    for(auto &i : v) {
        cin >> i.x >> i.y >> i.c;
        total += i.c;
    }

    vector<pair<ll, pll>> edge;
    for(ll i = 0; i < N; i++) {
        for(ll j = i+1; j < N; j++) {
            ll cost = llabs(v[i].x - v[j].x) + llabs(v[i].y - v[j].y) + v[i].c + v[j].c;
            edge.push_back({cost, {i, j}});
        }
    }

    sort(edge.begin(), edge.end());

    
    for(auto i : edge) {
        ll cost = i.X;
        ll u = i.Y.X;
        ll v = i.Y.Y;

        if(find(u) == find(v)) continue;

        Merge(u, v);
        allCost += cost;
    }

    for(ll i = 0; i < N; i++) {
        cout << allCost - total + v[i].c << ' ';
    }

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