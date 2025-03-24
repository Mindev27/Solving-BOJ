#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    Node* prev, * next;
    Node(char cc = 0) : c(cc), prev(nullptr), next(nullptr) {}
};

struct LinkedList {
    Node* head, * tail, * rth;
    int sz, r;

    LinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        sz = 0;    // 리스트 내 실제  개수
        r = 0;     // 현재 rthNode가 몇 번째인지
        rth = head; // 초기엔 head를 가리키게
    }

    void pushBack(char c) {
        Node* n = new Node(c);
        Node* p = tail->prev;
        p->next = n;  n->prev = p;
        n->next = tail; tail->prev = n;
        sz++;
    }

    void removeNode(Node* n) {
        Node* p = n->prev;
        Node* q = n->next;
        p->next = q;
        q->prev = p;
        sz--;
    }

    void addFront(Node* n) {
        Node* f = head->next;
        head->next = n; n->prev = head;
        n->next = f; f->prev = n;
        sz++;
    }

    void addBack(Node* n) {
        Node* p = tail->prev;
        p->next = n; n->prev = p;
        n->next = tail; tail->prev = n;
        sz++;
    }

    void moveLeft() {
        if (sz < 2) return;

        Node* front = head->next;
        removeNode(front);
        addBack(front);

        rth = rth->next;
        if (rth == tail) rth = head->next;
    }

    void moveRight() {
        if (sz < 2) return;

        Node* back = tail->prev;
        removeNode(back);
        addFront(back);

        rth = rth->prev;
        if (rth == head) rth = tail->prev;
    }

    void incR() {
        if (r < sz) { r++; rth = rth->next; }
    }

    void decR() {
        if (r > 0) { r--; rth = rth->prev; }
    }

    void setR(int R) {
        while (r < R) incR();
        while (r > R) decR();
    }

    void exchange(LinkedList& o, int R) {

        setR(R);
        o.setR(R);

        Node* thisFirst = head->next;
        Node* thisRth = rth;
        Node* thisRNext = thisRth->next;

        Node* otherFirst = o.head->next;
        Node* otherRth = o.rth;
        Node* otherRNext = otherRth->next;

        head->next = otherFirst;
        otherFirst->prev = head;

        otherRth->next = thisRNext;
        thisRNext->prev = otherRth;

        o.head->next = thisFirst;
        thisFirst->prev = o.head;

        thisRth->next = otherRNext;
        otherRNext->prev = thisRth;

        // 교환 뒤 rth 포인터도 서로 버꾸기
        Node* tmp = this->rth;
        this->rth = o.rth;
        o.rth = tmp;
    }

    // 문자열로 바꾸기
    string getString() {
        string s;
        s.reserve(sz);
        Node* cur = head->next;
        while (cur != tail) {
            s.push_back(cur->c);
            cur = cur->next;
        }
        return s;
    }
};

void solve() {
    int N, R, Q;
    cin >> N >> R >> Q;

    string s1, s2;
    cin >> s1 >> s2;

    LinkedList belt1, belt2;
    for (char c : s1) belt1.pushBack(c);
    for (char c : s2) belt2.pushBack(c);

    belt1.setR(R);
    belt2.setR(R);

    while (Q--) {
        char op;
        cin >> op;
        if (op == 'S') {
            belt1.exchange(belt2, R);
        }
        else if (op == 'L') {
            int x; cin >> x;
            (x == 1 ? belt1 : belt2).moveLeft();
        }
        else if (op == 'R') {
            int x; cin >> x;
            (x == 1 ? belt1 : belt2).moveRight();
        }
        else if (op == 'I') {
            R++;
        }
        else if (op == 'D') {
            R--;
        }
    }

    cout << belt1.getString() << "\n";
    cout << belt2.getString() << "\n";
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