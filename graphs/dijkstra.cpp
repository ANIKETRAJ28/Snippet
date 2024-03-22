#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

vector<list<pp>> graph;

void add_list(int src, int dst, int wts) {
    graph[src].push_back({dst, wts});
    graph[dst].push_back({src, wts});
}

vector<int> dijkstra(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> visited;
    vector<int> via(n+1), dis(n+1, INT_MAX);
    dis[src] = 0; 
    via[src] = src;
    pq.push({0, src});
    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int wts = node.first;
        int par = node.second;
        visited.insert(par);
        for(auto neig : graph[par]) {
            if(!visited.count(neig.first) and wts+neig.second < dis[neig.first]) {
                dis[neig.first] = wts+neig.second;
                via[neig.first] = par;
                pq.push({wts+neig.second, neig.first});
            }
        }
    }
    return dis;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        graph.resize(n+1, list<pp>());
        while(m--) {
            int src, dst, wts;
            cin>>src>>dst>>wts;
            add_list(src, dst, wts);
        }
        int src;
        cin>>src;
        vector<int> dis = dijkstra(src, n);
        for(int i = 1 ; i <= n ; i++) {
            cout<<dis[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}