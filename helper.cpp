#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define REP(i, start, end) for (int i = start; i < (end); i++)
#define ITER(e, vec) for (auto &e : vec)

#define endl '\n'

#define F first
#define S second
#define append push_back
#define INFTY numeric_limits<int>::infinity()

#define ll long long
#define vi vector<int>
#define Graph vector<vector<int>>

using namespace std;

int main()
{
    int n;
    vector<int> vec(n, 0);
    vector<pair<int, int>> res;
    priority_queue<tuple<int, int, int>> pq;

    // more concise for-loops
    for (auto &e : vec)
        cin >> e;
    for (auto [a, b] : res)
        cout << a << ' ' << b << endl;

    // for outputting enough digits: cout << setprecision(15);

    // sort vector in descending order
    sort(all(vec), greater<>());

    /** Accessing tuples
     *  int a = get<0>(pq.top());
     *  int b = get<1>(pq.top());
     *  int c = get<2>(pq.top());
     */
    auto [a, b, c] = pq.top();

    // Usage Lambda Function
    /** struct compare {
            bool operator()(int a, int b) {
                // content, e.g.:
                return a < b;
            }
        };
        sort(all(vec), compare{});
     */
    sort(all(vec), [](int a, int b)
         {
        // content, e.g.:
        return a < b; });

    return 0;
}

// floor: int res = a/b
int int_division_ceil(int a, int b)
{
    return (a + b - 1) / b;
}

// equivalent to a/b < c/d
bool compare_fractions(int a, int b, int c, int d)
{
    return a * d < c * b;
}

bool is_even(int num)
{
    return num % 2 == 0;
}

// modular arithmetics (auch mit - und *)
int modular_arithmetics(int a, int b, int mod)
{
    return (a % mod + b % mod) % mod;
}

//-------Printing-functions-------
template <typename T, size_t N>
void printArrayWithFixedLength(const T (&array)[N])
{
    for (size_t i = 0; i < N; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printArrayDynamicallyAllocated(const T *array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printVector(const std::vector<T> &vec)
{
    for (const T &element : vec)
    {
        cout << element << " ";
    }
    cout << std::endl;
}
template <typename Container>
void printSets(const Container &c)
{
    for (const auto &element : c)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
template <typename Container>
void printMaps(const Container &c)
{
    for (const auto &pair : c)
    {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;
}

template <typename T>
void printQueue(std::queue<T> q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void printPriorityQueue(std::priority_queue<T> pq)
{
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
}

int printing()
{
    // Testing array with fixed length
    int fixedArray[] = {1, 2, 3, 4, 5};
    cout << "Fixed-length Array: ";
    printArrayWithFixedLength(fixedArray);

    // Testing dynamically allocated array
    int *dynamicArray = new int[5]{1, 2, 3, 4, 5};
    cout << "Dynamically Allocated Array: ";
    printArrayDynamicallyAllocated(dynamicArray, 5);
    delete[] dynamicArray;

    // Testing vector
    vector<int> intVector = {1, 2, 3, 4, 5};
    cout << "Vector: ";
    printVector(intVector);

    // Testing set
    set<int> intSet = {1, 2, 3, 4, 5};
    cout << "Set: ";
    printSets(intSet);

    // Testing multiset
    multiset<int> intMultiset = {1, 2, 2, 3, 3, 3, 4, 5};
    cout << "Multiset: ";
    printSets(intMultiset);

    // Testing map
    map<int, string> intStringMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    cout << "Map: ";
    printMaps(intStringMap);

    // Testing multimap
    multimap<int, string> intStringMultimap = {{1, "one"}, {2, "two"}, {2, "two again"}, {3, "three"}};
    cout << "Multimap: ";
    printMaps(intStringMultimap);

    // Testing queue
    queue<int> intQueue;
    for (int i = 1; i <= 5; ++i)
    {
        intQueue.push(i);
    }
    cout << "Queue: ";
    printQueue(intQueue);

    // Testing priority queue
    priority_queue<int> intPQueue;
    for (int i = 1; i <= 5; ++i)
    {
        intPQueue.push(i);
    }
    cout << "Priority Queue: ";
    printPriorityQueue(intPQueue);

    return 0;
}