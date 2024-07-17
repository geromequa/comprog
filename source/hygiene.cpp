#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

struct point
{
    ll x;
    ll y;
    point operator-(const point& other) const
    {
        return point{x - other.x, y - other.y};
    };
    bool operator==(const point& other) const
    {
        return x == other.x && y == other.y;
    }
};

ll squared_len(const point& a)
{
    return a.x * a.x + a.y * a.y;
}

ll squared_dist(const point& a, const point& b)
{
    return squared_len(a - b);
}

ll squared_min_dist(vector<point>& x_sorted, vector<point>& y_sorted)
{
    if (x_sorted.size() <= 4)
    {
        ll min_dist = numeric_limits<ll>::max();
        for (int i = 0; i < x_sorted.size(); i++)
        {
            for (int j = i + 1; j < x_sorted.size(); j++)
            {
                min_dist = min(min_dist, squared_dist(x_sorted[i], x_sorted[j]));
            }
        }
        return min_dist;
    }
    vector<point> l,r, ly, ry;
    ll mid = x_sorted.size() / 2;
    for (int i = 0; i < mid; i++) l.push_back(x_sorted[i]);
    for (int i = mid; i < x_sorted.size(); i++) r.push_back(x_sorted[i]);
    for (auto p : y_sorted) {
        if (p.x <= l.back().x) ly.push_back(p);
        else ry.push_back(p);
    }
    ll min_dist = min(squared_min_dist(l, ly), squared_min_dist(r, ry));
    ll mid_x = x_sorted[mid].x;
    vector<point> strip;
    for (auto p : y_sorted)
    {
        if (mid_x - min_dist <= p.x && p.x <= mid_x + min_dist) {strip.push_back(p);}
    }
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < min(i + 16, (int)strip.size()); j++)
        {
            min_dist = min(min_dist, squared_dist(strip[i], strip[j]));
        }
    }
    return min_dist;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll num_points;
    cin >> num_points;
    vector<point> x_sorted, y_sorted;
    for (int i = 0; i < num_points; i++)
    {
        point p;
        cin >> p.x >> p.y;
        x_sorted.push_back(p);
        y_sorted.push_back(p);
    }
    sort(x_sorted.begin(), x_sorted.end(), [](const point &a, const point &b) {return a.x < b.x;});
    sort(y_sorted.begin(), y_sorted.end(), [](const point &a, const point &b) {return a.y < b.y;});
    cout << squared_min_dist(x_sorted, y_sorted);

    return 0;
}