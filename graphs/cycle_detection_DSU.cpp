#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

/**
 * TC = O(log*n) 
 * SC = O(n)
*/
int find(vec<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

/**
 * TC = O(log*n) 
 * SC = O(n)
*/
bool Union(vec<int> &parent, vec<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b)
        // same parent cycle detected
        return true;

    if(rank[a] >= rank[b]) {
        parent[b] = a;
        rank[a]++;
    } else {
        parent[a] = b;
        rank[b]++;
    }
    return false;
}

/**
 * Overall TC and SC
 * TC = O(log*n) 
 * SC = O(n)
*/


int main() {
    int n, m;
    cin>>n>>m;
    // n -> no. of elements
    // m -> no. of queries
    vector<int> rank(n+1, 0);
    vector<int> parent(n+1);
    for(int i = 0 ; i <= n ; i++) parent[i] = i;

    while(m--) {
        int x, y;
        cin>>x>>y;
        bool res = Union(parent, rank, x, y);
        if(res) {
            cout<<"Cycle detected\n";
            break;
        }
    }
    return 0;
}
/**
6
6
0 2
0 5
2 3
3 1
1 4
3 4
*/