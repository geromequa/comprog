
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int calculateWaterVolume(string s)
{
    int volume = 0;
    int x = 0;
    stack<int> downslopes;
    rep(i, s.length())
    {
        switch (s[i])
        {
        case '_':
            x++;
            break;
        case '/':
            if (!downslopes.empty())
            {
                volume += x - downslopes.top();
                downslopes.pop();
            }
            x++;
            break;
        case '\\':
            downslopes.push(x);
            x++;
            break;

        default:
            break;
        }
    }

    return volume;
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
        string s;
        cin >> s;
        cout << calculateWaterVolume(s) << endl;
    }
    return 0;
}
