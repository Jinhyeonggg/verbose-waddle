#include <bits/stdc++.h>
using namespace std;

int N, K;

/*
A, B -> k

AAAAA BBBBB 

AAA BBB CCC CC

AAA BBB -> 9

AA BA BB -> 8
AA BBA B -> 7
AA BBB A -> 6

A BABB A -> 5
A BBAB A -> 4
A BBBA A -> 3

B A

n/2 * n/2 = n^2/4
n/3 * n/3 + n/3 *n/3 + n/3*n/3 = 3 * n^2/9 = n^2/3

N=4 
AABB -> 4
ABCC -> 5

AA BB CC -> 12

AA B CB C -> 11

AA B CC B -> 10

AA CC BB

A A A C C C C A C B B B B B A

A -> 10+10+10+6
B C

AAAA BB CC 
or
AA BB CCCC
*/


string solve() {

    int n = N / 3;
    int numA = n, numB = n, numC = n + N % 3;
    if (numB + 2 == numC) {
        numB++;
        numC--;
    }
    int M = numA * numB + numB * numC + numA * numC;

    if (M < K) return "-1";
    int toDecrease = M - K;
    int decreased = 0;

    string ans = "";
    for (int i = 0; i < numA; i++) {
        ans += 'A';
    }
    for (int i = 0; i < numB; i++) {
        ans += 'B';
    }
    for (int i = 0; i < numC; i++) {
        ans += 'C';
    }

    int bubble = numA + numB - 1;
    int toBubble = numA + numB - 1;

    while (decreased < toDecrease && bubble >= 0) {
        if (toBubble == N - 1 || ans[toBubble] == ans[toBubble + 1]) {
            bubble -= 1;
            toBubble = bubble;
        }
        else {
            swap(ans[toBubble], ans[toBubble + 1]);
            decreased++;
            toBubble++;
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    cout << solve() << endl;
    return 0;
}