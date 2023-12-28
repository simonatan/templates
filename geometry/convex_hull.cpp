#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <map>
#include <stack>
#include <unordered_set>
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
const int MX = 5e5 + 5;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e6;
const double MAX_ERROR = 1e-7;
const int INF = 1e9 + 5;

template <class T> bool min(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T> bool max(T& a, const T& b) {
    return b > a ? a = b, 1 : 0;
}

#define point std::pair<ll, ll>

point operator - (const point &a, const point &b) { return {a.f - b.f, a.s - b.s}; }

ll cross(const point &a, const point &b) { return a.f * b.s - a.s * b.f; }
ll cross(const point &p, const point &a, const point &b) { return cross(p - a, p - b); }
ll sq(const ll &a) { return a * a; }
ll norm(const point &a) { return sq(a.f) + sq(a.s); }

std::istream& operator >> (std::istream& is, point &a) { return is >> a.f >> a.s; }

int n;
std::vector<point> points;

std::vector<int> cnvhull() {
    int ind = int(std::min_element(all(points)) - points.begin());
    std::vector<int> cand, hull{ind};
    for(int i = 0; i < n; i++) {
        if (points[i] != points[ind]) cand.push_back(i);
    }
    std::sort(all(cand), [&] (const int &a, const int &b) {
       point F = points[a] - points[ind], S = points[b] - points[ind];
       ll c = cross(F, S);
       return c != 0 ? c > 0 : norm(F) < norm(S); 
    });
    
    for(int &c : cand) {
        while (hull.size() > 1 && cross(points[end(hull)[-2]], points[hull.back()], points[c])) {
            hull.pop_back();
        }
        hull.push_back(c);
    }
    return hull;
}

void solve() {
    for(int i = 0; i < n; i++) {
        point a; std::cin>>a;
        points.push_back(a);
    }

    std::vector<int> ret = cnvhull();
    std::cout<<ret.size()<<"\n";
    for(int &a : ret) std::cout<<a<<" ";
    std::cout<<"\n";
}

int main () {
    fast_io;
    std::cin>>n;
    while (n) {
        solve();
        std::cin>>n;
    }
    
    return 0;
}
