#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define LLMAX       numeric_limits<ll>::max()

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using ull = unsigned long long;

//prims for numbers
vector<bool> sieveOfEratosthenes(int n, unordered_map<int,unordered_set<int>> &numbers) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; 2*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = 2*i; j <= n; j += i) {
                if (numbers.find(j) != numbers.end())
                    numbers[j].insert(i);
                is_prime[j] = false;
            }
        }
    }
    for (auto &n : numbers)
        if (is_prime[n.first])
            n.second.insert(n.first);

    return is_prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n;
    cin >> n;
    unordered_map<int,unordered_set<int>> medalValues;
    vector <int> medals(n);

    for (auto &m : medals) {
        cin >> m;
        medalValues[m] = {};
    }

    int maxMedal = medals[medals.size()-1];
    sieveOfEratosthenes(maxMedal, medalValues);

    unordered_map<int, int> primeOccurences;

    int overallMax = 1;
    for (auto &m : medals) {
        int maxCount = 0;
        for (auto &prime : medalValues[m]) {
            maxCount = max(maxCount, ++primeOccurences[prime]);
        }
        for (auto &prime : medalValues[m]) {
            primeOccurences[prime] = maxCount;
        }
        overallMax = max(overallMax, maxCount);
    }

    cout << overallMax << endl;

    return 0;
}