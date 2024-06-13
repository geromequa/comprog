#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int getParent(int a, vector<int>& parent) {
    int parentElement = parent[a];
    while(parentElement != parent[parentElement]) {
        parentElement = parent[parentElement];
    }
    return parentElement;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int numofint, numofcmd;
    cin >> numofint >> numofcmd;

    vector<int> parent(numofint*2);
    vector<ll> sum(numofint*2);
    vector<int> count(numofint*2,1);

    for (int i = 0; i < numofint; i++) {
        parent[i] = i+numofint;
        parent[i+numofint] = i+numofint;
        sum[i+numofint] = i+1;
    }

    rep(i,numofcmd) {
        int cmd;
        cin >> cmd;

        switch (cmd) {
            int a,b, parentA, parentB;
            case 1: //union a,b

            cin >> a >> b;
            a--;b--;
            parentA = getParent(a,parent);
            parentB = getParent(b,parent);
            if (parentA == parentB) {
                break;
            }

            if (count[parentA] > count[parentB]) {
                swap(parentA,parentB);
            }

            parent[parentA] = parentB;
            count[parentB] += count[parentA];
            sum[parentB] += sum[parentA];

            break;


            case 2: // move a to set from b

            cin >> a >> b;
            a--;b--;

            parentA = getParent(a,parent);
            parentB = getParent(b,parent);
            if(parentA == parentB) {
                break;
            }

            parent[a] = parentB;

            count[parentA]--;
            count[parentB]++;
            sum[parentA] -= a+1;
            sum[parentB] += a+1;
            break;

            case 3: // count and sum of set a
                cin >> a;
                a--;

                cout << count[getParent(a,parent)] << " " << sum[getParent(a,parent)] << endl;
        }
    }
    return 0;
}