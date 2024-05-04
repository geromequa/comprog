
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n, size;
    cin >> n >> size;
    vector<int> items = vector<int>(n);
    int ones = 0, twos = 0, threes = 0;
    for (int i=0; i < n; i++) {
        cin >> items[i];
        switch (items[i]) {
            case 1:
                ones++;
                break;
            case 2:
                twos++;
                break;
            case 3:
                threes++;
                break;
            default:
                cout << "Some wrong value";
                exit(1);
        }
    }

    int sum;
    if (3 * threes < size) {
        sum = 3 * threes;
    } else {
        sum = (size / 3) * 3;
    }

    
    if (2 * twos < size - sum) {
        sum += 2 * twos;
    } else {
        sum += ((size-sum) / 2) * 2;
    }

    if (ones < size - sum) {
        sum += ones;
    } else {
        sum = size;
    }

    int sum2;
    if (threes >= 1) {
        if (3 * threes < size) {
            sum2 = 3 * threes;
        } else {
            sum2 = (size / 3) * 3;
        }
        sum2 -= 3;
    }


    
    if (2 * twos < size - sum2) {
        sum2 += 2 * twos;
    } else {
        sum2 += ((size - sum2) / 2) * 2;
    }

    if (ones < size - sum2) {
        sum2 += ones;
    } else {
        sum2 = size;
    }

    cout << max(sum, sum2) << endl;

    return 0;
}

