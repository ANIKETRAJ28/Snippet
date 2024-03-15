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
void Union(vec<int> &parent, vec<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(rank[a] >= rank[b]) {
        parent[b] = a;
        rank[a]++;
    } else {
        parent[a] = b;
        rank[b]++;
    }
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
        string str;
        cin>>str;
        if(str == "union") {
            int x, y;
            cin>>x>>y;
            Union(parent, rank, x, y);
        } else {
            int x;
            cin>>x;
            cout<<find(parent, x)<<"\n";
        }
    }
    return 0;
}
/**
5 8
union
1 2
union
3 4
union
2 4
find

find
2
find
4
find
5
find
3
*/