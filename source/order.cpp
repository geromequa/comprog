#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int rangen;
    cin >> rangen;
    auto cmpbegin = [](const vector<int> &a, const vector<int> &b)
    { return a[0] > b[0]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmpbegin)> pqbegin(cmpbegin);

    auto cmpend = [](const vector<int> &a, const vector<int> &b)
    { return a[1] > b[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmpend)> pqend(cmpend);

    for (int rangeid = 1; rangeid <= rangen; rangeid++)
    {
        vector<int> range(3);
        cin >> range[0] >> range[1];
        range[2] = rangeid;
        pqbegin.push(range);
    }

    for (int id = 1; id <= rangen; id++)
    {
        while (!pqbegin.empty() && pqbegin.top()[0] <= id)
        {
            pqend.push(pqbegin.top());
            pqbegin.pop();
        }
        cout << pqend.top()[2] << endl;
        pqend.pop();
    }
    return 0;
}