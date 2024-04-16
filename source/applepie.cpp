
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int distributePies(priority_queue<tuple<int, int, int>> households, int p, int h)
{
    if (h == 1)
        return (1 + (get<0>(households.top()) - 1) / p);
    p -= h;
    rep(i, p)
    {
        if (households.empty())
            return 0;
        tuple<int, int, int> current = households.top();
        if (get<0>(current) == 1)
            break;
        households.pop();
        get<2>(current)++;
        get<0>(current) = 1 + (get<1>(current) - 1) / get<2>(current);
        households.push(current);
    }
    return get<0>(households.top());
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
        priority_queue<tuple<int, int, int>> households;
        rep(i, h)
        {
            int tmp;
            cin >> tmp;
            households.push(make_tuple(tmp, tmp, 1));
        }
        cout << distributePies(households, p, h) << endl;
    }

    return 0;
}
