#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val = val;
        right=left=NULL;
    }
};

class BST{
private:
    Node* root;

    Node* push(Node* cur, int x){
        if(cur==NULL){
            return new Node(x);
        }
        if(cur->val>x) cur->left = push(cur->left, x);
        if(cur->val<x) cur->right = push(cur->right, x);
        return cur;
    }

    int sumcur = 0;
    vector<int>v;
    void inOrder(Node* cur){
        if(cur!=NULL){
            inOrder(cur->right);
            sumcur+=cur->val;
            v.push_back(sumcur);
            inOrder(cur->left);
        }
    }

public:
    BST(){
        root = NULL;
    }

    void push(int x){
        root = push(root, x);
    }

    vector<int> inOrder(){
        inOrder(root);
        return v;
    }

};
int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    vector<int>vv = tree.inOrder();
    for(int i=0; i<vv.size(); i++){
        cout << vv[i] << " ";
    }
}