// https://oj.uz/problem/view/IZhO12_apple

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
    int lx, rx, add, sum = 0; // interval, lazy add, sum of interval
    node *left, *right; // pointers to children

    node(int lx, int rx) : lx(lx), rx(rx) {
        left = right = nullptr;
        add = INF;
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

    void push() {
        if (lx == rx || add == INF) return; // at a child node and can't push any further or nothing to add
        int m = lx + (rx - lx) / 2;
        if (!left) return; // no children
        left->add = add;
        right->add = add;
        left->sum = (m - lx + 1) * add;
        right->sum = (rx - m + 1) * add;
        add = INF;
    }

    void upd(int v, int l, int r) {
        if (r < lx || l > rx) return;
        if (l >= lx && rx <= r) {
            sum = (rx - lx + 1) * v;
            add = v;
            return;
        }
        extend(); push();
        int m = lx + (rx - lx) / 2;
        // go down a child only when necessary
        if (l <= m) left->upd(v, l, r);
        if (r > m) right->upd(v, l, r);
        sum = left->sum + right->sum;
    }

    int query(int l, int r) {
        if (r < lx || l > rx) return 0;
        if (l >= lx && rx <= r) return sum;
        extend(); push();
        int m = lx + (rx - lx) / 2;
        int res = 0;
        if (l <= m) res += left->query(l, r);
        if (r > m) res += right->query(l, r);
        return res;
    }
};


int main () {
    fast_io;
    int q; std::cin>>q;
    node root(1, INF);
    int c = 0;
    for( ; q; q--) {
        int ty, x, y; std::cin>>ty>>x>>y; x += c; y += c;
        if (ty == 1) {
            c = root.query(x, y);
            std::cout<<c<<"\n";
        } else {
            root.upd(1, x, y);
        }
    }

    return 0;
}
