// https://www.eolymp.com/en/problems/3252

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <map>
#include <stack>
#include <algorithm>

#define dbg(v) std::cerr<<#v<<" = "<<v<<"\n";
#define show(x) std::cerr<<#x<<": "; for(auto i : x) std::cerr<<i<<" "; std::cerr<<"\n";
#define fast_io std::cin.tie(0)->sync_with_stdio(0);
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(std::unique(all(x)), x.end())
#define pii std::pair<int, int>
#define f first
#define s second

using ll = long long;
const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e9;
const double MAX_ERROR = 1e-7;
const int INF = 1e9 + 5;

template <class T> bool min(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T> bool max(T& a, const T& b) {
    return b > a ? a = b, 1 : 0;
}

struct node {
    int lx, rx, val;
    node *left, *right;

    node(int lx, int rx) : lx(lx), rx(rx) {
        left = nullptr;
        right = nullptr;
        val = 0;
    }

    ~node() {
        delete left;
        delete right;
    }

    void extend() {
        if (!left && !right) {
            int m = lx + (rx - lx) / 2;
            left = new node(lx, m);
            right = new node(m + 1, rx);
        }
    }

    void upd(int i, int v) {
        if (i < lx || i > rx) return;
        if (lx < i && i < rx) {
            val = v; return;
        }
        extend();
        right->upd(i, v);
        left->upd(i, v);
        val = left->val + right->val;
    }

    int sum(int l, int r) {
        if (l > rx || r < lx) return 0;
        if (l >= lx && rx <= r) {
            return val;
        }
        extend();
        return left->sum(l, r) + right->sum(l, r);
    }
};

int n, m;

int main () {
    fast_io;
    std::cin>>n>>m;
    node root(1, n);
    int P = 91, Q = 47;

    for(; m; m--) {
        char c; int a, b; std::cin>>c>>a>>b;
        if (c == '!') {
            int i = (a + P) % n, v = (b + Q) % MOD;
            root.upd(i, v);
        } else {
            int l = (a + P) % n, r = (b + Q) % n;
            int z = root.sum(l, r);
            P = (P * 31) + z % MOD;
            Q = (Q * 29) + z % MOD;
            std::cout<<z<<"\n";
        }
    }

    return 0;
}
