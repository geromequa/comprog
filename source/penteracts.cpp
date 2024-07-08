#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define LLMAX       numeric_limits<ll>::max()

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using ull = unsigned long long;

ll mul(ll a, ll b) {
    if (b == 1) return a;
    ll result = mul(a << 1, b >> 1);
    if (b & 1) result = result + a;
    return result;
}

ll pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ll result = pow(mul(a,a), n >> 1);
    if (n & 1) result = mul(result, a);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll x;
    cin >> x;

    vector<pair<ll,ll>> pows;
    for (int i = -119; i <= 119; i++) {
        pows.push_back({i,pow(i, 5)});
    }

    for (auto & a: pows) {
        for (auto & b: pows) {
            if (a.second - b.second == x) {
                cout << a.first << " " << b.first << endl;
                return 0;
            }
        }
    }

    return 0;
}