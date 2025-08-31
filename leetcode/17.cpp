#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> numToChar = {
    {'1', {}},
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},

};

vector<string> ans = {};
string digits;

void helper(string cur, int idx) {
    if (idx == digits.length()) ans.push_back(cur);
    else {
        for (char c: numToChar[digits[idx]]) {
            helper(cur + c, idx + 1);
        }
    }
}

void solve() {
    helper("", 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> digits;
    solve();
    for (string s: ans) {
        cout << s << endl;
    }
    // cout << solve() << endl;
    return 0;
}