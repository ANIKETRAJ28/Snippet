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
 * v -> vertices, e -> edges
 * TC = O(v+e)
 * SC = O(v+e)
*/

vec<list<int>> graph;
int v;

// direc -> true -> bidirectional graph
// direc -> false -> directional graph
void add_list(int src, int dst, bool direc) {
    graph[src].push_back(dst);
    if(direc) graph[dst].push_back(src);
}

unordered_set<int> visited;

bool dfs(int src, int prnt) {
    visited.insert(src);
    for(auto neig : graph[src]) {
        if(visited.count(neig) and neig != prnt) return true;
        if(!visited.count(neig)) {
            bool res = dfs(neig, src);
            if(res) return true;
        }
    }
    return false;
}

int main() {
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    while(e--) {
        int src, dst;
        cin>>src>>dst;
        add_list(src, dst, true);
    }
    cout<<dfs(0, -1);
    return 0;
}

/**
 * example
*/
// 5
// 5
//  1
// 1 2
// 0 2
// 2 3
// 3 4