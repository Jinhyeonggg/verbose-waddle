#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<char> S;
vector<int> pi;

int gcm(int n, int m) {
    if (m > n) swap(n, m);
    if (m == 0) return n;
    if (n % m == 0) return m;

    return gcm(m, n % m);
}
void getPi() {
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (S[i] != S[j] && j > 0) {
            j = pi[j - 1];
        }
        if (S[i] == S[j]) {
            j++;
            pi[i] = j;
        }
    }
}

int KMP() {
    getPi();
    string ss = "";
    for (int i = 0; i < 2; i++) {
        for (char c: S) {
            ss += c;
        }
    }

    int j = 0;
    int ans = 0;
    for (int i = 0; i < 2 * N; i++) {
        while (ss[i] != S[j] && j > 0) {
            j = pi[j - 1];
        }

        if (ss[i] == S[j]) {
            if (j == N - 1) {
                ans++;
                j = pi[j];
            }
            else j++;
        }
    }
    ans--;
    cout << ans/gcm(N, ans) << '/' << N/gcm(N, ans);
    // cout << ans << '/' << N;
    return 0;
}


int solve() {
    KMP();
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    pi.resize(N, 0);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        S.push_back(c);
    }
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
    }

    solve();
    return 0;
}