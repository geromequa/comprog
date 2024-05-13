
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int k, c;
    cin >> k >> c;
    vector<int> colors(k);
    for (int i = 0; i < k; i++) {
        cin >> colors[i];
    }

    int left = 0, right = k - 1, counter = 0;
    vector<int> possible_n;
    while (left <= right) {
        if (colors[left] == colors[right]) {
            counter++;
            left++;
            right--;
        } else {
            possible_n.push_back(right + 1 + counter);
            counter = 0;
            right--;
        }
    }
    possible_n.push_back(right + 1 + counter);

    for (int n : possible_n) {
        cout << n << ' ';
    }
    cout << '\n';

    return 0;
}