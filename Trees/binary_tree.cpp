#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Node {
    public: 
    int val;
    Node *left, *right;
    
    Node(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Tree {
    public: 
    int idx = -1;

    // tree construction
    Node* buildTree(vec<int> &arr) {
        idx++;
        // base case
        if(idx >= arr.size() or arr[idx] == -1) return NULL;
        Node* root = new Node(arr[idx]);
        // reccursively creating nodes
        root->left = buildTree(arr);
        root->right = buildTree(arr);

        return root;
    }

    // height of the tree
    int height(Node* root) {
        // base case
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // size of tree
    int size(Node* root) {
        if(!root) return 0;
        return 1 + size(root->left) + size(root->right);
    }

    // preorder traversal
    void preOrder(Node* root) {
        // base case
        if(!root) return;
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // inorder traversal
    void inOrder(Node* root) {
        // base case
        if(!root) return;
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }

    // postorder traversal
    void postOrder(Node* root) {
        // base case
        if(!root) return;
        postOrder(root->left);
        cout<<root->val<<" ";
        postOrder(root->right);
    }

    // bfs levelOrder traversal
    void levelOrder(Node* root) {
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()) {
            Node* dummy = qu.front();
            qu.pop();
            cout<<dummy->val<<" ";
            if(dummy->left) qu.push(dummy->left);
            if(dummy->right) qu.push(dummy->right);
        }
    }
};

int main(){
    vec<int> arr = {1,2,4,-1,-1,5,-1,-1,3,6,-1,7,-1,-1};
    Tree tree;
    Node* n = tree.buildTree(arr);
    tree.preOrder(n);
    cout<<"\n";
    tree.inOrder(n);
    cout<<"\n";
    tree.postOrder(n);
    cout<<"\n";
    tree.levelOrder(n);
    cout<<"\n"<<tree.height(n);
    cout<<"\n"<<tree.size(n);
    return 0;
}
/**        1
 *       /   \
 *      2     3
 *     / \   / \
 *    4   5 6   7
 */