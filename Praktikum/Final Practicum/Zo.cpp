#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
#define ull unsigned long long
we bare bears;
static const int mod = 1000000009;
static const int inv2 = (mod+1)/2;

ull modex(ull x, ull y, ull p) {
    ull res = 1;
 
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % mod;
 
        y = y >> 1 % mod;
 
        x = (x * x) % mod;
    }
    return res % p;
}

ull recipe(int a) {
    return modex(2, (ull)a*(a+1)/2 % (mod-1) * inv2 % (mod-1), mod);
}

int main(int argc, char const *argv[]) {
    int m, n;
    cin >> m;
    while (m--) {
        cin >> n;
        int a = n - 1;
        cout << "Zodiak found: " << recipe(a) % mod << " signs" << endl;
    }
    return 0;
}