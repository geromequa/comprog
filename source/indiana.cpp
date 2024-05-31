#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

Graph graph;
vector<int> permanent_visited;
vector<int> temporary_visited;
vector<int> order;
int loop = 0;

void dfs(int v)
{
    if (permanent_visited[v])
        return;
    if (temporary_visited[v])
    {
        loop = 1;
        return;
    }
    temporary_visited[v] = 1;
    for (auto &u : graph[v])
    {
        dfs(u);
    }
    temporary_visited[v] = 0;
    permanent_visited[v] = 1;
    order.push_back(v);
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
        int n, g;
        cin >> n >> g;

        graph = Graph(n);
        rep(j, g)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
        }

        permanent_visited = vector(n, 0);
        temporary_visited = vector(n, 0);
        loop = 0;
        order = vector(0, 0);

        rep(j, n)
        {
            dfs(j);
        }

        if (loop)
        {
            cout << "recheck hints" << endl;
            continue;
        }

        auto normalorder = order;

        permanent_visited = vector(n, 0);
        temporary_visited = vector(n, 0);
        loop = 0;
        order = vector(0, 0);

        for (auto &v : graph)
            reverse(all(v));

        for (int j = n - 1; j >= 0; j--)
        {
            dfs(j);
        }

        if (normalorder != order)
        {
            cout << "missing hints" << endl;
            continue;
        }

        for (auto i = n - 1; i >= 0; i--)
        {
            cout << order[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}