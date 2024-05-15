
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

string match(string p, string s)
{
    int m = p.size(), n = s.size();
    int p1 = 0;
    int p2 = m - 1;
    int s1 = 0;
    int s2 = n - 1;

    while (p[p1] != '*' && p[p1] != '+' && p1 < m && s1 < n)
    {
        if (p[p1] != s[s1])
        {
            return "NO";
        }
        p1++;
        s1++;
    }
    if (p[p1] == '*')
    {
        if (p1 == m - 1)
        {
            return "YES";
        }
        s1--;
    }
    if (p[p1] == '+')
    {
        if (p1 == m - 1)
        {
            if (s1 < n)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
    }
    while (p[p2] != '*' && p[p2] != '+' && p2 > p1 && s2 > s1)
    {
        if (p[p2] != s[s2])
        {
            return "NO";
        }
        p2--;
        s2--;
    }
    if (p[p2] == '*')
    {
        return "YES";
    }
    if (p[p2] == '+')
    {
        s2++;
        if (s2 - s1 > 0)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    if (m == n)
    {
        return "YES";
    }
    return "NO";
}
// string match(string p, string s)
//{
//     int m = p.size(), n = s.size();
//     int i = 0, j = 0;
//     vector<int> marked(s.size(), 0);
//     while (i < m && j < n && p[i] != '*' && p[i] != '+')
//     {
//         if (p[i] != s[j] || marked[j])
//         {
//             return "NO";
//         }
//         marked[j] = 1;
//         i++;
//         j++;
//     }
//
//     if (p[i] == '+')
//     {
//         if (i == m - 1)
//         {
//             if (j < n)
//             {
//                 return "YES";
//             }
//             else
//             {
//                 return "NO";
//             }
//         }
//     }
//
//     if (i == m - 1 && p[i] == '*')
//     {
//         return "YES";
//     }
//
//     i = m - 1;
//     int k = 0;
//     while (i >= 0 && k < n && p[i] != '*' && p[i] != '+')
//     {
//         if (p[i] != s[n - k - 1] || marked[n - k - 1])
//         {
//             return "NO";
//         }
//         marked[n - k - 1] = 1;
//         i--;
//         k++;
//     }
//
//     if (p[i] == '+')
//     {
//         if (n - k - j > 0)
//         {
//             return "YES";
//         }
//         else
//         {
//             return "NO";
//         }
//     }
//     if (n == m || p[i] == '*')
//     {
//         return "YES";
//     }
//
//     return "NO";
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    cin.ignore();
    rep(i, t)
    {
        string s, p;
        getline(cin, p);
        getline(cin, s);
        cout << match(p, s) << endl;
    }

    return 0;
}
