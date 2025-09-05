#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> nCk;
ll M = 1000000007;
ll N, L, R;
vector<vector<ll>> dpLeft, dpRight;
vector<ll> pac;

void getComb(ll n) {
    nCk[0][0] = 1;
    nCk[1][0] = 1, nCk[1][1] = 1;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            if (j == 0 || j == i) nCk[i][j] = 1;
            else nCk[i][j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % M;
        }
    }
}

void getPac(ll n) {
    ll cur = 1;
    for (ll i = 1; i <= n; i++) {
        cur *= i;
        cur = cur % M;
        pac[i] = cur;
    }
}

ll lHelper(ll n, ll k) {
    if (dpLeft[n][k] != -1) return dpLeft[n][k];
    if (n == 0 && k == 0) return 1;
    if (n != 0 && k == 0) return 0; 
    if (n < k) return 0;
    
    ll ans = 0;
    for (ll topPos = 0; topPos < n; topPos++) {
        ll numLeft = topPos, numRight = n - topPos - 1;
        ans += nCk[n - 1][numLeft] * lHelper(numLeft, k - 1) % M * pac[numRight] % M;
        ans = ans % M;
    }

    dpLeft[n][k] = ans;
    return ans;
}

ll rHelper(ll n, ll k) {
    if (dpRight[n][k] != -1) return dpRight[n][k];
    if (n == 0 && k == 0) return 1;
    if (n != 0 && k == 0) return 0; 
    if (n < k) return 0;
    
    ll ans = 0;
    for (ll topPos = 0; topPos < n; topPos++) {
        ll numLeft = topPos, numRight = n - topPos - 1;
        ans += nCk[n - 1][numLeft] * pac[numLeft] % M * rHelper(numRight, k - 1) % M;
        ans = ans % M;
    }

    dpRight[n][k] = ans;
    return ans;
}

ll solve() {
    getComb(N);
    getPac(N);
    ll ans = 0;
    for (ll topPos = 0; topPos < N; topPos++) {
        ll numLeft = topPos, numRight = N - topPos - 1;
        ans += nCk[N - 1][numLeft] * lHelper(numLeft, L - 1) % M * rHelper(numRight, R - 1) % M;
        ans = ans % M;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> L >> R;
    nCk.resize(N + 1, vector<ll>(N + 1, 0));
    pac.resize(N + 1, 1);
    dpLeft.resize(N + 1, vector<ll>(N + 1, -1));
    dpRight.resize(N + 1, vector<ll>(N + 1, -1));
    
    dpLeft[1][0] = 0, dpLeft[1][1] = 1;
    dpRight[1][0] = 0, dpRight[1][1] = 1;

    cout << solve() << endl;
    return 0;
}