
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

vector<int> paintFence(vector<pair<int, int>> jobs, vector<int> colors, int fencesize, int fencestart)
{
    vector<int> fence = vector<int>(fencesize, -1);
    vector<int> volume = vector<int>(colors.size(), 0);
    for (int i = jobs.size(); 0 <= i; i--)
    {
        for (int j = jobs[i].first - fencestart; j <= jobs[i].second - fencestart - 1; j++)
        {
            if (fence[j] != -1)
                continue;
            fence[j] = colors[i];
        }
    }

    return fence;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll fencesize = pow(10.0, 12);
    int n, m;
    int min = fencesize, max = 0;
    cin >> n;
    cin >> m;
    vector<pair<int, int>> jobs = vector<pair<int, int>>(m);
    vector<int> colors = vector<int>(m);
    int l, r;
    cin >> l;
    cin >> r;
    min = l;
    max = r;
    jobs[0] = make_pair(l, r);
    cin >> colors[0];
    rep(i, m - 1)
    {
        int l, r;
        cin >> l;
        cin >> r;
        if (l < min)
            min = l;
        if (r > max)
            max = r;
        jobs[i + 1] = make_pair(l, r);
        cin >> colors[i + 1];
    }
    fencesize = max - min + 2;
    vector<int> fence = paintFence(jobs, colors, fencesize, min);
    vector<int> volume = vector<int>(n, 0);
    rep(i, fencesize)
    {
        if (fence[i] != -1)
            volume[fence[i]]++;
    }
    rep(i, n)
    {
        cout << volume[i] << endl;
    }
    return 0;
}
