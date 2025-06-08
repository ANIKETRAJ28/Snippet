#include <bits/stdc++.h>
using namespace std;

void buildTree(int arr[], int tree[], int i, int lo, int hi)
{
  // base case
  if (lo == hi)
  {
    tree[i] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  // left child
  buildTree(arr, tree, 2 * i + 1, lo, mid);
  // right tree
  buildTree(arr, tree, 2 * i + 2, mid + 1, hi);
  // curr maximum
  tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int getMax(int tree[], int &lRange, int &rRange, int i, int lo, int hi)
{
  // base case
  if (lRange > hi || rRange < lo)
    return INT_MIN;
  if (lo >= lRange && hi <= rRange)
    return tree[i];
  int mid = lo + (hi - lo) / 2;
  int leftMax = getMax(tree, lRange, rRange, 2 * i + 1, lo, mid);
  int rightMax = getMax(tree, lRange, rRange, 2 * i + 2, mid + 1, hi);
  return max(leftMax, rightMax);
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
  int segmentTree[4 * n];
  // build tree
  buildTree(arr, segmentTree, 0, 0, n - 1);
  int q;
  cin >> q;
  while (q--)
  {
    pair<int, int> query;
    cin >> query.first >> query.second;
    cout << getMax(segmentTree, query.first, query.second, 0, 0, n - 1) << "\n";
  }
  return 0;
}