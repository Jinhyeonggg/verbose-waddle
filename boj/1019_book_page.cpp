#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<ll>> numCount;
int digit = 0;
vector<ll> ans(10, 0);

void count(ll n, int factor) {
    while (n > 0) {
        ans[n % 10] += factor;
        n /= 10;
    }
}

int solve() {
    if (N < 10) {
        for (int i = 1; i <= N; i++) ans[i]++;
        return 0;
    }

    int factor = 1;
    while (N > 0) {
        while (N % 10 != 9) {
            count(N, factor);
            N--;
        }

        for (int i = 0; i <= 9; i++) {
            ans[i] += factor * (N / 10 + 1);
        }
        ans[0] -= factor;

        N = N / 10;
        factor *= 10;
        if (N < 10) {
            // ans[0] -= factor / 10;
            for (int i = 1; i <= N; i++) {
                ans[i] += factor;
            }
            return 0;
        }
    } 
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    
    solve();
    // ans[0]--;
    for (ll n: ans) {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}