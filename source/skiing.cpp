#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'


struct Track {
    int to, length;
};

using namespace std;
using Graph = vector<vector<Track>>;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int numOfResorts;
    cin >> numOfResorts;

    rep(resort, numOfResorts){
        int nOfStations, nOfTracks;
        cin >> nOfStations >> nOfTracks;

        Graph graph(nOfStations);
        vector<int> count = vector(nOfStations,0);

        for (int i = 0; i < nOfTracks; i++) {
            int from, to, length;
            cin >> from >> to >> length;
            graph[from-1].push_back({to-1,length});
            count[to-1]++;
        }

        queue<int> q;
        for (int i = 0; i < nOfStations; i++) {
            if (count[i] == 0)
                q.push(i);
        }

        vector<ll> dist(nOfStations,0);
        vector<int> top;
        ll longestRoute = 0;
        while (!q.empty()) {
            top.push_back(q.front());

            for (auto &track: graph[q.front()]) {
                count[track.to]--;
                if (count[track.to] == 0)
                    q.push(track.to);
                dist[track.to] = max(dist[track.to],dist[q.front()]+track.length);
                longestRoute = max(dist[q.front()]+track.length,longestRoute);
            }
            q.pop();
        }
        cout << longestRoute << endl;

    }

    return 0;
}