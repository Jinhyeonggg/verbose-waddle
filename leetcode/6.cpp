#include <bits/stdc++.h>
using namespace std;

string solve(string s, int numRows) {
    /*
    period: 2 * numRows - 2
    0st row: 0, period, 2*period, ...
    1st row: 1, period-1, period+1, 2*period-1, ...
    2nd row: 2, period-2, period+2, 2*period-2, ...

    N-1 st row: N-1, ...
    */
    if (numRows == 1) return s;
    int period = 2 * numRows - 2;
    string ans = "";
    for (int i = 0; i < numRows; i++) {
        int idx = i;
        int front = 1;
        while (idx < s.length()) {
            ans += s[idx];
            if (i == 0 || i == numRows - 1) idx += period;
            else {
                if (front == 1) idx = period*(idx/period + 1) - (idx%period);
                else idx = idx = period*(idx/period + 1) + period*(idx/period + 1) % idx;
                front *= -1;
            }
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s; 
    int numRows;
    cin >> s >> numRows;

    cout << solve(s, numRows) << endl;
    return 0;
}