#include<bits/stdc++.h>
using namespace std;

void getNext(vector<int>& next, string p) {
    int j;
    j = 0;
    next[0] = 0;
    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) {
            j = next[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
}

int main() {
    string s = "aaacaaab";
    string p = "acab";
    vector<int> next(p.size());
    getNext(next, p);
    int i, j;
    i = j = 0;
    while (i < s.size() && j < p.size()) {
        while (j > 0 && s[i] != p[j]) {
            j = next[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        i++;
    }
    if (j == p.size()) {
        cout << "success!\n";
    } else {
        cout << "fail!\n";
    }
    return 0;
}