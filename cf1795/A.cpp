#include<bits/stdc++.h>
using namespace std;

bool is_possible(string a, string b, int n, int m) {
    int flag = 1;
    char c;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            flag--;
            c = 'a';
            break;
        }
    }
    for (int i = 0; i < m - 1; i++) {
        if (b[i] == b[i + 1]) {
            flag--;
            c = 'b';
            break;
        }
    }
    if (flag == 1) {
        return true;
    }
    if (flag == -1) {
        return false;
    }
    char a1 = a[n - 1];
    char b1 = b[m - 1];
    if (c == 'a') {
        while (a1 != b1) {
            b1 = a1;
            n--;
            a1 = a[n - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                return false;
            }
        }
        return true;
    } else {
        while (b1 != a1) {
            a1 = b1;
            m--;
            b1 = b[m - 1];
        }
        for (int i = 0; i < m - 1; i++) {
            if (b[i] == b[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        if (is_possible(a, b, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}