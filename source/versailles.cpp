#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <cmath>

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
    point operator+(const point& other) const
    {
        return point{x + other.x, y + other.y};
    }
    point operator*(const ll scale)
    {
        return point{scale * x, scale * y};
    }
    bool operator==(const point& other) const
    {
        return x == other.x && y == other.y;
    }
    // dot product = cos(alpha) unit
    ll operator*(const point& other) const{
        return x*other.x + y*other.y;
    }
    // cross product = sin(alpha) unit
    ll operator%(const point& other) const{
        return x*other.y - y*other.x;
    }
    bool operator<(const point& other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

ll squared_len(const point& a)
{
    return a.x * a.x + a.y * a.y;
}

double len(const point& a)
{
    return sqrt(squared_len(a));
}

ll squared_dist(const point& a, const point& b)
{
    return squared_len(a - b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while(cases--)
    {
        int num_points;
        cin >> num_points;
        vector<point> points;
        for (int i = 0; i < num_points; i++)
        {
            point p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }
        sort(points.begin(), points.end());
        int rings = 0;
        while (num_points > 2)
        {
            stack<point> L,U;
            set<point> CH;
            for (int i = 0; i < num_points; i++)
            {
                while(L.size() > 1)
                {
                    point p2 = L.top(); L.pop();
                    point p1 = L.top();
                    // cout << p1.x << " " << p1.y << ", " << p2.x << " " << p2.y << ", " <<points[i].x << " " << points[i].y << endl;
                    // cout << (p2 - p1) % (points[i] - p1) << endl;
                    if ((p2 - p1) % (points[i] - p1) <= 0)
                    {
                        L.push(p2);
                        break;
                    }
                }
                L.push(points[i]);
            }
            for (int i = num_points - 1; i >= 0; i--)
            {
                while(U.size() > 1)
                {
                    point p2 = U.top(); U.pop();
                    point p1 = U.top();
                    if ((p2 - p1) % (points[i] - p1) <= 0)
                    {
                        U.push(p2);
                        break;
                    }
                }
                U.push(points[i]);
            }
            for (; !L.empty(); L.pop()) {CH.insert(L.top());}
            for (; !U.empty(); U.pop()) {CH.insert(U.top());}
            // cout << "Points on CH: \n";
            // for (auto p : CH) cout << p.x << " " << p.y <<" , ";
            // cout <<endl<< "Points in points: \n";
            // for (auto p : points) cout << p.x <<" " <<p.y<<" , ";
            // cout << endl;
            vector<point> new_points;
            for (auto p : points) if(CH.find(p) == CH.end()) new_points.push_back(p);
            points = new_points;
            //cout << "rem points: " << points.size() << endl;
            num_points = points.size();
            rings++;
        }
        cout<< ((num_points == 0) ? rings : ++rings) << "\n";
    }
}