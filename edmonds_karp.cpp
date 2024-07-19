//
// Created by Jeanne Aue on 14.06.24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

#define REP(i, start, end) for(long long i = start; i < (end); i++)
#define append push_back

using namespace std;
using ll = long long;
typedef vector<int> vi;

struct edge {
    ll from, to;
    ll flow, cap;
    edge* reverse;
};

//I do not want to write comments... my future self will hate me
bool bfs(vector<vector<edge *>>& graph, int s, int t, vector<edge *> &parent) {
    fill(parent.begin(), parent.end(), nullptr);
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : graph[u]) {
            if (!parent[e->to] && e->to != s && e->cap > e->flow) {
                parent[e->to] = e;
                q.push(e->to);
                if (e->to == t) return true;
            }
        }
    }
    return false;
}

ll fordFulkerson(vector<vector<edge *>>& graph, int s, int t) {
    ll max_flow = 0;
    vector<edge *> parent(graph.size());

    while (bfs(graph, s, t, parent)) {
        // Find the maximum flow through the path found by BFS (two times find.... work on your language skills)
        ll path_flow = LLONG_MAX;

        for (edge *e = parent[t]; e != nullptr; e = parent[e->from]) {
            path_flow = min(path_flow, e->cap - e->flow);
        }

        // Update the capacities of the edges and reverse edges along the path
        for (edge *e = parent[t]; e != nullptr; e = parent[e->from]) {
            e->flow += path_flow;
            e->reverse->flow -= path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}
void add_edge_to_flow(vector<vector<edge *>>& graph, ll start, ll end, ll cap){
    auto *forward = new edge{start, end, 0, cap, nullptr};

    //works for undirected graphs, if direction is needed: start flow at 0
    auto *reverse = new edge{end, start, 0, cap, forward};
    forward->reverse = reverse;

    graph[start].push_back(forward);
    graph[end].push_back(reverse);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the input
    ll n, m;
    cin >> n >> m;
    vector<vector<edge *>> graph(n);

    REP(i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        add_edge_to_flow(graph, a,b,c);
    }

    // The source is always 0 and the sink is always 1
    ll max_flow = fordFulkerson(graph, 0, 1);
    cout << max_flow << endl;

    return 0;
}
