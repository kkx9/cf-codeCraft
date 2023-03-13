#include<bits/stdc++.h>
using namespace std;
typedef long long int llint;

void solve(vector<llint> tea, vector<llint> tasters, llint n) {
    llint ans;
    llint dk = 0;
    priority_queue<llint> q;
    for (llint i = 0; i < n; i++) {
        ans = 0;
        q.push(-(tea[i] + dk));
        while (!q.empty() && (-(q.top()) - dk) <= tasters[i]) {
            ans += -(q.top()) - dk;
            q.pop();
        }
        ans += (llint)q.size() * tasters[i];
        dk += tasters[i];
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    llint t;
    cin >> t;
    while (t--) {
        llint n;
        cin >> n;
        vector<llint> tea(n);
        vector<llint> tasters(n);
        llint temp;
        for (llint i = 0; i < n; i++) {
            cin >> tea[i];
        }
        for (llint i = 0; i < n; i++) {
            cin >> tasters[i];
        }
        solve(tea, tasters, n);
    }
    return 0;
}