
#include <bits/stdc++.h>
#include <vector>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int uniqueSubArr(int n, vector<int> a)
{
    unordered_map<int, int> indices;
    int result = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(indices[a[i]], j);
        result = max(result, i - j + 1);
        indices[a[i]] = i + 1;
    }
    return result;
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
        int n;
        cin >> n;
        vector<int> current = vector<int>(n);
        rep(j, n)
        {
            int y;
            cin >> y;
            current[j] = y;
        }
        cout << uniqueSubArr(n, current) << endl;
    }
}
