#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;

struct Edge {
    int weight = std::numeric_limits<int>::max();
    int to = -1;
    bool operator<(Edge const& other) const {
        return std::make_pair(weight, to) < std::make_pair(other.weight, other.to);
    }
};

using Graph = vector<vector<Edge>>;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int nTests;
    cin >> nTests;

    rep(test,nTests) {
        int nCities, nStreets;
        cin >> nCities >> nStreets;

        int neededCities = ceil(0.75* (nCities-1))+1;
        int heighestWeight = 0;

        Graph graph(nCities);
        for (int i = 0; i < nStreets; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            graph[from].push_back({weight,to});
            graph[to].push_back({weight,from});
        }

        vector<Edge> min_e(nCities);
        min_e[0].weight = 0;
        set<Edge> q;
        q.insert({0,0});
        vector<bool> selected(nCities, false);

        for (int i = 0; i<neededCities;i++) {

            int v = q.begin()->to;
            selected[v] = true;
            heighestWeight = max(heighestWeight,q.begin()->weight);
            q.erase(q.begin());

            for (Edge e: graph[v]) {
                if (!selected[e.to] && e.weight < min_e[e.to].weight) {
                    q.erase({min_e[e.to].weight,e.to});
                    min_e[e.to] = {e.weight,v};
                    q.insert({e.weight,e.to});
                }
            }
        }

        cout << heighestWeight << endl;
    }
    return 0;
}