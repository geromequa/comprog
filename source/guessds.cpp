
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

    cout << "? insert 1" << endl;
    cout << "? insert 2" << endl;
    cout << "? insert 1" << endl;
    cout << "? insert 2" << endl;
    cout << "? remove" << endl;
    cout.flush();
    int x;
    cin >> x;
    string y;
    if (x == 1)
    {
        cout << "? remove" << endl;
        cout.flush();
        cin >> x;
        if (x == -1)
            return 0;
        if (x == 2)
        {
            cout << "? empty" << endl;
            cout.flush();
            cin >> y;
            if (y == "-1")
                return 0;
            if (y == "yes")
            {
                cout << "! set" << endl;
                return 0;
            }
            else
            {
                cout << "! queue" << endl;
                return 0;
            }
        }
        else
        {
            cout << "! pq" << endl;
            return 0;
        }
    }
    else
    {
        cout << "! stack" << endl;
        return 0;
    }

    // content

    return 0;
}
