
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

    cout << "insert 1";
    cout << "insert 2";
    cout << "insert 1";
    cout << "insert 2";
    cout.flush();
    cout << "remove";
    int x;
    cin >> x;
    string y;
    if (x == 1)
    {
        cin >> x;
        if (x == -1)
            return 0;
        if (x == 2)
        {
            cout << "empty";
            cout.flush();
            cin >> y;
            if (y == "-1")
                return 0;
            if (y == "yes")
            {
                cout << "! set";
                return 0;
            }
            else
            {
                cout << "! queue";
                return 0;
            }
        }
        else
        {
            cout << "! pq";
            return 0;
        }
    }
    else
    {
        cout << "! stack";
        return 0;
    }

    // content

    return 0;
}
