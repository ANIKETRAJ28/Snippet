#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

vector<list<pp>>graph;

void add_list(int src, int dst, int wts) {
    graph[src].push_back({dst, wts});
    graph[dst].push_back({src, wts});
}

ll prims(int src, int n) {
    // minheap
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> visited;
    vector<int> wts(n, INT_MAX), parent(n);
    for(int i = 0 ; i < n ; i++) parent[i] = i;
    wts[src] = 0;
    pq.push({0, src});
    ll res = 0;
    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int par = node.second;
        int wt = node.first;
        if(visited.count(par)) continue;
        res += wt;
        visited.insert(par);
        for(auto neig : graph[par]) {
            if(!visited.count(neig.first) and wts[neig.first] > neig.second) {
                wts[neig.first] = neig.second;
                parent[neig.first] = par;
                pq.push({neig.second, neig.first});
            }
        }
    }
    return res;
}


int main() {
    int n, m;
    cin>>n>>m;
    graph.resize(n+1, list<pp> ());
    while(m--) {
        int src, dst, wts;
        cin>>src>>dst>>wts;
        add_list(src, dst, wts);
    }
    int src;
    cin>>src;
    cout<<prims(src, n);
    return 0;
}