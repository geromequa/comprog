
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int distributePies(priority_queue<int> households, int p, int h)
{
    if (h == 1)
        return (1 + (households.top() - 1) / p);
    p -= h;
    rep(i, p)
    {
        if (households.empty())
            return 0;
        int tmp = households.top();
        if (tmp == 1)
            break;
        households.pop();
        households.push(1 + ((tmp - 1) / 2));
    }
    return households.top();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    rep(i, t)
    {
        int h, p;
        cin >> h >> p;
        priority_queue<int> households;
        rep(i, h)
        {
            int tmp;
            cin >> tmp;
            households.push(tmp);
        }
        cout << distributePies(households, p, h) << endl;
    }

    return 0;
}
