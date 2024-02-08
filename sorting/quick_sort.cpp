#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int Sort(vec<int> &v, int strt, int end) {
    int k = strt;
    for(int i = strt + 1; i <= end; i++) {
        if(v[i] < v[strt]) k++;
    }
    swap(v[strt], v[k]);
    int lo = strt, hi = end;
    // arranged elements according to pivot
    while(lo < k && hi > k) {
        if(v[lo] <= v[k]) lo++;
        else if(v[hi] > v[k]) hi--;
        else {
            swap(v[lo], v[hi]);
            lo++;
            hi--;
        }
    }
    return k;
}

void quickSort(vec<int> &v, int strt, int end) {
    if(strt >= end) return;
    int mid = Sort(v, strt, end);
    quickSort(v, strt, mid-1);
    quickSort(v, mid+1, end);
}

int main(){
    vec<int> v = {5, 1, 3, 8, 6, 2, 4, 7};
    quickSort(v, 0, v.size()-1);
    for(auto el : v) cout<<el<<" ";
    return 0;
}