#include <bits/stdc++.h>
using namespace std;

void buildTree(int arr[], int tree[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    tree[i] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  buildTree(arr, tree, i * 2 + 1, lo, mid);
  buildTree(arr, tree, 2 * i + 2, mid + 1, hi);
  tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int getSum(int arr[], int tree[], int lazy[], int &lRange, int &rRange, int i, int lo, int hi)
{
  if (lazy[i] != 0)
  {
    int range = hi - lo + 1;
    tree[i] += range * lazy[i];
    if (lo != hi)
    {
      lazy[2 * i + 1] += lazy[i];
      lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if (lo > rRange || hi < lRange)
    return 0;
  if (lo >= lRange && hi <= rRange)
    return tree[i];
  int mid = lo + (hi - lo) / 2;
  int lSum = getSum(arr, tree, lazy, lRange, rRange, 2 * i + 1, lo, mid);
  int rSum = getSum(arr, tree, lazy, lRange, rRange, 2 * i + 2, mid + 1, hi);
  return tree[i] = lSum + rSum;
}

void updateSum(int arr[], int tree[], int lazy[], int &lRange, int &rRange, int &val, int i, int lo, int hi)
{
  if (lazy[i] != 0)
  {
    int range = hi - lo + 1;
    tree[i] += range * lazy[i];
    if (lo != hi)
    {
      lazy[2 * i + 1] += lazy[i];
      lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if (lo > rRange || hi < lRange)
    return;
  if (lo >= lRange && hi <= rRange)
  {
    int range = hi - lo + 1;
    tree[i] += range * val;
    if (lo != hi)
    {
      lazy[2 * i + 1] += val;
      lazy[2 * i + 2] += val;
    }
    return;
  }
  int mid = lo + (hi - lo) / 2;
  updateSum(arr, tree, lazy, lRange, rRange, val, 2 * i + 1, lo, mid);
  updateSum(arr, tree, lazy, lRange, rRange, val, 2 * i + 2, mid + 1, hi);
  tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int segmentTree[4 * n], lazyTree[4 * n];
  memset(lazyTree, 0, sizeof(lazyTree));
  // build tree
  buildTree(arr, segmentTree, 0, 0, n - 1);
  int q;
  cin >> q;
  while (q--)
  {
    string s;
    cin >> s;
    if (s == "getSum")
    {
      pair<int, int> query;
      cin >> query.first >> query.second;
      cout << getSum(arr, segmentTree, lazyTree, query.first, query.second, 0, 0, n - 1) << "\n";
    }
    else if (s == "updateSum")
    {
      vector<int> query(3);
      cin >> query[0] >> query[1] >> query[2];
      updateSum(arr, segmentTree, lazyTree, query[0], query[1], query[2], 0, 0, n - 1);
    }
  }
  return 0;
}