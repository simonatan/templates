int sum(int a, int b) {
    while (b > 0) {
        int carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    return a;
}

int mult(int a, int b) {
    int res = 0;
    while (b > 0) {
        if (b & 1) res = sum(res, a);
        a <<= 1; b >>= 1;
    }
    return res;
}

int xor_(int a, int b) {
    return ~((a & b) & (a | b));
}
