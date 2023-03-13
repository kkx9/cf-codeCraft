#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;

// 快速幂求逆元
ll quick_pow(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

// 求排列
ll permutation(ll low, ll up) {
    ll ret = 1;
    for (ll i = low; i > low - up; i--) {
        ret = ret * i % MOD;
    }
    return ret;
}

ll solve(vector<int> edges) {
    ll ans = 1;
    int n = edges.size();
    for (int i = 0; i < n - 1; i += 3) {
        if (edges[i] == edges[i + 1] && edges[i + 1] == edges[i + 2]) {
            ans = ans * 3 % MOD;
        } else if (edges[i] > edges[i + 1] && edges[i + 1] == edges[i + 2]) {
            ans = ans * 2 % MOD;
        } else if (edges[i + 1] > edges[i] && edges[i] == edges[i + 2]) {
            ans = ans * 2 % MOD;
        } else if (edges[i + 2] > edges[i] && edges[i] == edges[i + 1]) {
            ans = ans * 2 % MOD;
        }
    }
    ans = ans * permutation(n / 3, n / 6) % MOD;
    ll temp = permutation(n / 6, n / 6);
    ans = ans * quick_pow(temp, MOD - 2) % MOD;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> edges(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }
    cout << solve(edges) << endl;
    return 0;
}