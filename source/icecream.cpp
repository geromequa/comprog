#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'


struct Track {
    int to, weight;
};

using namespace std;
using Graph = vector<vector<Track>>;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int nRooms, nConnections;
    cin >> nRooms >> nConnections;

    Graph graph(nRooms+1);

    for (int i = 1; i<=nRooms; i++) {
        int cost;
        cin >> cost;
        graph[0].push_back({i,cost});
        graph[i].push_back({0,cost});
    }

    for (int i = 0; i < nConnections; i++) {
        int from, ton, weight;
        cin >> from >> ton >> weight;
        graph[from+1].push_back({ton+1,weight});
        graph[ton+1].push_back({from+1,weight});
    }

    struct comparator{
        bool operator()(const Track a, const Track b) const { return a.weight>b.weight;}
    };

    priority_queue<Track, vector<Track>, comparator> q;
    vector<int> selectedRooms = vector(nRooms+1,0);
    ll totalCost = 0;
    for (auto track : graph[0]) {
        q.emplace(track);
    }
    selectedRooms[0] = 1;

    while (!q.empty()) {
        Track top = q.top();
        q.pop();
        if (selectedRooms[top.to]) {

            continue;
        }
        totalCost += top.weight;
        selectedRooms[top.to] = 1;
        for (auto track: graph[top.to]) {
            q.emplace(track);
        }
    }
    cout << totalCost << endl;
    return 0;
}