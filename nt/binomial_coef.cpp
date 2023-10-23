ll exp(ll x, ll a) {
    x %= MOD;
    ll res = 1;
    while (a > 0) {
        if (a % 2) res = res * x % MOD;
        x = x * x % MOD;
        a /= 2;
    }
    return res;
}

ll fac[MX + 1];
void fact() {
    fac[0] = 1;
    for(int i = 1; i <= MX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll inv[MX + 1];
void inverse() {
    inv[MX] = exp(MX, MOD - 2);
    for(int i = MX; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

ll choose(ll n, ll k) {
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}
