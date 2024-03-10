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

bool dfsAnyPath(int src, int dst) {
    if(src == dst) return true;
    visited.insert(src);
    for(auto neig : graph[src]) {
        if(!visited.count(neig)) {
            bool result = dfsAnyPath(neig, dst);
            if(result) return true;
        }
    }
    return false;
}

void dfs(int src, int dst, vector<int> &paths) {
    if(src == dst) {
        paths.push_back(src);
        for(auto el : paths) {
            cout<<el<<", ";
        }
        cout<<"\n";
        paths.pop_back();
        return;
    }
    visited.insert(src);
    paths.push_back(src);
    for(auto neig : graph[src]) {
        if(!visited.count(neig)) {
            dfs(neig, dst, paths);
        }
    }
    paths.pop_back();
    visited.erase(src);
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
    int src, dst;
    cin>>src>>dst;
    // cout<<dfsAnyPath(src, dst)<<"\n";
    vector<int> paths;
    dfs(src, dst, paths);
    return 0;
}

/**
 * example
*/
// 7
// 8
// 0 1
// 0 2
// 1 3
// 2 3
// 1 4
// 4 5
// 5 6
// 3 5
// 0 6
