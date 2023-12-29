
// dynamic CHT
// + lines are inserted in arbitrary order
// + query positions are in arbitrary order

struct line {
    mutable ll m, c, p;
    bool operator < (const line &o) const { return m < o.m; }
    bool operator < (ll x) const { return p < x; }
};

struct lineContainer : std::multiset<line, std::less<>> {
    static const ll inf = LLONG_MAX;
    static ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool intersect(iterator x, iterator y) {
        if (y == end()) { // x is the last line, it doesn't have a neighbour to intersect with
            x->p = inf;
            return false;
        }
        if (x->m == y->m) { // same slopes, therefore don't intersect
            x->p = (x->c > y->c ? inf : -inf); // we need this to determine whether this line is a part of the CH
        }
        else x->p = div(y->c - x->c, x->m - y->m);
        return x->p >= y->p;
    }

    void add(ll m, ll c) {
        auto nxt = insert({m, c, 0}), pos = nxt++, prv = pos;
        while (intersect(pos, nxt)) nxt = erase(nxt); // delete from right
        if (prv != begin() && intersect(--prv, pos)) intersect(prv, pos = erase(pos));
        while ((pos = prv) != begin() && (--prv)->p >= pos->p) { // delete from left
            intersect(prv, erase(pos));
        }
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }
};
