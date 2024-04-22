
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

vector<ll> parseFenceColors(vector<ll> colors, priority_queue<tuple<ll, ll, int, int>, vector<tuple<ll, ll, int, int>>, greater<tuple<ll, ll, int, int>>> jobs)
{
    tuple<ll, ll, int, int> current, tmp;
    while (!jobs.empty() && get<0>(jobs.top()) == get<1>(jobs.top()))
        jobs.pop();
    if (!jobs.empty())
    {
        current = jobs.top();
        jobs.pop();
    }
    while (!jobs.empty())
    {
        if (get<0>(jobs.top()) == get<1>(jobs.top()))
        {
            jobs.pop();
        }
        else if (get<0>(jobs.top()) >= get<1>(current))
        {
            colors[get<3>(current)] += get<1>(current) - get<0>(current);
            current = jobs.top();
            jobs.pop();
        }
        else if (get<0>(jobs.top()) != get<0>(current))
        { // 2 elements with different starting points
            if (get<2>(jobs.top()) > get<2>(current))
            {
                if (get<1>(jobs.top()) < get<1>(current))
                {
                    colors[get<3>(current)] += get<0>(jobs.top()) - get<0>(current);
                    get<0>(current) = get<1>(jobs.top());
                    jobs.push(current);
                    current = jobs.top();
                    jobs.pop();
                }
                else
                {
                    colors[get<3>(current)] += get<0>(jobs.top()) - get<0>(current);
                    current = jobs.top();
                    jobs.pop();
                }
            }
            else
            {
                if (get<1>(jobs.top()) <= get<1>(current))
                {
                    jobs.pop();
                }
                else
                {
                    colors[get<3>(current)] += get<0>(jobs.top()) - get<0>(current);
                    get<0>(current) = get<0>(jobs.top());
                    tmp = jobs.top();
                    jobs.pop();
                    get<0>(tmp) = get<1>(current);
                    jobs.push(tmp);
                }
            }
        }
        else
        { // 2 elements with same starting point
            if (get<2>(jobs.top()) > get<2>(current))
            {
                current = jobs.top();
                jobs.pop();
            }
            else
            {
                if (get<1>(jobs.top()) <= get<1>(current))
                {
                    jobs.pop();
                }
                else
                {
                    tmp = jobs.top();
                    jobs.pop();
                    get<0>(tmp) = get<1>(current);
                    jobs.push(tmp);
                }
            }
        }
    }

    colors[get<3>(current)] += get<1>(current) - get<0>(current);

    return colors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, color;
    ll l, r;
    cin >> n >> m;

    priority_queue<tuple<ll, ll, int, int>, vector<tuple<ll, ll, int, int>>, greater<tuple<ll, ll, int, int>>> jobs;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> color;
        jobs.push(make_tuple(l, r, i, color));
    }
    vector<ll> colors(n, 0);
    colors = parseFenceColors(colors, jobs);
    for (int i = 0; i < n; i++)
    {
        cout << colors[i] << endl;
    }

    return 0;
}
