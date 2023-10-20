#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        right = left = NULL;
    }
};
int cnt = 0;
class BST{
private:
    Node* root;
    Node* pur;

    Node* push(Node* cur, int val){
        if(cur==NULL){
            return new Node(val);
        } 
        if(val<cur->val) cur->left = push(cur->left, val);
        if(val>cur->val) cur->right = push(cur->right, val);
        return cur;
    }
    Node * inOrder(Node* cur, int val){
        if(cur!=NULL){
            inOrder(cur->left, val);
            inOrder(cur->right, val);
            if(cur->val==val){
                pur=cur;
            }
        }
    }

    Node * print(Node* pur){
        if(pur!=NULL){
            cout << pur->val << " ";
            print(pur->left);
            print(pur->right);
        }
    }

public:
    BST(){
        root = NULL;
        pur = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void inOrder(int val){
        inOrder(root, val);
    }

    void print(){
        print(pur);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    for(int i=0; i<n; i++){
        tree.push(a[i]);
    }
    tree.inOrder(m);
    tree.print();
    // cout << cnt << endl;
}