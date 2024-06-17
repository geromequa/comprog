#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

struct Edge
{
    int to, flow;
    Edge *rev;
};

using namespace std;
using Graph = vector<vector<Edge *>>;
using ll = long long;

int bfs(Graph &g, int &s, int &t, vector<Edge *> &parent)
{
    fill(all(parent), nullptr);
    parent[s] = new Edge{0, 0, nullptr};
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (Edge *next : g[cur])
        {
            if (!parent[next->to] && next->flow)
            {
                parent[next->to] = next; //???
                int new_flow = min(flow, next->flow);
                if (next->to == t)
                    return new_flow;
                q.push({next->to, new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(Graph g, int s, int t)
{
    ll flow = 0;
    vector<Edge *> prevEdge(g.size(), nullptr);
    int new_flow;

    while ((new_flow = bfs(g, s, t, prevEdge)))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            prevEdge[cur]->flow -= new_flow;
            prevEdge[cur]->rev->flow += new_flow;
            cur = prevEdge[cur]->rev->to;
        }
    }

    return flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        Edge *e = new Edge();
        Edge *r = new Edge();
        e->to = b;
        e->flow = c;
        e->rev = r;
        r->to = a;
        r->flow = c;
        r->rev = e;
        g[a].push_back(e);
        g[b].push_back(r);
    }

    ll flow = maxflow(g, 0, 1);
    cout << flow << endl;

    return 0;
}