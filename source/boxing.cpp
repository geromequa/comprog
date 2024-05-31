#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define INF 1e9

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

typedef pair<ll, ll> pll;

// The eight possible moves for a knight
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(ll x, ll y, ll w, ll h)
{
    return x >= 0 && y >= 0 && x < h && y < w;
}

void boxing(vector<vector<ll>> &input, pll king, ll w, ll h)
{
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    vector<vector<pll>> prev(h, vector<pll>(w, {-1, -1}));
    queue<pll> Q;

    Q.push(king);
    dist[king.first][king.second] = 0;

    while (!Q.empty())
    {
        pll c = Q.front();
        Q.pop();

        rep(i, 8)
        {
            ll nx = c.first + dx[i];
            ll ny = c.second + dy[i];

            if (valid(nx, ny, w, h) && input[nx][ny] != 1 && dist[nx][ny] > dist[c.first][c.second] + 1)
            {
                dist[nx][ny] = dist[c.first][c.second] + 1;
                prev[nx][ny] = c;
                Q.push({nx, ny});
            }
        }
    }

    int minDist = INF;
    pll knight;
    rep(i, h)
    {
        rep(j, w)
        {
            if (input[i][j] == 2 && dist[i][j] < minDist)
            {
                minDist = dist[i][j];
                knight = {i, j};
            }
        }
    }

    if (minDist == INF)
    {
        cout << "Resign" << endl;
    }
    else
    {
        cout << "Checkmate in " << minDist << endl;
        vector<pll> path;
        for (pll c = knight; c != king; c = prev[c.first][c.second])
        {
            path.push_back(c);
        }
        path.push_back(king);
        ll n = path.size();
        for (size_t i = 0; i < n - 1; i++)
        {
            cout << h - path[i].first << " " << path[i].second + 1 << " " << h - path[i + 1].first << " " << path[i + 1].second + 1 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll w, h;
    cin >> w >> h;

    vector<vector<ll>> input(h, vector<ll>(w));
    pair<ll, ll> king;
    rep(i, h)
    {
        rep(j, w)
        {
            char x;
            cin >> x;
            if (x == 'k')
            {
                input[i][j] = 1;
                king = {i, j};
            }
            else if (x == 'N')
            {
                input[i][j] = 2;
            }
            else if (islower(x) || x == '.')
            {
                input[i][j] = 0;
            }
            else
            {
                input[i][j] = 1;
            }
        }
    }
    boxing(input, king, w, h);
    return 0;
}
