#include<bits/stdc++.h>
using namespace std;

bool is_possible(vector<vector<int>> segs, int k) {
    vector<int> hm(51);
    for (int i = 0; i < segs.size(); i++) {
        if (k >= segs[i][0] && k <= segs[i][1]) {
            for (int j = segs[i][0]; j <= segs[i][1]; j++) {
                hm[j]++;
            }
        }
    }
    for (int i = 1; i < 51; i++) {
        if (i != k && hm[i] == hm[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> segs;
        while (n--) {
            int a, b;
            vector<int> temp;
            cin >> a >> b;
            temp.push_back(a);
            temp.push_back(b);
            segs.push_back(temp);
        }
        if (is_possible(segs, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}