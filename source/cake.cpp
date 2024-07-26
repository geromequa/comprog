#include <bits/stdc++.h>
#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;

class SegmentTree
{
public:
    SegmentTree(const vector<ll> &data) : n(data.size())
    {
        tree.resize(2 * n);
        build(data);
    }

    void update(ll index, ll value)
    {
        index += n;
        tree[index] -= value;
        while (index > 1)
        {
            index /= 2;
            tree[index] = gcd(tree[2 * index], tree[2 * index + 1]);
        }
    }

    ll query(ll left, ll right)
    {
        left += n;
        right += n;
        ll result = 0;
        while (left <= right)
        {
            if (left % 2 == 1)
                result = gcd(result, tree[left++]);
            if (right % 2 == 0)
                result = gcd(result, tree[right--]);
            left /= 2;
            right /= 2;
        }
        return result;
    }

private:
    ll n;
    vector<ll> tree;

    void build(const vector<ll> &data)
    {
        for (ll i = 0; i < n; ++i)
        {
            tree[n + i] = data[i];
        }
        for (ll i = n - 1; i > 0; --i)
        {
            tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
        }
    }

    ll gcd(ll a, ll b)
    {
        while (b)
        {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    SegmentTree segTree(a);

    while (q--)
    {
        char type;
        cin >> type;
        if (type == '?')
        {
            ll l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << segTree.query(l, r) << endl;
        }
        else if (type == '!')
        {
            string name;
            ll i, x;
            cin >> name >> i >> x;
            --i;
            segTree.update(i, x);
        }
    }

    return 0;
}
