#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
string S;
vector<int> pi;

void getPi() {
    int j = 0;

    for (int i = 1; i < N; i++) {
        while (j > 0 && S[i] != S[j]) {
            j = pi[j - 1];
        }

        if (S[i] == S[j]) {
            j++;
            pi[i] = j;
        }
    }
}

int solve() {
    getPi();
    // for (int i: pi) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    return N - pi[N - 1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> S;
    pi.resize(N, 0);

    cout << solve() << endl;
    return 0;
}