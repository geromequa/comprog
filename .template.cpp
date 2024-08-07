#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;

struct point // for geometry
{
    ld x;
    ld y;
    point operator-(const point &other) const
    {
        return point{x - other.x, y - other.y};
    };
    point operator+(const point &other) const
    {
        return point{x + other.x, y + other.y};
    }
    point operator*(const ll scale)
    {
        return point{scale * x, scale * y};
    }
    bool operator==(const point &other) const
    {
        return x == other.x && y == other.y;
    }
    // dot product = cos(alpha) unit
    ll operator*(const point &other) const
    {
        return x * other.x + y * other.y;
    }
    // cross product = sin(alpha) unit
    ll operator%(const point &other) const
    {
        return x * other.y - y * other.x;
    }
    bool operator<(const point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};
struct circle : point
{
    ld r;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    return 0;
}
