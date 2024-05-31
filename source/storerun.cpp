#include <bits/stdc++.h>
using namespace std;

const int MAXN = 103;
const int MAXK = 10;
const int INF = 1e9;

vector<int> graph[MAXN];
int dist[MAXN][1 << MAXK];
int store[MAXN][1 << MAXK];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    map<string, int> grocery_to_id;
    for (int i = 0; i < k; i++)
    {
        string grocery;
        cin >> grocery;
        grocery_to_id[grocery] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            string grocery;
            int t;
            cin >> grocery >> t;
            if (grocery_to_id.count(grocery))
            {
                store[i][t] |= 1 << grocery_to_id[grocery];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << k); mask++)
        {
            dist[i][mask] = INF;
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, store[0][0]}});
    dist[0][store[0][0]] = 0;

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int u = pq.top().second.first;
        int mask = pq.top().second.second;
        pq.pop();

        if (d != dist[u][mask])
            continue;

        for (int v : graph[u])
        {
            int new_mask = mask | store[v][d + 1];
            if (dist[v][new_mask] > d + 1)
            {
                dist[v][new_mask] = d + 1;
                pq.push({-dist[v][new_mask], {v, new_mask}});
            }
        }
    }

    int min_tram_rides = INF;
    for (int mask = 0; mask < (1 << k); mask++)
    {
        min_tram_rides = min(min_tram_rides, dist[0][mask]);
    }

    if (min_tram_rides == INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << min_tram_rides << "\n";
    }

    return 0;
}