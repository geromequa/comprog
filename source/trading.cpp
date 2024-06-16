#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> ws;
    vector<double> dist(n, numeric_limits<double>::infinity());
    vector<int> pre(n, -1);
    vector<string> identifiers(n);
    string rates;
    getline(cin, rates);
    stringstream ss(rates);
    for (auto &s : identifiers)
        getline(ss, s, ' ');
    Matrix<double> M(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double a;
            cin >> a;
            M[i][j] = -1.0 * a;
        }
    }
    dist[0] = 0.0;
    for (int k = 1; k <= n - 1; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (dist[u] + M[u][v] < dist[v])
                {
                    dist[v] = dist[u] + M[u][v];
                    pre[v] = u;
                }
            }
        }
    }
    // for (auto d : dist) cout << d << " ";
    // cout << endl;
    // for (auto d : pre) cout << d << " ";
    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (dist[u] + M[u][v] < dist[v])
            {
                cout << "money!\n";
                // cout << identifiers[u] << " " << identifiers[v] << endl;
                // pre[v] = u;
                vector<bool> visited(n, false);
                stack<string> out;
                visited[v] = true;
                while (!visited[u])
                {
                    visited[u] = true;
                    u = pre[u];
                }
                out.push(identifiers[u].append(" "));
                v = pre[u];
                int length = 0;
                while (v != u)
                {
                    length++;
                    out.push(identifiers[v].append(" "));
                    v = pre[v];
                }
                cout << ++length << "\n";
                while (!out.empty())
                {
                    cout << out.top();
                    out.pop();
                }
                return 0;
            }
        }
    }

    cout << "noglitch";

    return 0;
}