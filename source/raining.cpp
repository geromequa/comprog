
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

    int t;
    cin >> t;
    vector<string> cases;
    rep(input, t)
    {
        string s;
        cin >> s;
        cases.insert(cases.end(), s);
    }

    vector<int> results;
    int peak;
    int x;
    int y;
    rep(c, t)
    {
        results.insert(results.end(), 0);
        peak = 0;
        x = 0;
        y = 0;
        priority_queue<pair<int, int>> flats;
        int length = cases[c].length();
        while (cases[c].at(x) != '\\')
        {
            x++;
            if (cases[c].at(x) == '/')
                y++;
        }
        while (x < length)
        {
            switch (cases[c].at(x))
            {
            case '/':
                if (peak >= y)
                {
                    while (!flats.empty() && flats.top().second <= y)
                    {
                        pair<int, int> tmp = flats.top();
                        flats.pop();
                        results[c] += tmp.first;
                    }
                }
                results[c] += ((abs(peak - y) - 1) * 2 + 1);
                x++;
                y++;
                break;
            case '_':
            {
                if (!flats.empty())
                {
                    pair<int, int> tmp = flats.top();

                    if (tmp.second == y)
                    {
                        tmp.first++;
                        flats.pop();
                        flats.push(tmp);
                    }
                    else
                        flats.push({1, y});
                }
                else
                {
                    flats.push({1, y});
                }
                x++;
                break;
            }
            case '\\':
                if (peak <= y)
                {
                    peak = y;
                    while (!flats.empty())
                    {
                        flats.pop();
                    }
                }
                y--;
                x++;
            default:
                break;
            }
        }
    }
    rep(c, t) cout << results[c] << endl;

    return 0;
}