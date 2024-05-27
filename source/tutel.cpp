#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

bool tutel(unordered_map<ll, vector<ll>> &M, vector<tuple<ll, ll>> participants, ll danceSum, ll diveSum)
{
    for (auto [a, b] : participants)
    {
        if (M[danceSum - a].empty())
        {
            return false;
        }
        for (int i = 0; i < M[danceSum - a].size(); i++)
        {
            if (diveSum == b + M[danceSum - a][i])
            {
                if (danceSum - a == a)
                {
                    if (M[danceSum - a].size() == 1)
                    {
                        continue;
                    }
                }
                M[danceSum - a].erase(M[danceSum - a].begin() + i);

                break;
            }
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "impossible" << endl;
        return 0;
    }

    unordered_map<ll, vector<ll>> M;
    vector<tuple<ll, ll>> dive(n);
    ll danceSum = 0;
    ll diveSum = 0;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        dive[i] = {a, b};
        danceSum += a;
        diveSum += b;
        M[a].push_back(b);
    }
    if ((abs(danceSum) * 2) % n != 0)
    {
        cout << "impossible" << endl;
        return 0;
    }
    else
    {
        danceSum = (danceSum * 2) / n;
    }
    if ((abs(diveSum) * 2) % n != 0)
    {
        cout << "impossible" << endl;
        return 0;
    }
    else
    {
        diveSum = (diveSum * 2) / n;
    }
    if (tutel(M, dive, danceSum, diveSum))
    {
        cout << "possible" << endl;
    }
    else
        cout << "impossible" << endl;

    return 0;
}
