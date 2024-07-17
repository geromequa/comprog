#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

struct point
{
    double x;
    double y;
    point operator-(const point& other) const
    {
        return point{x - other.x, y - other.y};
    };
    point operator+(const point& other) const
    {
        return point{x + other.x, y + other.y};
    }
    point operator*(const double scale)
    {
        return point{scale * x, scale * y};
    }
    bool operator==(const point& other) const
    {
        return x == other.x && y == other.y;
    }
    // dot product = cos(alpha)
    double operator*(const point& other) const{
        return x*other.x + y*other.y;
    }
};

struct circle : point
{
    double r;
};

double squared_len(const point& a)
{
    return a.x * a.x + a.y * a.y;
}

double len(const point& a)
{
    return sqrt(squared_len(a));
}

double squared_dist(const point& a, const point& b)
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
        point position, target, arrow_vector;
        int num_balloons;
        cin >> position.x >> position.y >> target.x >> target.y;
        cin >> num_balloons;
        arrow_vector = target - position;
        vector<circle> balloons(num_balloons);
        for (auto& b: balloons) cin >> b.x >> b.y >> b.r;
        int popped = 0;
        for (auto balloon : balloons)
        {   
            point center_to_start = position - balloon;
            // Mitternacht motherfucker
            double a = arrow_vector * arrow_vector;
            double b = 2 * (center_to_start * arrow_vector);
            double c = (center_to_start * center_to_start) - balloon.r * balloon.r;
            double discriminant = b*b - 4*a*c;
            //cout << discriminant<<endl;
            if (discriminant < 0) continue;
            discriminant = sqrt(discriminant);
            double t1 = (-b - discriminant) / (2 * a);
            double t2 = (-b + discriminant) / (2 * a);
            // // too short
            // if (t1 > 1 && t2 > 1) continue;
            // // completely inside
            // if (t1 < 0 && t2 > 1) continue;
            // starts too late
            if (t1 < 0 && t2 < 0) continue;
            popped++;
        }
        cout << popped << "\n";
    }
}