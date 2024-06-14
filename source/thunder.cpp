#include <bits/stdc++.h>
#include <limits.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const double INF = DBL_MAX;

void floyd_warshall(vector<vector<double>> &g, int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
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
        int n;
        cin >> n;
        vector<pair<int, int>> towns(n);
        rep(j, n)
        {
            int x, y;
            cin >> x >> y;
            towns[j] = make_pair(x, y);
        }
        vector<vector<double>> result(n, vector<double>(n, INF));
        rep(j, n)
        {
            rep(k, n)
            {
                double dist = sqrt(pow((towns[j].first - towns[k].first), 2) + pow((towns[j].second - towns[k].second), 2));
                if (dist <= 10)
                {
                    result[j][k] = result[k][j] = dist;
                }
            }
        }
        floyd_warshall(result, n);
        bool impossible = false;
        double max_dist = 0;
        rep(j, n)
        {
            if (impossible)
            {
                break;
            }
            rep(k, n)
            {
                if (result[j][k] == INF)
                {
                    cout << "Send Kurdy" << endl;
                    impossible = true;
                    break;
                }
                else
                {
                    if (j < k)
                        max_dist = max(max_dist, result[j][k]);
                }
            }
        }
        if (!impossible)
        {
            cout << setprecision(4) << fixed;
            cout << max_dist << endl;
        }
    }
    return 0;
}
