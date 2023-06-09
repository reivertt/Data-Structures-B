#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;
 
map<int, int> g[11];
 
int countPairs(vector<int> a, int n, int k) {
    vector<int> len(n);
    vector<int> p(11);
    p[0] = 1;

    for (int i = 1; i <= 10; i++) {
        p[i] = (p[i-1] * 10) % k;
    }
 
    for (int i = 0; i < n; i++) {
        int x = a[i];
 
        while (x > 0) {
            len[i]++;
            x /= 10;
        }
        g[len[i]][a[i] % k]++;
    }
 
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 10; j++) {
            int r = (a[i] * p[j]) % k;
            int xr = (k - r) % k;
            ans += g[j][xr];
 
            if (len[i] == j && (r + a[i] % k) % k == 0) ans--;
        }
    }
    return ans;
}
 
int main(int argc, char const *argv[]) {
    int n, k;
    vector<int> arr;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << countPairs(arr, n, k);
    return 0;
}