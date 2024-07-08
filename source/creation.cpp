#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define LLMAX       numeric_limits<ll>::max()
#define ll          long long

using namespace std;
using Graph = vector<vector<int>>;
//using ll = long long;
using ull = unsigned long long;

//factorials up to n
void precomputeFactorials(vector<long long> & factorials, long long n, long long mod) {
    factorials[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorials[i] = factorials[i-1] * i % mod;
    }
}

//extended euclidean algorithm ax+by=gcd(a,b)
//gcd iterative
long long gcd(long long a, long long b, long long& x, long long& y) {
    x = 1, y = 0;
    long long x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        long long q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

//gcd recursive
long long gcd_recursive(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd_recursive(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//mod inverses of list of numbers
std::vector<long long> invs(const std::vector<long long> &a, long long m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<long long> b(n);
    long long v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = v * a[i] % m;
    }
    long long x, y;
    gcd(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = x * b[i] % m;
        x = x * a[i] % m;
    }
    return b;
}

//mod inverse of a number
long long inv(long long a, long long &mod) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a, mod) % mod;
}

// mod inverse up to n
//inverse.size() = n+1
void precomputeInverses(vector<long long> &inverses, long long n, long long mod) {
    inverses[0] = 0;
    inverses[1] = 1;
    for (int i = 2; i < n; i++) {
        inverses[i] = mod - (long long)(mod/i) * inverses[mod%i] % mod;
    }
}

// normal binominalcoeffizient
long long binomial_coefficient(int n, int k, vector<long long> &factorials, long long mod) {
    return factorials[n] * inv(factorials[k] * factorials[n - k] % mod, mod) % mod;
}

//precompute factorial inverses
long long binomial_coefficient(int n, int k, std::vector<long long> &factorials, vector<long long> &inverse_factorials, long long mod) {
    return factorials[n] * inverse_factorials[k] % mod * inverse_factorials[n - k] % mod;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    ll mod = 1e9+7;

    vector<long long> factorials (200000);
    precomputeFactorials(factorials, 200000, mod);

    rep(i,t){
        int l,h,n;
        cin >> l >> h >> n;

        ll walls = h-l;
        ll places = walls + n-2;

        cout << binomial_coefficient(places, walls, factorials, mod) << endl;
    }



    return 0;
}