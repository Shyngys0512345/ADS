#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left=right=NULL;
    }
};

class BST {
private:
    Node* root;

    Node* push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    int height(Node* cur){
        if(cur==NULL){
            return 0;
        }
        return max(height(cur->left), height(cur->right))+1;
    }

    int max(int a, int b) { return (a > b) ? a : b; }

    int diameter(Node * cur){
        if (cur == NULL)
            return 0;
    
        // get the height of left and right sub-trees
        int lheight = height(cur -> left);
        int rheight = height(cur -> right);
    
        // get the diameter of left and right sub-trees
        int ldiameter = diameter(cur -> left);
        int rdiameter = diameter(cur -> right);
    
        // Return max of following three
        // 1) Diameter of left subtree
        // 2) Diameter of right subtree
        // 3) Height of left subtree + height of right subtree +
        // 1
        return max(lheight + rheight + 1, max(ldiameter, rdiameter));
    }

public:
    BST(){
        root=NULL;
    }
    void push(int x){
        root = push(root, x);
    }
    int diameter(){
        return diameter(root);
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        tree.push(x);
    }
    cout << tree.diameter();
    return 0;
}