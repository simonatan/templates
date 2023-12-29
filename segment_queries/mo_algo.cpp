// O((N + Q)√N)

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
const int MX = 3e4 + 5;
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

int n, ar[MX];
int cnt[MAX_VAL], ans = 0;
int BLOCK_SIZE;

int main () {
    fast_io;
    std::cin>>n;
    BLOCK_SIZE = static_cast<int>(sqrt(n));
    for(int i = 0; i < n; i++) {
        std::cin>>ar[i];
    }
    int q; std::cin>>q;
    using T = std::pair<pii, int>;
    T queries[200005];
    for(int i = 0; i < q; i++) {
        std::cin>>queries[i].f.f>>queries[i].f.s;
        queries[i].s = i;
    }
    // Mo's algo
    std::sort(queries, queries + q, [&] (const T& a, const T& b) {
        int block_a = a.f.f / BLOCK_SIZE, block_b = b.f.f / BLOCK_SIZE;
        if (block_a != block_b) {
            return block_a < block_b;
        }
        return a.f.s < b.f.s;
    });
    //

    auto add = [&] (int x) {
        if (cnt[x]++ == 0) ans++;
    };
    auto remove = [&] (int x) {
        if (--cnt[x] == 0) ans++;
    };

    std::vector<int> answers(q);
    int left = 0, right = -1;
    for(int i = 0; i < q; i++) {
        int new_left = queries[i].f.f, new_right = queries[i].f.s;
        
        while (right < new_right) add(ar[++right]);
        while (right > new_right) remove(ar[right--]);
        while (left < new_left) remove(ar[left++]);
        while (left > new_left) add(ar[--left]);
        
        answers[queries[i].s] = ans;
    }

    for(int i : answers) std::cout<<i<<"\n";
    
    return 0;
}
