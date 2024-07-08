#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

// Function to find the largest prime factor
ll max_prime_factor(ll t)
{
    ll maxPrime = -1;
    while (t % 2 == 0)
    {
        maxPrime = 2;
        t >>= 1;
    }
    // n must be odd at this point
    while (t % 3 == 0)
    {
        maxPrime = 3;
        t = t / 3;
    }

    // now we have to iterate only for integers
    // who does not have prime factor 2 and 3
    for (int i = 5; i <= sqrt(t); i += 6)
    {
        while (t % i == 0)
        {
            maxPrime = i;
            t = t / i;
        }
        while (t % (i + 2) == 0)
        {
            maxPrime = i + 2;
            t = t / (i + 2);
        }
    }

    // This condition is to handle the case
    // when n is a prime number greater than 4
    if (t > 4)
        maxPrime = t;

    return maxPrime;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    cout << max_prime_factor(t) << endl;

    return 0;
}
