
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n,m;
    cin >> n >> m;
    string s,t;
    rep(i,n) {
        int c;
        cin >> c;
        s.push_back(c);
    }
    rep(i,m) {
        int c;
        cin >> c;
        t.push_back(c);
    }
    if (n > m){
        while (t.size() <= s.size()) {
            t = t + t;
        }
        if (t.find(s) != string::npos) {
            cout << "YES" << endl;
            return 0;
        }
    } else { 
        while(s.size() <= t.size()) {
            s = s + s;
        }
        if (s.find(t) != string::npos) {
            cout << "YES" << endl;
            return 0;
        } 
    }
    cout << "NO" << endl;
    return 0;
}
