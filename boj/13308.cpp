#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
vector<ll> prices; // oil price per 1L at n-th node
vector<vector<pair<ll, ll>>> graph;
priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq; // cost, node, price
ll solve() {
    
    pq.push({0, 1, prices[1]});
    // vector<ll> dists(N + 1, 1e9);
    // vector<vector<pair<ll, ll>>> dists(N + 1, {{1e9, 1e9}}); // cost, price
    // dists[1] = {{0, 5}};
    vector<map<ll, ll>> dists(N + 1); // dists[node][price] -> cost
    dists[1][0] = 0;
    
    ll ans = 1e9;
    while (!pq.empty()) {
        vector<ll> v = pq.top();
        ll cost = v[0];
        ll cur = v[1];
        ll price = v[2];

        for (pair<ll, ll> p: graph[cur]) {
            ll next = p.first;
            ll dist = p.second;
            ll new_price = min(price, prices[cur]);
            ll new_cost = cost + new_price * dist;

            bool should_push = true;
            auto it = dists[next].lower_bound(new_price);
            if (it != dists[next].begin()) {
                if ((it-1)->)
            }
            for (auto &d : dists[next]) {
                if (d.first <= new_cost && d.second <= new_price) {
                    should_push = false; // 이미 더 좋은 상태 존재
                    break;
                }
            }

            if (should_push) {
                dists[next].push_back({new_cost, new_price});
                pq.push({new_cost, next, new_price});
            }
        }
        pq.pop();
    }
    for (auto &it: dists[N]) {
        ans = min(ans, it.first);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    prices.resize(N + 1);
    graph.resize(N + 1);
    for (ll i = 1; i <= N; i++) {
        ll t; cin >> t;
        prices[i] = t;
    }
    for (ll i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cout << solve() << endl;
    return 0;
}