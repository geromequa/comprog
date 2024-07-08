#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;

bool compareX(const P &p1, const P &p2)
{
    return p1.first < p2.first;
}

bool compareY(const P &p1, const P &p2)
{
    return p1.second < p2.second;
}

double distance(const P &p1, const P &p2)
{
    return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

// All points in strip[] are sorted according to y coordinate. They all have an upper bound on minimum distance as d.
double stripClosest(vector<P> &strip, double d)
{
    double minDist = d;
    ll size = strip.size();

    for (ll i = 0; i < size; ++i)
    {
        for (ll j = i + 1; j < size && (strip[j].second - strip[i].second) < minDist; ++j)
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist)
            {
                minDist = dist;
            }
        }
    }

    return minDist;
}

// Points are sorted by x-coordinate.
double closestUtil(vector<P> &points, vector<P> &temp, ll left, ll right)
{
    if (right - left <= 3)
    {
        double minDist = numeric_limits<double>::infinity();
        for (ll i = left; i < right; ++i)
        {
            for (ll j = i + 1; j < right; ++j)
            {
                double dist = distance(points[i], points[j]);
                if (dist < minDist)
                {
                    minDist = dist;
                }
            }
        }
        return minDist;
    }

    ll mid = left + (right - left) / 2;
    P midPoint = points[mid];

    double dl = closestUtil(points, temp, left, mid);
    double dr = closestUtil(points, temp, mid, right);

    double d = min(dl, dr);

    temp.clear();
    for (ll i = left; i < right; ++i)
    {
        if (abs(points[i].first - midPoint.first) < d)
        {
            temp.push_back(points[i]);
        }
    }

    return min(d, stripClosest(temp, d));
}

double closest(vector<P> &points)
{
    ll n = points.size();
    vector<P> temp(n);
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, temp, 0, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    vector<P> points(n);
    for (auto &[x, y] : points)
    {
        cin >> x >> y;
    }
    cout << pow(closest(points), 2) << endl;

    return 0;
}
