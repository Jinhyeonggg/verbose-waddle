#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M = 1000000;
vector<ll> dp(101, -1);
vector<vector<ll>> nCk(101, vector<ll>(101, 0));

void getComb(ll n) {
    nCk[1][0] = 1, nCk[1][1] = 1;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            if (j == 0 || j == i) nCk[i][j] = 1;
            else nCk[i][j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % M;
        }
    }
}

ll helper(ll n) {
    if (n <= 2) return 1;
    if (dp[n] != -1) return dp[n];
    ll ans = 0;
    
    for (ll i = 0; i < n; i++) { // position of '1'
        ll numLeft = i, numRight = n - i - 1;
        if (numLeft % 2 == 0) {
            ans = (ans + 
                (nCk[n-1][numLeft]*helper(numRight))%M * helper(numLeft) % M) 
                % M;
        }

        
    }
    dp[n] = ans;
    return ans;
}

/*
1 3 2 4
1 4 2 3

2 3 1 4
2 4 1 3

3 4 1 2
*/

ll solve() {
    getComb(N);
    dp[1] = 1;
    if(N==1)return 1;
    return (helper(N) * 2) % M;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    cout << solve() << endl;
    return 0;
}