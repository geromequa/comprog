
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll useOperator(int operatorID, ll a, ll b)
{
    switch (operatorID)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    }
}

string parseNumbers(vector<ll> numbers)
{
    sort(all(numbers));
    while (next_permutation(all(numbers)))
    {
        rep(i, 3)
        {
            rep(j, 3)
            {
                rep(k, 3)
                {
                    rep(l, 3)
                    {
                        if (useOperator(l, useOperator(k, useOperator(j, useOperator(i, numbers[0], numbers[1]), numbers[2]), numbers[3]), numbers[4]) == 23)
                            return "Possible";
                    }
                }
            }
        }
    }
    return "Impossible";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    vector<ll> numbers(5);
    rep(i, t)
    {
        for (auto &num : numbers)
        {
            cin >> num;
        }
        cout << parseNumbers(numbers) << endl;
    }

    return 0;
}
