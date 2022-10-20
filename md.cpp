#include <iostream>
typedef long long ll;

const int MOD = 1e9 + 7;

struct md {
  int v; 
  md() : v(0) { }
  md(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }

  md& operator += (const md& o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
  md& operator -= (const md& o) { if ((v -= o.v) < 0) v += MOD; return *this; }
  md& operator *= (const md& o) { v = (ll) v * o.v % MOD; return *this; }
  md& operator /= (const md& o) { return *this *= inv(o); }

  friend md operator+(md a, const md b) { return a += b; }
  friend md operator-(md a, const md b) { return a -= b; }
  friend md operator*(md a, const md b) { return a *= b; }
  friend md operator/(md a, const md b) { return a /= b; }
  
  friend bool operator == (const md& a, const md& b) { return a.v == b.v; }
  friend bool operator != (const md& a, const md& b) { return a.v != b.v; }

  friend md binpow(md a, ll b) {
    md res = 1;
    while (b) {
      if (b & 1) res *= a;
      a *= a; b >>= 1;
    }
    return res;
  }
  friend md inv(md a) {
    return binpow(a, MOD - 2);
  }
};
