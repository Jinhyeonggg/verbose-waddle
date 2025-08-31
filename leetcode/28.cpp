#include <bits/stdc++.h>
using namespace std;

int solve(string haystack, string needle) {
    if (needle.length() > haystack.length()) return -1;
    else {
        for (int i = 0; i < haystack.length(); i++) {
            int flag = 1;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i+j] != needle[j]) {
                    flag = -1;
                    break;
                }
            }
            if (flag == 1) return i;
        }
    }
    return -1;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string haystack, needle;
    cin >> haystack >> needle;
    cout << solve(haystack, needle) << endl;
    return 0;
}