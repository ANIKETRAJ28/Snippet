#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int maxi(vector<int> &arr) {
    int maxEle = INT_MIN;
    for(int i = 0 ; i < arr.size() ; i++) {
        maxEle = max(maxEle, arr[i]);
    }
    return maxEle;
}

vector<int> countingSort(vector<int> &originalArr, vector<int> &countArr) {
    int n = originalArr.size();
    vector<int> sortedArr(n);
    int i = n-1;
    while(i >= 0) {
        int ele = originalArr[i];
        int pos = countArr[ele];
        sortedArr[pos-1] = ele;
        countArr[ele]--;
        i--;
    }
    return sortedArr;
}

void display(vector<int> &arr) {
    for(auto el : arr) {
        cout<<el<<" ";
    }
    cout<<"\n";
}

int main() {
    vector<int> arr = {5, 3, 0, 0, 3, 5, 6, 1, 7, 3, 0, 8, 1, 9, 5, 4, 2, 1, 0, 9, 0};
    int n = maxi(arr);
    vector<int> countArr(n+1, 0);
    for(int i = 0 ; i < arr.size() ; i++) {
        countArr[arr[i]]++;
    }
    for(int i = 1 ; i <= n ; i++) {
        countArr[i] += countArr[i-1];
    }
    int val = arr.size();
    vector<int> sortedArr = countingSort(arr, countArr);
    display(sortedArr);
    return 0;
}