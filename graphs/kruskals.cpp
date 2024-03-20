#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

struct Edges {
    int src, dst, wts;
};

bool cmp(Edges &e1, Edges &e2) {
    return e1.wts < e2.wts;
}

int find(vector<int> &par, int n) {
    return par[n] = (par[n] == n) ? n : find(par, par[n]);
}

void Union(vector<int> &par, vector<int> &rank, int a, int b) {
    a = find(par, a);
    b = find(par, b);
    
    // both lie in same component
    if(a == b) return;

    if(rank[a] >= rank[b]) {
        rank[a]++;
        par[b] = a;
    } else {
        rank[b]++;
        par[a] = b;
    }
}

int kruskals(vector<Edges> &graph, int v, int e) {
    int i = 0, ans = 0;
    sort(graph.begin(), graph.end(), cmp);
    vector<int> par(v+1), rank(v+1, 1);
    for(int i = 0 ; i <= v ; i++) par[i] = i;
    // max edges wil be v-1 taking 1 based index
    int edge = 0;
    for(int i = 0 ; i < graph.size() ; i++) {
        Edges e = graph[i];
        int src = e.src;
        int dst = e.dst;
        int wts = e.wts;
        src = find(par, src);
        dst = find(par, dst);
        if(src != dst) {
            // least weight edge found
            Union(par, rank, src, dst);
            ans += wts;
        }
    }
    return ans;
}

int main() {
    // v -> size of the input e -> not of edges
    int v, e;
    cin>>v>>e;
    vector<Edges> graph(e);
    for(int i = 0 ; i < e ; i++) {
        cin>>graph[i].src>>graph[i].dst>>graph[i].wts;
    }
    cout<<kruskals(graph, v, e)<<"\n";
    return 0;
}