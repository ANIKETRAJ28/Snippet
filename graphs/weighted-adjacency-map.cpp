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

vec<unordered_map<int, int>> graph;
int v;

// direc -> true -> bidirectional graph
// direc -> false -> directional graph
void add_list(int src, int dst, int wgt, bool direc) {
    graph[src].insert({dst, wgt});
    if(direc) graph[dst].insert({src, wgt});
}

void display() {
    for(int i = 0 ; i < v ; i++) {
        cout<<i<<" -> (";
        for(auto el : graph[i]) {
            cout<<"{"<<el.first<<", "<<el.second<<"},";
        }
        cout<<")\n";
    }
}

int main() {
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, unordered_map<int, int>());
    while(e--) {
        int src, dst, wgt;
        cin>>src>>dst>>wgt;
        add_list(src, dst, wgt, true);
    }
    display();
    return 0;
}

/**
 * example
*/
// 7
// 7
// 0 1 1
// 0 2 2
// 1 5 3
// 2 5 2
// 2 3 6
// 3 6 2
// 6 4 9