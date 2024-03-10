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

vec<unordered_set<int>> graph;
int v;

// direc -> true -> bidirectional graph
// direc -> false -> directional graph
void add_list(int src, int dst, bool direc) {
    graph[src].insert(dst);
    if(direc) graph[dst].insert(src);
}

void display() {
    for(int i = 0 ; i < v ; i++) {
        cout<<i<<" -> (";
        for(auto el : graph[i]) {
            cout<<el<<",";
        }
        cout<<")\n";
    }
}

int main() {
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, unordered_set<int>());
    while(e--) {
        int src, dst;
        cin>>src>>dst;
        add_list(src, dst, true);
    }
    display();
    return 0;
}

/**
 * example
*/
// 7
// 7
// 0 1
// 0 2
// 1 5
// 2 5
// 2 3
// 3 6
// 6 4